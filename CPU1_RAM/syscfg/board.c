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
	INTERRUPT_init();

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
	
	// GPIO40 -> BYPASS Pinmux
	GPIO_setPinConfig(GPIO_40_GPIO40);
	// GPIO14 -> GNDRLY Pinmux
	GPIO_setPinConfig(GPIO_14_GPIO14);
	// GPIO45 -> AC_SoftRLY Pinmux
	GPIO_setPinConfig(GPIO_45_GPIO45);
	// GPIO15 -> DC_SoftRLY Pinmux
	GPIO_setPinConfig(GPIO_15_GPIO15);
	// GPIO1 -> LED_STG Pinmux
	GPIO_setPinConfig(GPIO_1_GPIO1);
	// GPIO0 -> LED_STR Pinmux
	GPIO_setPinConfig(GPIO_0_GPIO0);
	// GPIO34 -> PWR Pinmux
	GPIO_setPinConfig(GPIO_34_GPIO34);
	// GPIO41 -> GreenT Pinmux
	GPIO_setPinConfig(GPIO_41_GPIO41);
	// GPIO43 -> EN_AUX Pinmux
	GPIO_setPinConfig(GPIO_43_GPIO43);
	// GPIO39 -> LED_PonG Pinmux
	GPIO_setPinConfig(GPIO_39_GPIO39);
	// GPIO9 -> SW_On Pinmux
	GPIO_setPinConfig(GPIO_9_GPIO9);
	// GPIO27 -> DetBTS Pinmux
	GPIO_setPinConfig(GPIO_27_GPIO27);
	// GPIO44 -> NTC_IO Pinmux
	GPIO_setPinConfig(GPIO_44_GPIO44);

}

//*****************************************************************************
//
// CPUTIMER Configurations
//
//*****************************************************************************
void CPUTIMER_init(){
	myCPUTIMER0_init();
}

void myCPUTIMER0_init(){
	CPUTimer_setEmulationMode(myCPUTIMER0_BASE, CPUTIMER_EMULATIONMODE_STOPAFTERNEXTDECREMENT);
	CPUTimer_setPreScaler(myCPUTIMER0_BASE, 0U);
	CPUTimer_setPeriod(myCPUTIMER0_BASE, 2000U);
	CPUTimer_enableInterrupt(myCPUTIMER0_BASE);
	CPUTimer_stopTimer(myCPUTIMER0_BASE);

	CPUTimer_reloadTimerCounter(myCPUTIMER0_BASE);
}

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
void GPIO_init(){
	BYPASS_init();
	GNDRLY_init();
	AC_SoftRLY_init();
	DC_SoftRLY_init();
	LED_STG_init();
	LED_STR_init();
	PWR_init();
	GreenT_init();
	EN_AUX_init();
	LED_PonG_init();
	SW_On_init();
	DetBTS_init();
	NTC_IO_init();
}

void BYPASS_init(){
	GPIO_writePin(BYPASS, 0);
	GPIO_setPadConfig(BYPASS, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(BYPASS, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(BYPASS, GPIO_DIR_MODE_OUT);
}
void GNDRLY_init(){
	GPIO_writePin(GNDRLY, 0);
	GPIO_setPadConfig(GNDRLY, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(GNDRLY, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(GNDRLY, GPIO_DIR_MODE_OUT);
}
void AC_SoftRLY_init(){
	GPIO_writePin(AC_SoftRLY, 0);
	GPIO_setPadConfig(AC_SoftRLY, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(AC_SoftRLY, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(AC_SoftRLY, GPIO_DIR_MODE_OUT);
}
void DC_SoftRLY_init(){
	GPIO_writePin(DC_SoftRLY, 0);
	GPIO_setPadConfig(DC_SoftRLY, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(DC_SoftRLY, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(DC_SoftRLY, GPIO_DIR_MODE_OUT);
}
void LED_STG_init(){
	GPIO_writePin(LED_STG, 0);
	GPIO_setPadConfig(LED_STG, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(LED_STG, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(LED_STG, GPIO_DIR_MODE_OUT);
}
void LED_STR_init(){
	GPIO_writePin(LED_STR, 0);
	GPIO_setPadConfig(LED_STR, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(LED_STR, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(LED_STR, GPIO_DIR_MODE_OUT);
}
void PWR_init(){
	GPIO_writePin(PWR, 0);
	GPIO_setPadConfig(PWR, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(PWR, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(PWR, GPIO_DIR_MODE_OUT);
}
void GreenT_init(){
	GPIO_writePin(GreenT, 0);
	GPIO_setPadConfig(GreenT, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(GreenT, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(GreenT, GPIO_DIR_MODE_OUT);
}
void EN_AUX_init(){
	GPIO_writePin(EN_AUX, 0);
	GPIO_setPadConfig(EN_AUX, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(EN_AUX, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(EN_AUX, GPIO_DIR_MODE_OUT);
}
void LED_PonG_init(){
	GPIO_writePin(LED_PonG, 0);
	GPIO_setPadConfig(LED_PonG, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(LED_PonG, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(LED_PonG, GPIO_DIR_MODE_OUT);
}
void SW_On_init(){
	GPIO_writePin(SW_On, 0);
	GPIO_setPadConfig(SW_On, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(SW_On, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(SW_On, GPIO_DIR_MODE_IN);
}
void DetBTS_init(){
	GPIO_writePin(DetBTS, 0);
	GPIO_setPadConfig(DetBTS, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(DetBTS, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(DetBTS, GPIO_DIR_MODE_IN);
}
void NTC_IO_init(){
	GPIO_writePin(NTC_IO, 0);
	GPIO_setPadConfig(NTC_IO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(NTC_IO, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(NTC_IO, GPIO_DIR_MODE_IN);
}

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************
void INTERRUPT_init(){
	
	// Interrupt Setings for INT_myCPUTIMER0
	Interrupt_register(INT_myCPUTIMER0, &INT_myCPUTIMER0_ISR);
	Interrupt_enable(INT_myCPUTIMER0);
}
