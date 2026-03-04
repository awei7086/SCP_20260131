/*
 * SysConfig.c
 *
 *  Created on: 2025年10月10日
 *      Author: wujw
 */

#include "f28002x_device.h"
#include "device\device.h"
#include "h\SysConfig.h"
#include "h\ADC.h"
/*
#include "h\I2c_eeprom.h"
#include "h\Charger.h"
#include "h\Compensation.h"
#include "h\Protection.h"
#include "h\FanControl.h"



TY_SpecMax st_SpecMax;
TY_USER_Set st_USER_Set;
 extern TY_LCM_Pro_Set  LCM_Pro_Set;

unsigned int u16_SysConfigTemp = 0;
*/
void SysConfig(void)
{
    EALLOW;
    EPwm1Regs.TBPRD = INV_PWM_TBPRD;
    EPwm1Regs.TBCTR = 0;

    EPwm4Regs.TBPRD = PuRec_PWM_TBPRD;
    EPwm4Regs.TBCTR = 0;

    //以下需修改(for test)
    EPwm4Regs.CMPA.bit.CMPA = 50;
    EPwm4Regs.CMPB.bit.CMPB = PuRec_PWM_TBPRD-50;
    EPwm6Regs.CMPA.bit.CMPA = 50;
    EPwm6Regs.CMPB.bit.CMPB = PuRec_PWM_TBPRD-50;

    EDIS;





    Clr_ADC_Value();
    SCI_init();
    Init_Def_EE_Set();
/*
    Init_Def_USER_Set();
    Init_Def_LCM_Pro_Set();
    Init_FanControl();

  //EEprom reload in here !
    InitI2C();
    InitEEpromData();
  //EEprom reload in here !

    Load_Rate_To_Max();

    Init_Protection();

  //Force ADCC C15 operation and sample one time
    u16_SysConfigTemp = Force_ADC_Sample();
  //fellow ADCC C15 AD value select battery type
    Sel_BatType(u16_SysConfigTemp);

    Init_Compensation();

*/


}




void Init_Def_EE_Set(void)
{
    /*
    EE_Set.StartBat.u16_VRate =1200;    //ex. 1200 = 12.00V (only can setting 12.00/24.00/48.00)
    EE_Set.StartBat.u16_IRate =10000;   //ex. 10000= 100.00A

    EE_Set.BatBank.u16_VRate =1200;     //ex. 1200 = 12.00V(only can setting 12.00/24.00/48.00)
    EE_Set.BatBank.u16_IRate =10000;    //ex. 10000= 100.00A
    */

    EE_Set.AD_Gain.u16_AMP_A = 4096;
    EE_Set.AD_Gain.u16_AMP_B = 4096;
    EE_Set.AD_Gain.u16_AMP_C = 4096;
    EE_Set.AD_Gain.u16_VOL_A = 4096;
    EE_Set.AD_Gain.u16_VOL_B = 4096;
    EE_Set.AD_Gain.u16_VOL_C = 4096;
    EE_Set.AD_Gain.u16_VOL = 4096;
    EE_Set.AD_Gain.u16_ACIN = 4096;


    EE_Set.AD_Offset.u16_AMP_A = 2048;
    EE_Set.AD_Offset.u16_AMP_B = 2048;
    EE_Set.AD_Offset.u16_AMP_C = 2048;
    EE_Set.AD_Offset.u16_VOL_A = 2048;
    EE_Set.AD_Offset.u16_VOL_B = 2048;
    EE_Set.AD_Offset.u16_VOL_C = 2048;
    EE_Set.AD_Offset.u16_VOL = 2048;
    EE_Set.AD_Offset.u16_ACIN = 2048;

    //Bat_Def_Parameter_Sett();


}

void Init_Def_USER_Set(void)
{
    st_USER_Set.u16_ModbusID = 1; // Modbus ID 1
}

void Init_Def_LCM_Pro_Set(void)
{
    /*
    LCM_Pro_Set.BB.u16_OVP = 1650;
    LCM_Pro_Set.BB.u16_OVPR = 300;
    LCM_Pro_Set.BB.u16_OVPWarn = 100;
    LCM_Pro_Set.BB.u16_UVP = 1000;

    LCM_Pro_Set.BB.u16_UVPR = 250;
    LCM_Pro_Set.BB.u16_UVPWarn = 100;

    LCM_Pro_Set.SB.u16_OVP = 1650;
    LCM_Pro_Set.SB.u16_OVPR = 300;
    LCM_Pro_Set.SB.u16_OVPWarn = 100;
    LCM_Pro_Set.SB.u16_UVP = 1000;
    LCM_Pro_Set.SB.u16_UVPR = 250;
    LCM_Pro_Set.SB.u16_UVPWarn = 100;

    LCM_Pro_Set.u16_RetryTime = 3;
    */
}



void Load_Rate_To_Max(void)
{
    /*
    st_SpecMax.StartBat.u16_VRate = EE_Set.StartBat.u16_VRate * 1.5f;   //ex. 12V system = 18.00V
    st_SpecMax.StartBat.u16_IRate = EE_Set.StartBat.u16_IRate * 1.2f;   //ex. 100A system = 120.00A

    st_SpecMax.BatBank.u16_VRate = EE_Set.BatBank.u16_VRate * 1.5f;     //ex. 12V system = 18.00V
    st_SpecMax.BatBank.u16_IRate = EE_Set.BatBank.u16_IRate * 1.2f;     //ex. 100A system = 120.00A
*/
}

unsigned int Force_ADC_Sample(void)
{
/*
    DEVICE_DELAY_US(5000);              //delay 5msec確保ADC穩定
    EALLOW;
    AdccRegs.ADCSOCFRC1.bit.SOC0 = 1;   //觸發 SOC0 (LAYOUT NAME : DipSW)
    EDIS;

    DEVICE_DELAY_US(50);                //等待50usec(Sample Time >90ns)
 */
    return(AdccResultRegs.ADCRESULT0);

}



void InitI2C(void)
{
    I2C_disableModule(I2CA_BASE);
    //I2C_initMaster(I2CA_BASE, DEVICE_SYSCLK_FREQ, 100000, I2C_DUTYCYCLE_50);
    I2C_initMaster(I2CA_BASE, DEVICE_SYSCLK_FREQ, 400000, I2C_DUTYCYCLE_33); //I2C configuration. Use a 400kHz I2CCLK with a 33% duty cycle.
    I2C_setConfig(I2CA_BASE, I2C_MASTER_SEND_MODE);
    I2C_setBitCount(I2CA_BASE, I2C_BITCOUNT_8);
    I2C_setAddressMode(I2CA_BASE, I2C_ADDR_MODE_7BITS);
    I2C_setSlaveAddress(I2CA_BASE, 0x58);
    //I2C_setEmulationMode(I2CA_BASE, I2C_EMULATION_FREE_RUN);
    //I2C_enableInterrupt(I2CA_BASE, I2C_INT_STOP_CONDITION |I2C_INT_REG_ACCESS_RDY);
    I2C_clearInterruptStatus(I2CA_BASE, I2C_INT_RXFF | I2C_INT_TXFF);
    I2C_enableModule(I2CA_BASE);

    /////////////////////////////
    // GPIO for I2C             //
    //////////////////////////////
    GPIO_setPinConfig(GPIO_32_I2CA_SDA);
    GPIO_setPadConfig(32, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(32, GPIO_QUAL_ASYNC);
    GPIO_setDirectionMode(32, GPIO_DIR_MODE_OUT);


    GPIO_setPinConfig(GPIO_33_I2CA_SCL);
    GPIO_setPadConfig(33, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(33, GPIO_QUAL_ASYNC);
    GPIO_setDirectionMode(33, GPIO_DIR_MODE_OUT);
}


void SCI_init(void)
{
    EALLOW;
    SciaRegs.SCICCR.all = 0x0007;           // 1 stop bit,  No loopback
                                            // No parity, 8 char bits,
                                            // async mode, idle-line protocol
    SciaRegs.SCICTL1.all = 0x0003;          // enable TX, RX, internal SCICLK,
                                            // Disable RX ERR, SLEEP, TXWAKE
    SciaRegs.SCICTL2.all = 0x0003;
    SciaRegs.SCICTL2.bit.TXINTENA = 1;
    SciaRegs.SCICTL2.bit.RXBKINTENA = 1;

    //
    // SCIA at 9600 baud
    // @LSPCLK = 25 MHz (100 MHz SYSCLK) HBAUD = 0x01  and LBAUD = 0x44.
    //

    //9600
    SciaRegs.SCIHBAUD.all = 0x0001;
    SciaRegs.SCILBAUD.all = 0x0044;

    //19200
    #if Used_Debug
    SciaRegs.SCIHBAUD.all = 0x0000;
    SciaRegs.SCILBAUD.all = 0x00a2;
    #endif


    SciaRegs.SCICTL1.all = 0x0023;          // Relinquish SCI from Reset
    EDIS;


    GPIO_setPinConfig(GPIO_28_SCIA_RX);
    GPIO_setPinConfig(GPIO_29_SCIA_TX);
}
