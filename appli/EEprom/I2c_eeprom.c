/*
 * I2c_eeprom.c
 *
 *  Created on: 2026/04/09
 *      Author: wujw
 *
 *  EEPROM: M24C04 (512 Bytes = 256 Words)
 *  I2C:    I2CA_SCL=GPIO33, I2CA_SDA=GPIO26
 *  Device address: 1010 E2 E1 P0 (E2=1, E1=1)
 *    Page0: 0x57 (byte addr 0~255)
 *    Page1: 0x58 (byte addr 256~511)
 */

#include "f28002x_device.h"
#include "driverlib.h"
#include "device\device.h"
#include "h\EEprom\I2c_eeprom.h"
#include "h\EEprom\EE_Set.h"
#include "h\EEprom\SI_Set.h"
#include "h\EEprom\User_Set.h"


//=============================================================================
// Global Variables
//=============================================================================
TY_EEPROM_FLAG EEPromFlag;

                          //1234567890123456
TY_INFO INFO = {.D0 = "Cotek           ",  // Company
                .D1 = "SCP 12V 2000W   ",  // Model
                .D2 = "1200            ",  // Output Voltage Rate: 12.00V
                .D3 = "10001           ",  // Revision: 1000.1
                .D4 = "20260409        ",  // Date
                .D5 = "T0000000001     ",  // Serial Number
                .D6 = "Taiwan          "};  // Country of MFG


//=============================================================================
// I2C Timeout Constants (based on 100MHz SYSCLK)
//   400kHz I2C: 1 bit = 2.5us, 10 bits = 25us
//=============================================================================
#define I2C_TIMEOUT_20BIT   (2500*3)    // ~2 bytes transfer time
#define I2C_TIMEOUT_10BIT   (2500*2)    // ~1 byte transfer time


//=============================================================================
// InitI2C
//   Initialize I2C module manually (bypass SysConfig Board_init GMUX bug).
//   GPIO26 I2CA_SDA requires mux=11 (GMUX=10, MUX=11), which SysConfig
//   may set incorrectly. Use driverlib API after Board_init() to fix.
//
//   SYSCLK=100MHz, 400kHz I2C, 33% duty cycle
//=============================================================================
void InitI2C(void)
{
    // Ensure I2C peripheral clock is ON
    EALLOW;
    CpuSysRegs.PCLKCR9.bit.I2C_A = 1;
    EDIS;
    DEVICE_DELAY_US(10);

    // Disable I2C module for configuration
    I2C_disableModule(I2CA_BASE);

    // Init as master, 400kHz, 33% duty
    I2C_initMaster(I2CA_BASE, DEVICE_SYSCLK_FREQ, 400000, I2C_DUTYCYCLE_33);
    I2C_setConfig(I2CA_BASE, I2C_MASTER_SEND_MODE);
    I2C_setBitCount(I2CA_BASE, I2C_BITCOUNT_8);
    I2C_setAddressMode(I2CA_BASE, I2C_ADDR_MODE_7BITS);
    I2C_setSlaveAddress(I2CA_BASE, M24C04_PAGE0_ADDR);
    I2C_clearInterruptStatus(I2CA_BASE, I2C_INT_RXFF | I2C_INT_TXFF);

    // Enable I2C module
    I2C_enableModule(I2CA_BASE);

    // GPIO config (driverlib API, NO open-drain, same as AD500)
    GPIO_setPinConfig(GPIO_26_I2CA_SDA);
    GPIO_setPadConfig(26, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(26, GPIO_QUAL_ASYNC);
    GPIO_setDirectionMode(26, GPIO_DIR_MODE_OUT);

    GPIO_setPinConfig(GPIO_33_I2CA_SCL);
    GPIO_setPadConfig(33, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(33, GPIO_QUAL_ASYNC);
    GPIO_setDirectionMode(33, GPIO_DIR_MODE_OUT);

    DEVICE_DELAY_US(200);
}


//=============================================================================
// I2C_BusRecovery
//   When SDA is stuck low by a slave, toggle SCL 9 times to release it,
//   then generate a STOP condition. Re-init I2C module afterwards.
//   GPIO26=SDA (GPA bit 26), GPIO33=SCL (GPB bit 1)
//=============================================================================
void I2C_BusRecovery(void)
{
    unsigned int i;

    // Step1: Disable I2C module
    I2caRegs.I2CMDR.bit.IRS = 0;

    // Step2: Switch GPIO26(SDA) and GPIO33(SCL) to GPIO mode
    GPIO_setPinConfig(GPIO_26_GPIO26);
    GPIO_setDirectionMode(26, GPIO_DIR_MODE_IN);
    GPIO_setPadConfig(26, GPIO_PIN_TYPE_PULLUP);

    GPIO_setPinConfig(GPIO_33_GPIO33);
    GPIO_setDirectionMode(33, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(33, GPIO_PIN_TYPE_STD);
    GPIO_writePin(33, 1);   // SCL HIGH

    // Step3: Toggle SCL (GPIO33) 9 times to release stuck slave
    for(i = 0; i < 9; i++)
    {
        GPIO_writePin(33, 0);       // SCL LOW
        DEVICE_DELAY_US(5);
        GPIO_writePin(33, 1);       // SCL HIGH
        DEVICE_DELAY_US(5);

        // Check if SDA is released (GPIO26)
        if(GPIO_readPin(26) == 1) break;
    }

    // Step4: Generate STOP condition (SDA: LOW -> HIGH while SCL HIGH)
    GPIO_setDirectionMode(26, GPIO_DIR_MODE_OUT);
    GPIO_writePin(26, 0);           // SDA LOW
    DEVICE_DELAY_US(5);
    GPIO_writePin(33, 1);           // SCL HIGH
    DEVICE_DELAY_US(5);
    GPIO_writePin(26, 1);           // SDA HIGH (STOP)
    DEVICE_DELAY_US(5);

    // Step5: Restore GPIO to I2C function and re-enable
    GPIO_setPinConfig(GPIO_26_I2CA_SDA);
    GPIO_setPadConfig(26, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(26, GPIO_QUAL_ASYNC);
    GPIO_setDirectionMode(26, GPIO_DIR_MODE_OUT);

    GPIO_setPinConfig(GPIO_33_I2CA_SCL);
    GPIO_setPadConfig(33, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(33, GPIO_QUAL_ASYNC);
    GPIO_setDirectionMode(33, GPIO_DIR_MODE_OUT);

    I2C_enableModule(I2CA_BASE);

    DEVICE_DELAY_US(100);
}


//=============================================================================
// WriteEEWorld
//   Write 1 Word (16-bit) to EEPROM
//   EE_WriteAddr: word address (0~255), byte address = word addr * 2
//   EE_WriteData: 16-bit data (High byte first)
//   Return: EEPROM_OK / EEPROM_TIMEOUT / EEPROM_BUS_BUSY
//
//   I2CMDR must be written as whole word (.all) to avoid RMW issues
//   where residual STP/STT bits from previous transaction get re-written.
//   MDR bit map: STT=bit13, STP=bit11, MST=bit10, TRX=bit9, IRS=bit5
//=============================================================================
#define I2CMDR_TX_START  0x2620  // IRS + MST + TRX + STT
#define I2CMDR_RX_START  0x2420  // IRS + MST + STT (no TRX = receive)
#define I2CMDR_STOP      0x0C20  // IRS + MST + STP
#define I2CMDR_NACK      0x8420  // IRS + MST + NACKMOD

unsigned int WriteEEWorld(unsigned char EE_WriteAddr, unsigned int EE_WriteData)
{
    unsigned int ByteAddr;
    unsigned long TimeCNT;

    // Wait for bus free (with timeout)
    TimeCNT = 0;
    while(I2caRegs.I2CSTR.bit.BB != 0)
    {
        asm(" NOP");
        if(++TimeCNT >= I2C_TIMEOUT_20BIT * 10UL) return EEPROM_BUS_BUSY;
    }

    // Calculate byte address and select page
    ByteAddr = (unsigned int)EE_WriteAddr * 2;
    if(ByteAddr >= 256)
    {
        I2caRegs.I2CSAR.all = M24C04_PAGE1_ADDR;   // Page1
        ByteAddr -= 256;
    }
    else
    {
        I2caRegs.I2CSAR.all = M24C04_PAGE0_ADDR;   // Page0
    }

    // Clear NACK flag before transaction
    I2caRegs.I2CSTR.bit.NACK = 1;

    // Send: [byte address] [data high] [data low] = 3 bytes
    I2caRegs.I2CCNT = 3;
    I2caRegs.I2CDXR.all = ByteAddr;
    I2caRegs.I2CMDR.all = I2CMDR_TX_START;  // Master + Transmit + START

    // Wait: byte address sent
    TimeCNT = 0;
    while(I2caRegs.I2CSTR.bit.XRDY == 0)
    {
        asm(" NOP");
        if(++TimeCNT >= I2C_TIMEOUT_20BIT) return EEPROM_TIMEOUT;
    }

    // Check NACK after address phase
    if(I2caRegs.I2CSTR.bit.NACK == 1)
    {
        I2caRegs.I2CSTR.bit.NACK = 1;  // Clear NACK
        I2caRegs.I2CMDR.all = I2CMDR_STOP;
        return 3;  // NACK error
    }

    // Send high byte
    I2caRegs.I2CDXR.all = EE_WriteData >> 8;
    TimeCNT = 0;
    while(I2caRegs.I2CSTR.bit.XRDY == 0)
    {
        asm(" NOP");
        if(++TimeCNT >= I2C_TIMEOUT_10BIT) return EEPROM_TIMEOUT;
    }

    // Send low byte
    I2caRegs.I2CDXR.all = EE_WriteData & 0xFF;
    TimeCNT = 0;
    while(I2caRegs.I2CSTR.bit.ARDY == 0)
    {
        asm(" NOP");
        if(++TimeCNT >= I2C_TIMEOUT_10BIT) return EEPROM_TIMEOUT;
    }

    // Check NACK after data phase
    if(I2caRegs.I2CSTR.bit.NACK == 1)
    {
        I2caRegs.I2CSTR.bit.NACK = 1;
        I2caRegs.I2CMDR.all = I2CMDR_STOP;
        return 3;
    }

    // STOP condition
    I2caRegs.I2CMDR.all = I2CMDR_STOP;

    TimeCNT = 0;
    while(TimeCNT <= 130) { asm(" NOP"); TimeCNT++; }

    return EEPROM_OK;
}


//=============================================================================
// ReadEEWorld
//   Read 1 Word (16-bit) from EEPROM
//   EE_ReadAddr: word address (0~255), byte address = word addr * 2
//   Return: 16-bit data (High byte first)
//=============================================================================
unsigned int ReadEEWorld(unsigned char EE_ReadAddr)
{
    unsigned int ByteAddr;
    unsigned long TimeCNT;
    unsigned int EEDataBuf = 0;

    // Wait for bus free (with timeout)
    TimeCNT = 0;
    while(I2caRegs.I2CSTR.bit.BB != 0)
    {
        asm(" NOP");
        if(++TimeCNT >= I2C_TIMEOUT_20BIT * 10UL) return 0;
    }

    // Calculate byte address and select page
    ByteAddr = (unsigned int)EE_ReadAddr * 2;
    if(ByteAddr >= 256)
    {
        I2caRegs.I2CSAR.all = M24C04_PAGE1_ADDR;   // Page1
        ByteAddr -= 256;
    }
    else
    {
        I2caRegs.I2CSAR.all = M24C04_PAGE0_ADDR;   // Page0
    }

    //--- Phase 1: Write byte address (dummy write) ---
    I2caRegs.I2CCNT = 1;
    I2caRegs.I2CDXR.all = ByteAddr;
    I2caRegs.I2CMDR.all = I2CMDR_TX_START;  // Master + Transmit + START

    // Wait: byte address sent
    TimeCNT = 0;
    while(I2caRegs.I2CSTR.bit.XRDY == 0)
    {
        asm(" NOP");
        if(++TimeCNT >= I2C_TIMEOUT_20BIT) return 0;
    }

    //--- Phase 2: Repeated START + Read 2 bytes ---
    I2caRegs.I2CCNT = 2;
    I2caRegs.I2CMDR.all = I2CMDR_RX_START;  // Master + Receive + repeated START

    // Wait: receive high byte
    TimeCNT = 0;
    while(I2caRegs.I2CSTR.bit.RRDY == 0)
    {
        asm(" NOP");
        if(++TimeCNT >= I2C_TIMEOUT_20BIT) return 0;
    }
    EEDataBuf = I2caRegs.I2CDRR.all;

    // Set NACK before reading last byte (use .bit to preserve ongoing receive state)
    I2caRegs.I2CMDR.bit.NACKMOD = 1;

    // Wait: receive low byte
    TimeCNT = 0;
    while(I2caRegs.I2CSTR.bit.RRDY == 0)
    {
        asm(" NOP");
        if(++TimeCNT >= I2C_TIMEOUT_10BIT) return 0;
    }
    EEDataBuf = (EEDataBuf << 8) | I2caRegs.I2CDRR.all;

    // Wait: transfer complete
    TimeCNT = 0;
    while(I2caRegs.I2CSTR.bit.ARDY == 0)
    {
        asm(" NOP");
        if(++TimeCNT >= I2C_TIMEOUT_10BIT) break;
    }

    // STOP condition
    I2caRegs.I2CMDR.all = I2CMDR_STOP;

    TimeCNT = 0;
    while(TimeCNT <= 130) { asm(" NOP"); TimeCNT++; }

    return EEDataBuf;
}


//=============================================================================
// Struct <-> EEPROM helpers (pointer-based loop)
//=============================================================================
static void WriteStructToEEprom(unsigned int *ptr, unsigned int count, unsigned char baseAddr)
{
    unsigned int i;
    for(i = 0; i < count; i++)
    {
        WriteEEWorld(baseAddr + i, ptr[i]);
        DEVICE_DELAY_US(5000);  // M24C04 write cycle time = 5ms max
    }
}

static void ReadStructFromEEprom(unsigned int *ptr, unsigned int count, unsigned char baseAddr)
{
    unsigned int i;
    for(i = 0; i < count; i++)
    {
        ptr[i] = ReadEEWorld(baseAddr + i);
        DEVICE_DELAY_US(5000);
    }
}


//=============================================================================
// EE_Set <-> EEPROM  (FUNC 100~122, word addr 100~122)
//=============================================================================
void EE_Set_To_EEprom(void)
{
    WriteStructToEEprom((unsigned int *)&EE_Set,
                        sizeof(TY_st_EE_Set) / sizeof(unsigned int),
                        EEPROM_ADDR_EE_SET);
}

void EEprom_To_EE_Set(void)
{
    ReadStructFromEEprom((unsigned int *)&EE_Set,
                         sizeof(TY_st_EE_Set) / sizeof(unsigned int),
                         EEPROM_ADDR_EE_SET);
}


//=============================================================================
// SI_Set <-> EEPROM  (FUNC 0~28, word addr 0~28)
//=============================================================================
void SI_Set_To_EEprom(void)
{
    WriteStructToEEprom((unsigned int *)&SI_Set,
                        sizeof(TY_st_SI_Set) / sizeof(unsigned int),
                        EEPROM_ADDR_SI_SET);
}

void EEprom_To_SI_Set(void)
{
    ReadStructFromEEprom((unsigned int *)&SI_Set,
                         sizeof(TY_st_SI_Set) / sizeof(unsigned int),
                         EEPROM_ADDR_SI_SET);
}


//=============================================================================
// User_Set <-> EEPROM  (FUNC 50~53, word addr 50~53)
//=============================================================================
void User_Set_To_EEprom(void)
{
    WriteStructToEEprom((unsigned int *)&User_Set,
                        sizeof(TY_st_User_Set) / sizeof(unsigned int),
                        EEPROM_ADDR_USER_SET);
}

void EEprom_To_User_Set(void)
{
    ReadStructFromEEprom((unsigned int *)&User_Set,
                         sizeof(TY_st_User_Set) / sizeof(unsigned int),
                         EEPROM_ADDR_USER_SET);
}


//=============================================================================
// INFO <-> EEPROM  (16 bytes = 8 words per block)
//=============================================================================
void INFO_Write_To_EEprom(unsigned char *InfoMatrix, unsigned char StartAddr)
{
    unsigned int i;
    unsigned int data;

    for(i = 0; i < 8; i++)
    {
        data = ((unsigned int)InfoMatrix[i * 2] << 8) + InfoMatrix[i * 2 + 1];
        WriteEEWorld(StartAddr + i, data);
        DEVICE_DELAY_US(5000);
    }
}

void EEprom_To_INFO(unsigned char *InfoMatrix, unsigned char StartAddr)
{
    unsigned int i;
    unsigned int data;

    for(i = 0; i < 8; i++)
    {
        data = ReadEEWorld(StartAddr + i);
        InfoMatrix[i * 2]     = data >> 8;
        InfoMatrix[i * 2 + 1] = data & 0xFF;
        DEVICE_DELAY_US(5000);
    }
}


//=============================================================================
// InitEEpromData
//   Check EEPROM validity, if invalid -> write all defaults
//   Then load all settings from EEPROM
//=============================================================================
void InitEEpromData(void)
{
    unsigned int EEpTemp;

    // Read EE_Set.Spec.ACout to check if EEPROM has valid data
    EEpTemp = ReadEEWorld(EEPROM_ADDR_EE_SET);
    DEVICE_DELAY_US(5000);

    // ACout valid: 1000/1100/1150/1200/2000/2200/2300/2400
    // If out of range -> EEPROM is blank/corrupt
    if((EEpTemp < 1000) || (EEpTemp > 2400))
    {
        // Load defaults and write to EEPROM
        EE_Set_Back_Def();
        SI_Set_Back_Def();
        User_Set_Back_Def();

        EE_Set_To_EEprom();
        SI_Set_To_EEprom();
        User_Set_To_EEprom();

        INFO_Write_To_EEprom(&INFO.D0[0], EEPROM_ADDR_INFO0);
        INFO_Write_To_EEprom(&INFO.D1[0], EEPROM_ADDR_INFO1);
        INFO_Write_To_EEprom(&INFO.D2[0], EEPROM_ADDR_INFO2);
        INFO_Write_To_EEprom(&INFO.D3[0], EEPROM_ADDR_INFO3);
        INFO_Write_To_EEprom(&INFO.D4[0], EEPROM_ADDR_INFO4);
        INFO_Write_To_EEprom(&INFO.D5[0], EEPROM_ADDR_INFO5);
        INFO_Write_To_EEprom(&INFO.D6[0], EEPROM_ADDR_INFO6);

        EEPromFlag.Flag.bit.IniEEpromPass = 1;
    }
    // Reset I2C module to clear stuck BB state after bulk writes
    I2caRegs.I2CMDR.bit.IRS = 0;   // Disable module (clears BB and state machine)
    DEVICE_DELAY_US(10);
    I2caRegs.I2CMDR.bit.IRS = 1;   // Re-enable module
    DEVICE_DELAY_US(100);

    // Read all settings from EEPROM
    EEprom_To_EE_Set();
    EEprom_To_SI_Set();
    EEprom_To_User_Set();

    EEprom_To_INFO(&INFO.D0[0], EEPROM_ADDR_INFO0);
    EEprom_To_INFO(&INFO.D1[0], EEPROM_ADDR_INFO1);
    EEprom_To_INFO(&INFO.D2[0], EEPROM_ADDR_INFO2);
    EEprom_To_INFO(&INFO.D3[0], EEPROM_ADDR_INFO3);
    EEprom_To_INFO(&INFO.D4[0], EEPROM_ADDR_INFO4);
    EEprom_To_INFO(&INFO.D5[0], EEPROM_ADDR_INFO5);
    EEprom_To_INFO(&INFO.D6[0], EEPROM_ADDR_INFO6);
}
