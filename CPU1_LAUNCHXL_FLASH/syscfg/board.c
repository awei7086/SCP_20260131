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

#include "board.h"

//*****************************************************************************
//
// Board Configurations
// Initializes the rest of the modules. 
// Call this function in your application if you wish to do all module 
// initialization.
// If you wish to not use some of the initializations, instead of the 
// Board_init use the individual Module_inits
//
//*****************************************************************************
void Board_init()
{
	EALLOW;

	PinMux_init();
	CPUTIMER_init();
	GPIO_init();

	EDIS;
}

//*****************************************************************************
//
// PINMUX Configurations
//
//*****************************************************************************
void PinMux_init()
{
	//
	// PinMux for modules assigned to CPU1
	//
	
	// GPIO5 -> DC_OK Pinmux
	GPIO_setPinConfig(GPIO_5_GPIO5);
	// GPIO9 -> AC_OK Pinmux
	GPIO_setPinConfig(GPIO_9_GPIO9);
	// GPIO10 -> Fail Pinmux
	GPIO_setPinConfig(GPIO_10_GPIO10);
	// GPIO28 -> LED_G Pinmux
	GPIO_setPinConfig(GPIO_28_GPIO28);
	// GPIO29 -> LED_R Pinmux
	GPIO_setPinConfig(GPIO_29_GPIO29);
	// GPIO6 -> INHIBIT Pinmux
	GPIO_setPinConfig(GPIO_6_GPIO6);
	// GPIO23 -> SYNC Pinmux
	GPIO_setPinConfig(GPIO_23_GPIO23);
	// GPIO30 -> myGPIO0 Pinmux
	GPIO_setPinConfig(GPIO_30_GPIO30);

}

//*****************************************************************************
//
// CPUTIMER Configurations
//
//*****************************************************************************
void CPUTIMER_init(){
	myCPUTIMER0_init();
	myCPUTIMER1_init();
}

void myCPUTIMER0_init(){
	CPUTimer_setEmulationMode(myCPUTIMER0_BASE, CPUTIMER_EMULATIONMODE_RUNFREE);
	CPUTimer_setPreScaler(myCPUTIMER0_BASE, 0U);
	CPUTimer_setPeriod(myCPUTIMER0_BASE, 6000U);
	CPUTimer_disableInterrupt(myCPUTIMER0_BASE);
	CPUTimer_stopTimer(myCPUTIMER0_BASE);

	CPUTimer_reloadTimerCounter(myCPUTIMER0_BASE);
	CPUTimer_startTimer(myCPUTIMER0_BASE);
}
void myCPUTIMER1_init(){
	CPUTimer_setEmulationMode(myCPUTIMER1_BASE, CPUTIMER_EMULATIONMODE_STOPAFTERNEXTDECREMENT);
	CPUTimer_setPreScaler(myCPUTIMER1_BASE, 0U);
	CPUTimer_setPeriod(myCPUTIMER1_BASE, 12000U);
	CPUTimer_disableInterrupt(myCPUTIMER1_BASE);
	CPUTimer_stopTimer(myCPUTIMER1_BASE);

	CPUTimer_reloadTimerCounter(myCPUTIMER1_BASE);
	CPUTimer_startTimer(myCPUTIMER1_BASE);
}

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
void GPIO_init(){
	DC_OK_init();
	AC_OK_init();
	Fail_init();
	LED_G_init();
	LED_R_init();
	INHIBIT_init();
	SYNC_init();
	myGPIO0_init();
}

void DC_OK_init(){
	GPIO_writePin(DC_OK, 0);
	GPIO_setPadConfig(DC_OK, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(DC_OK, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(DC_OK, GPIO_DIR_MODE_OUT);
}
void AC_OK_init(){
	GPIO_writePin(AC_OK, 0);
	GPIO_setPadConfig(AC_OK, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(AC_OK, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(AC_OK, GPIO_DIR_MODE_OUT);
}
void Fail_init(){
	GPIO_writePin(Fail, 0);
	GPIO_setPadConfig(Fail, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(Fail, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(Fail, GPIO_DIR_MODE_OUT);
}
void LED_G_init(){
	GPIO_writePin(LED_G, 0);
	GPIO_setPadConfig(LED_G, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(LED_G, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(LED_G, GPIO_DIR_MODE_OUT);
}
void LED_R_init(){
	GPIO_writePin(LED_R, 0);
	GPIO_setPadConfig(LED_R, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(LED_R, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(LED_R, GPIO_DIR_MODE_OUT);
}
void INHIBIT_init(){
	GPIO_writePin(INHIBIT, 0);
	GPIO_setPadConfig(INHIBIT, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(INHIBIT, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(INHIBIT, GPIO_DIR_MODE_IN);
}
void SYNC_init(){
	GPIO_writePin(SYNC, 0);
	GPIO_setPadConfig(SYNC, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(SYNC, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(SYNC, GPIO_DIR_MODE_IN);
}
void myGPIO0_init(){
	GPIO_setPadConfig(myGPIO0, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(myGPIO0, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(myGPIO0, GPIO_DIR_MODE_IN);
}

