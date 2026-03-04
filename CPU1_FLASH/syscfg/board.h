/*
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef BOARD_H
#define BOARD_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//
// Included Files
//

#include "driverlib.h"
#include "device.h"

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************

//
// ANALOG -> myANALOGPinMux0 Pinmux
//

//
// EPWM1 -> INV_HPWM Pinmux
//
//
// EPWM1_A - GPIO Settings
//
#define GPIO_PIN_EPWM1_A 30
#define INV_HPWM_EPWMA_GPIO 30
#define INV_HPWM_EPWMA_PIN_CONFIG GPIO_30_EPWM1_A
//
// EPWM1_B - GPIO Settings
//
#define GPIO_PIN_EPWM1_B 31
#define INV_HPWM_EPWMB_GPIO 31
#define INV_HPWM_EPWMB_PIN_CONFIG GPIO_31_EPWM1_B

//
// EPWM2 -> INV_LPWM Pinmux
//
//
// EPWM2_A - GPIO Settings
//
#define GPIO_PIN_EPWM2_A 2
#define INV_LPWM_EPWMA_GPIO 2
#define INV_LPWM_EPWMA_PIN_CONFIG GPIO_2_EPWM2_A
//
// EPWM2_B - GPIO Settings
//
#define GPIO_PIN_EPWM2_B 3
#define INV_LPWM_EPWMB_GPIO 3
#define INV_LPWM_EPWMB_PIN_CONFIG GPIO_3_EPWM2_B

//
// EPWM6 -> PuPu_PWM Pinmux
//
//
// EPWM6_A - GPIO Settings
//
#define GPIO_PIN_EPWM6_A 10
#define PuPu_PWM_EPWMA_GPIO 10
#define PuPu_PWM_EPWMA_PIN_CONFIG GPIO_10_EPWM6_A
//
// EPWM6_B - GPIO Settings
//
#define GPIO_PIN_EPWM6_B 11
#define PuPu_PWM_EPWMB_GPIO 11
#define PuPu_PWM_EPWMB_PIN_CONFIG GPIO_11_EPWM6_B

//
// EPWM4 -> Rec_PWM Pinmux
//
//
// EPWM4_A - GPIO Settings
//
#define GPIO_PIN_EPWM4_A 22
#define Rec_PWM_EPWMA_GPIO 22
#define Rec_PWM_EPWMA_PIN_CONFIG GPIO_22_EPWM4_A
//
// EPWM4_B - GPIO Settings
//
#define GPIO_PIN_EPWM4_B 7
#define Rec_PWM_EPWMB_GPIO 7
#define Rec_PWM_EPWMB_PIN_CONFIG GPIO_7_EPWM4_B
//
// GPIO40 - GPIO Settings
//
#define BYPASS_GPIO_PIN_CONFIG GPIO_40_GPIO40
//
// GPIO14 - GPIO Settings
//
#define GNDRLY_GPIO_PIN_CONFIG GPIO_14_GPIO14
//
// GPIO45 - GPIO Settings
//
#define AC_SoftRLY_GPIO_PIN_CONFIG GPIO_45_GPIO45
//
// GPIO15 - GPIO Settings
//
#define DC_SoftRLY_GPIO_PIN_CONFIG GPIO_15_GPIO15
//
// GPIO1 - GPIO Settings
//
#define LED_STG_GPIO_PIN_CONFIG GPIO_1_GPIO1
//
// GPIO0 - GPIO Settings
//
#define LED_STR_GPIO_PIN_CONFIG GPIO_0_GPIO0
//
// GPIO34 - GPIO Settings
//
#define PWR_GPIO_PIN_CONFIG GPIO_34_GPIO34
//
// GPIO41 - GPIO Settings
//
#define GreenT_GPIO_PIN_CONFIG GPIO_41_GPIO41
//
// GPIO43 - GPIO Settings
//
#define EN_AUX_GPIO_PIN_CONFIG GPIO_43_GPIO43
//
// GPIO39 - GPIO Settings
//
#define LED_PonG_GPIO_PIN_CONFIG GPIO_39_GPIO39
//
// GPIO9 - GPIO Settings
//
#define SW_On_GPIO_PIN_CONFIG GPIO_9_GPIO9
//
// GPIO27 - GPIO Settings
//
#define DetBTS_GPIO_PIN_CONFIG GPIO_27_GPIO27
//
// GPIO44 - GPIO Settings
//
#define NTC_IO_GPIO_PIN_CONFIG GPIO_44_GPIO44

//*****************************************************************************
//
// ADC Configurations
//
//*****************************************************************************
#define myADC0_BASE ADCA_BASE
#define myADC0_RESULT_BASE ADCARESULT_BASE
#define myADC0_SOC0 ADC_SOC_NUMBER0
#define myADC0_FORCE_SOC0 ADC_FORCE_SOC0
#define myADC0_SAMPLE_WINDOW_SOC0 90
#define myADC0_TRIGGER_SOURCE_SOC0 ADC_TRIGGER_EPWM1_SOCA
#define myADC0_CHANNEL_SOC0 ADC_CH_ADCIN0
#define myADC0_SOC1 ADC_SOC_NUMBER1
#define myADC0_FORCE_SOC1 ADC_FORCE_SOC1
#define myADC0_SAMPLE_WINDOW_SOC1 90
#define myADC0_TRIGGER_SOURCE_SOC1 ADC_TRIGGER_EPWM1_SOCA
#define myADC0_CHANNEL_SOC1 ADC_CH_ADCIN1
#define myADC0_SOC2 ADC_SOC_NUMBER2
#define myADC0_FORCE_SOC2 ADC_FORCE_SOC2
#define myADC0_SAMPLE_WINDOW_SOC2 90
#define myADC0_TRIGGER_SOURCE_SOC2 ADC_TRIGGER_EPWM1_SOCA
#define myADC0_CHANNEL_SOC2 ADC_CH_ADCIN2
#define myADC0_SOC3 ADC_SOC_NUMBER3
#define myADC0_FORCE_SOC3 ADC_FORCE_SOC3
#define myADC0_SAMPLE_WINDOW_SOC3 90
#define myADC0_TRIGGER_SOURCE_SOC3 ADC_TRIGGER_EPWM1_SOCA
#define myADC0_CHANNEL_SOC3 ADC_CH_ADCIN3
#define myADC0_SOC4 ADC_SOC_NUMBER4
#define myADC0_FORCE_SOC4 ADC_FORCE_SOC4
#define myADC0_SAMPLE_WINDOW_SOC4 90
#define myADC0_TRIGGER_SOURCE_SOC4 ADC_TRIGGER_EPWM1_SOCA
#define myADC0_CHANNEL_SOC4 ADC_CH_ADCIN4
#define myADC0_SOC5 ADC_SOC_NUMBER5
#define myADC0_FORCE_SOC5 ADC_FORCE_SOC5
#define myADC0_SAMPLE_WINDOW_SOC5 90
#define myADC0_TRIGGER_SOURCE_SOC5 ADC_TRIGGER_EPWM1_SOCA
#define myADC0_CHANNEL_SOC5 ADC_CH_ADCIN5
#define myADC0_SOC6 ADC_SOC_NUMBER6
#define myADC0_FORCE_SOC6 ADC_FORCE_SOC6
#define myADC0_SAMPLE_WINDOW_SOC6 90
#define myADC0_TRIGGER_SOURCE_SOC6 ADC_TRIGGER_EPWM1_SOCA
#define myADC0_CHANNEL_SOC6 ADC_CH_ADCIN6
#define myADC0_SOC7 ADC_SOC_NUMBER7
#define myADC0_FORCE_SOC7 ADC_FORCE_SOC7
#define myADC0_SAMPLE_WINDOW_SOC7 90
#define myADC0_TRIGGER_SOURCE_SOC7 ADC_TRIGGER_EPWM1_SOCA
#define myADC0_CHANNEL_SOC7 ADC_CH_ADCIN7
#define myADC0_SOC8 ADC_SOC_NUMBER8
#define myADC0_FORCE_SOC8 ADC_FORCE_SOC8
#define myADC0_SAMPLE_WINDOW_SOC8 90
#define myADC0_TRIGGER_SOURCE_SOC8 ADC_TRIGGER_EPWM1_SOCA
#define myADC0_CHANNEL_SOC8 ADC_CH_ADCIN9
#define myADC0_SOC9 ADC_SOC_NUMBER9
#define myADC0_FORCE_SOC9 ADC_FORCE_SOC9
#define myADC0_SAMPLE_WINDOW_SOC9 90
#define myADC0_TRIGGER_SOURCE_SOC9 ADC_TRIGGER_EPWM1_SOCA
#define myADC0_CHANNEL_SOC9 ADC_CH_ADCIN10
void myADC0_init();

#define myADC1_BASE ADCC_BASE
#define myADC1_RESULT_BASE ADCCRESULT_BASE
#define myADC1_SOC0 ADC_SOC_NUMBER0
#define myADC1_FORCE_SOC0 ADC_FORCE_SOC0
#define myADC1_SAMPLE_WINDOW_SOC0 90
#define myADC1_TRIGGER_SOURCE_SOC0 ADC_TRIGGER_CPU1_TINT0
#define myADC1_CHANNEL_SOC0 ADC_CH_ADCIN11
#define myADC1_SOC1 ADC_SOC_NUMBER1
#define myADC1_FORCE_SOC1 ADC_FORCE_SOC1
#define myADC1_SAMPLE_WINDOW_SOC1 90
#define myADC1_TRIGGER_SOURCE_SOC1 ADC_TRIGGER_CPU1_TINT0
#define myADC1_CHANNEL_SOC1 ADC_CH_ADCIN0
#define myADC1_SOC2 ADC_SOC_NUMBER2
#define myADC1_FORCE_SOC2 ADC_FORCE_SOC2
#define myADC1_SAMPLE_WINDOW_SOC2 90
#define myADC1_TRIGGER_SOURCE_SOC2 ADC_TRIGGER_CPU1_TINT0
#define myADC1_CHANNEL_SOC2 ADC_CH_ADCIN1
#define myADC1_SOC3 ADC_SOC_NUMBER3
#define myADC1_FORCE_SOC3 ADC_FORCE_SOC3
#define myADC1_SAMPLE_WINDOW_SOC3 90
#define myADC1_TRIGGER_SOURCE_SOC3 ADC_TRIGGER_CPU1_TINT0
#define myADC1_CHANNEL_SOC3 ADC_CH_ADCIN4
#define myADC1_SOC4 ADC_SOC_NUMBER4
#define myADC1_FORCE_SOC4 ADC_FORCE_SOC4
#define myADC1_SAMPLE_WINDOW_SOC4 90
#define myADC1_TRIGGER_SOURCE_SOC4 ADC_TRIGGER_CPU1_TINT0
#define myADC1_CHANNEL_SOC4 ADC_CH_ADCIN7
#define myADC1_SOC5 ADC_SOC_NUMBER5
#define myADC1_FORCE_SOC5 ADC_FORCE_SOC5
#define myADC1_SAMPLE_WINDOW_SOC5 90
#define myADC1_TRIGGER_SOURCE_SOC5 ADC_TRIGGER_CPU1_TINT0
#define myADC1_CHANNEL_SOC5 ADC_CH_ADCIN6
void myADC1_init();


//*****************************************************************************
//
// ASYSCTL Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// CPUTIMER Configurations
//
//*****************************************************************************
#define myCPUTIMER0_BASE CPUTIMER0_BASE
void myCPUTIMER0_init();

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
#define INV_HPWM_BASE EPWM1_BASE
#define INV_HPWM_TBPRD 2500
#define INV_HPWM_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define INV_HPWM_TBPHS 0
#define INV_HPWM_CMPA 1250
#define INV_HPWM_CMPB 1250
#define INV_HPWM_CMPC 0
#define INV_HPWM_CMPD 0
#define INV_HPWM_DBRED 100
#define INV_HPWM_DBFED 100
#define INV_HPWM_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define INV_HPWM_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define INV_HPWM_INTERRUPT_SOURCE EPWM_INT_TBCTR_PERIOD
#define INV_LPWM_BASE EPWM2_BASE
#define INV_LPWM_TBPRD 2500
#define INV_LPWM_COUNTER_MODE EPWM_COUNTER_MODE_UP
#define INV_LPWM_TBPHS 1
#define INV_LPWM_CMPA 1250
#define INV_LPWM_CMPB 1250
#define INV_LPWM_CMPC 0
#define INV_LPWM_CMPD 0
#define INV_LPWM_DBRED 100
#define INV_LPWM_DBFED 100
#define INV_LPWM_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define INV_LPWM_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define INV_LPWM_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define PuPu_PWM_BASE EPWM6_BASE
#define PuPu_PWM_TBPRD 2500
#define PuPu_PWM_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define PuPu_PWM_TBPHS 1
#define PuPu_PWM_CMPA 50
#define PuPu_PWM_CMPB 2450
#define PuPu_PWM_CMPC 0
#define PuPu_PWM_CMPD 0
#define PuPu_PWM_DBRED 0
#define PuPu_PWM_DBFED 0
#define PuPu_PWM_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define PuPu_PWM_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define PuPu_PWM_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define Rec_PWM_BASE EPWM4_BASE
#define Rec_PWM_TBPRD 2500
#define Rec_PWM_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define Rec_PWM_TBPHS 0
#define Rec_PWM_CMPA 50
#define Rec_PWM_CMPB 2450
#define Rec_PWM_CMPC 0
#define Rec_PWM_CMPD 0
#define Rec_PWM_DBRED 0
#define Rec_PWM_DBFED 0
#define Rec_PWM_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define Rec_PWM_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define Rec_PWM_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
#define BYPASS 40
void BYPASS_init();
#define GNDRLY 14
void GNDRLY_init();
#define AC_SoftRLY 45
void AC_SoftRLY_init();
#define DC_SoftRLY 15
void DC_SoftRLY_init();
#define LED_STG 1
void LED_STG_init();
#define LED_STR 0
void LED_STR_init();
#define PWR 34
void PWR_init();
#define GreenT 41
void GreenT_init();
#define EN_AUX 43
void EN_AUX_init();
#define LED_PonG 39
void LED_PonG_init();
#define SW_On 9
void SW_On_init();
#define DetBTS 27
void DetBTS_init();
#define NTC_IO 44
void NTC_IO_init();

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************

// Interrupt Settings for INT_myCPUTIMER0
#define INT_myCPUTIMER0 INT_TIMER0
#define INT_myCPUTIMER0_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void INT_myCPUTIMER0_ISR(void);

// Interrupt Settings for INT_INV_HPWM
#define INT_INV_HPWM INT_EPWM1
#define INT_INV_HPWM_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP3
extern __interrupt void INT_INV_HPWM_ISR(void);

//*****************************************************************************
//
// SYNC Scheme Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void	Board_init();
void	ADC_init();
void	ASYSCTL_init();
void	CPUTIMER_init();
void	EPWM_init();
void	GPIO_init();
void	INTERRUPT_init();
void	SYNC_init();
void	PinMux_init();

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif  // end of BOARD_H definition
