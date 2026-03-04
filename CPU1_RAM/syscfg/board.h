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
// CPUTIMER Configurations
//
//*****************************************************************************
#define myCPUTIMER0_BASE CPUTIMER0_BASE
void myCPUTIMER0_init();

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

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void	Board_init();
void	CPUTIMER_init();
void	GPIO_init();
void	INTERRUPT_init();
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
