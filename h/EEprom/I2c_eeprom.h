/*
 * I2c_eeprom.h
 *
 *  Created on: 2026/04/09
 *      Author: wujw
 *
 *  EEPROM: M24C04 (512 Bytes = 256 Words)
 *  I2C:    I2CA_SCL=GPIO33, I2CA_SDA=GPIO26
 *  Device address: 1010 E2 E1 P0 (E2=1, E1=1)
 *    Page0 (byte addr 0~255):   0x57
 *    Page1 (byte addr 256~511): 0x58
 */

#ifndef H_I2C_EEPROM_H_
#define H_I2C_EEPROM_H_


//=============================================================================
// I2C EEPROM Status
//=============================================================================
#define EEPROM_OK           0
#define EEPROM_TIMEOUT      1
#define EEPROM_BUS_BUSY     2


//=============================================================================
// M24C04 Slave Address (E2=1, E1=1)
//   Address format: 1010 E2 E1 P0
//   E2=1, E1=1 -> Page0: 1010 111 = 0x57
//                  Page1: 1011 000 = 0x58
//=============================================================================
#define M24C04_PAGE0_ADDR   0x57    // Page0: byte addr 0~255
#define M24C04_PAGE1_ADDR   0x58    // Page1: byte addr 256~511


//=============================================================================
// EEPROM Address Map (word address)
//   M24C04: 512 Bytes = 256 Words (1 Word = 2 Bytes, addr*2)
//
//   SI_Set:    word 0~28   (FUNC 0~28)
//   User_Set:  word 50~53  (FUNC 50~53)
//   EE_Set:    word 100~122 (FUNC 100~122)
//   INFO:      word 130~186
//=============================================================================
#define EEPROM_ADDR_SI_SET      0
#define EEPROM_ADDR_USER_SET    50
#define EEPROM_ADDR_EE_SET      100
#define EEPROM_ADDR_INFO0       130
#define EEPROM_ADDR_INFO1       138
#define EEPROM_ADDR_INFO2       146
#define EEPROM_ADDR_INFO3       154
#define EEPROM_ADDR_INFO4       162
#define EEPROM_ADDR_INFO5       170
#define EEPROM_ADDR_INFO6       178


//=============================================================================
// INFO Structure (16 bytes each, 7 blocks)
//=============================================================================
typedef struct
{
    unsigned char D0[16];   // Company
    unsigned char D1[16];   // Model
    unsigned char D2[16];   // Output Voltage Rate
    unsigned char D3[16];   // Revision
    unsigned char D4[16];   // Date
    unsigned char D5[16];   // Serial Number
    unsigned char D6[16];   // Country of MFG
}TY_INFO;

extern TY_INFO INFO;


//=============================================================================
// EEPROM Flag
//=============================================================================
typedef struct
{
    union
    {
        unsigned char ALL;
        struct
        {
            unsigned char  WrEepromEnable:1;
            unsigned char  ReEepromEnable:1;
            unsigned char  IniEEpromPass:1;
            unsigned char  WrEEpSet:1;
            unsigned char  EEpTest:1;
            unsigned char  :3;
        }bit;
    }Flag;

}TY_EEPROM_FLAG;

extern TY_EEPROM_FLAG EEPromFlag;


//=============================================================================
// Function Prototypes
//=============================================================================
extern void InitI2C(void);
extern void I2C_BusRecovery(void);
extern unsigned int WriteEEWorld(unsigned char EE_WriteAddr, unsigned int EE_WriteData);
extern unsigned int ReadEEWorld(unsigned char EE_ReadAddr);

extern void InitEEpromData(void);
extern void EE_Set_To_EEprom(void);
extern void EEprom_To_EE_Set(void);
extern void SI_Set_To_EEprom(void);
extern void EEprom_To_SI_Set(void);
extern void User_Set_To_EEprom(void);
extern void EEprom_To_User_Set(void);
extern void INFO_Write_To_EEprom(unsigned char *InfoMatrix, unsigned char StartAddr);
extern void EEprom_To_INFO(unsigned char *InfoMatrix, unsigned char StartAddr);


#endif /* H_I2C_EEPROM_H_ */
