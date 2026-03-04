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
// GPIO5 - GPIO Settings
//
#define DC_OK_GPIO_PIN_CONFIG GPIO_5_GPIO5
//
// GPIO9 - GPIO Settings
//
#define AC_OK_GPIO_PIN_CONFIG GPIO_9_GPIO9
//
// GPIO10 - GPIO Settings
//
#define Fail_GPIO_PIN_CONFIG GPIO_10_GPIO10
//
// GPIO28 - GPIO Settings
//
#define LED_G_GPIO_PIN_CONFIG GPIO_28_GPIO28
//
// GPIO29 - GPIO Settings
//
#define LED_R_GPIO_PIN_CONFIG GPIO_29_GPIO29
//
// GPIO6 - GPIO Settings
//
#define INHIBIT_GPIO_PIN_CONFIG GPIO_6_GPIO6
//
// GPIO23 - GPIO Settings
//
#define SYNC_GPIO_PIN_CONFIG GPIO_23_GPIO23
//
// GPIO30 - GPIO Settings
//
#define myGPIO0_GPIO_PIN_CONFIG GPIO_30_GPIO30

//*****************************************************************************
//
// CPUTIMER Configurations
//
//*****************************************************************************
#define myCPUTIMER0_BASE CPUTIMER0_BASE
void myCPUTIMER0_init();
#define myCPUTIMER1_BASE CPUTIMER1_BASE
void myCPUTIMER1_init();

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
#define DC_OK 5
void DC_OK_init();
#define AC_OK 9
void AC_OK_init();
#define Fail 10
void Fail_init();
#define LED_G 28
void LED_G_init();
#define LED_R 29
void LED_R_init();
#define INHIBIT 6
void INHIBIT_init();
#define SYNC 23
void SYNC_init();
#define myGPIO0 30
void myGPIO0_init();

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void	Board_init();
void	CPUTIMER_init();
void	GPIO_init();
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
