/*
 * SysConfig.h
 *
 *  Created on: 2025�~10��10��
 *      Author: wujw
 */

#ifndef H_SYSCONFIG_H_
#define H_SYSCONFIG_H_

#define SYSCLK_FREQ    100000000UL

#define INV_PWM_FREQ   30000UL
#define INV_PWM_TBPRD  SYSCLK_FREQ/(INV_PWM_FREQ*2)   // up/down counter


#define Inv_PWM_Ts            1.0f/INV_PWM_FREQ







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
#define _Ext_On     GpioDataRegs.GPADAT.bit.GPIO29
#define _DetBTS     GpioDataRegs.GPADAT.bit.GPIO27
#define _NTC_IO     GpioDataRegs.GPBDAT.bit.GPIO44





#define On 1
#define Off 0





// EE_Set definitions moved to h\EEprom\EE_Set.h

extern void SysConfig(void);
extern void EEprom_init(void);

void SCI_init(void);


#endif /* H_SYSCONFIG_H_ */
