/*
 * SysConfig.h
 *
 *  Created on: 2025¦~10¤ë10¤é
 *      Author: wujw
 */

#ifndef H_SYSCONFIG_H_
#define H_SYSCONFIG_H_

#define SYSCLK_FREQ    100000000UL
#define INV_PWM_FREQ   30000UL
#define INV_PWM_TBPRD  SYSCLK_FREQ/(INV_PWM_FREQ*2)   // up/down counter


#define Inv_PWM_Ts            1.0f/INV_PWM_FREQ


#define PuRec_PWM_FREQ   20000UL
#define PuRec_PWM_TBPRD  SYSCLK_FREQ/(PuRec_PWM_FREQ*2)   // up/down counter




//GPIO output pin define
#define ByPass_on   GpioDataRegs.GPBSET.bit.GPIO40 = 1
#define ByPass_off  GpioDataRegs.GPBCLEAR.bit.GPIO40 = 1

#define GndRLY_on    GpioDataRegs.GPASET.bit.GPIO14 = 1
#define GndRLY_off   GpioDataRegs.GPACLEAR.bit.GPIO14 = 1

#define AC_SoftRLY_on   GpioDataRegs.GPBSET.bit.GPIO45 = 1
#define AC_SoftRLY_off  GpioDataRegs.GPBCLEAR.bit.GPIO45 = 1

#define DC_SoftRLY_on   GpioDataRegs.GPASET.bit.GPIO15 = 1
#define DC_SoftRLY_off  GpioDataRegs.GPACLEAR.bit.GPIO15 = 1

#define LED_STG_on    GpioDataRegs.GPASET.bit.GPIO1 = 1
#define LED_STG_off   GpioDataRegs.GPACLEAR.bit.GPIO1 = 1

#define LED_STR_on    GpioDataRegs.GPASET.bit.GPIO0 = 1
#define LED_STR_off   GpioDataRegs.GPACLEAR.bit.GPIO0 = 1

#define PWR_on   GpioDataRegs.GPBSET.bit.GPIO34 = 1
#define PWR_off  GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1

#define GreenT_on   GpioDataRegs.GPBSET.bit.GPIO41 = 1
#define GreenT_off  GpioDataRegs.GPBCLEAR.bit.GPIO41 = 1

#define EN_AUX_on   GpioDataRegs.GPBSET.bit.GPIO43 = 1
#define EN_AUX_off  GpioDataRegs.GPBCLEAR.bit.GPIO43 = 1

#define LED_Pon_on   GpioDataRegs.GPBSET.bit.GPIO39 = 1
#define LED_Pon_off  GpioDataRegs.GPBCLEAR.bit.GPIO39 = 1


//GPIO input pin define
#define _SW_ON      GpioDataRegs.GPADAT.bit.GPIO9
#define _DetBTS     GpioDataRegs.GPADAT.bit.GPIO27
#define _NTC_IO     GpioDataRegs.GPBDAT.bit.GPIO44





#define On 1
#define Off 0





typedef struct
{
    unsigned int    u16_AMP_A;
    unsigned int    u16_AMP_B;
    unsigned int    u16_AMP_C;

    unsigned int    u16_VOL_A;
    unsigned int    u16_VOL_B;
    unsigned int    u16_VOL_C;
    unsigned int    u16_VOL;

    unsigned int    u16_ACIN;

}TY_Tune;


typedef struct
{
    unsigned int    u16_VRate;
    unsigned int    u16_IRate;
}TY_Rate;


typedef struct _ST_EE_SET
{
    TY_Rate   BatBank;
    TY_Rate   StartBat;

    TY_Tune   AD_Gain;              // AD Gain   (3276 ~ 4915 ==> Q10 mode)
    TY_Tune   AD_Offset;            // AD Offset (+/- 819 = 4096 * 20% )

}TY_st_EE_Set;
extern TY_st_EE_Set EE_Set;


typedef struct
{
    TY_Rate   BatBank;
    TY_Rate   StartBat;

}TY_SpecMax;
extern TY_SpecMax st_SpecMax;


































typedef struct
{
    unsigned int    u16_ModbusID;       //def=1 modbus ID

}TY_USER_Set;
extern  TY_USER_Set st_USER_Set;


typedef struct
{
    unsigned int    VBB_shift;
    unsigned int    VSB_shift;

}TY_SysPar;
extern TY_SysPar SysPar;







extern void SysConfig(void);
extern void Init_Def_EE_Set(void);
extern void Init_Def_USER_Set(void);
unsigned int Force_ADC_Sample(void);
void SCI_init(void);

void InitI2C(void);
void Load_Rate_To_Max(void);
void Init_Def_LCM_Pro_Set(void);

#endif /* H_SYSCONFIG_H_ */
