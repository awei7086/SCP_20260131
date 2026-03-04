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
	SYNC_init();
	ASYSCTL_init();
	ADC_init();
	CPUTIMER_init();
	EPWM_init();
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
	
	//
	// ANALOG -> myANALOGPinMux0 Pinmux
	//
	// Analog PinMux for A0/C15
	GPIO_setPinConfig(GPIO_231_GPIO231);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(231, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A1
	GPIO_setPinConfig(GPIO_232_GPIO232);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(232, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A10/C10
	GPIO_setPinConfig(GPIO_230_GPIO230);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(230, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A11/C0
	GPIO_setPinConfig(GPIO_237_GPIO237);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(237, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A12/C1
	GPIO_setPinConfig(GPIO_238_GPIO238);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(238, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A14/C4
	GPIO_setPinConfig(GPIO_239_GPIO239);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(239, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A15/C7
	GPIO_setPinConfig(GPIO_233_GPIO233);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(233, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A2/C9
	GPIO_setPinConfig(GPIO_224_GPIO224);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(224, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A3/C5/VDAC
	GPIO_setPinConfig(GPIO_242_GPIO242);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(242, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A4/C14
	GPIO_setPinConfig(GPIO_225_GPIO225);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(225, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A5/C2
	GPIO_setPinConfig(GPIO_244_GPIO244);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(244, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A6
	GPIO_setPinConfig(GPIO_228_GPIO228);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(228, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A7/C3
	GPIO_setPinConfig(GPIO_245_GPIO245);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(245, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A8/C11
	GPIO_setPinConfig(GPIO_241_GPIO241);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(241, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A9/C8
	GPIO_setPinConfig(GPIO_227_GPIO227);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(227, GPIO_ANALOG_ENABLED);
	// Analog PinMux for C6
	GPIO_setPinConfig(GPIO_226_GPIO226);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(226, GPIO_ANALOG_ENABLED);
	//
	// EPWM1 -> INV_HPWM Pinmux
	//
	GPIO_setPinConfig(INV_HPWM_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(INV_HPWM_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(INV_HPWM_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(INV_HPWM_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(INV_HPWM_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(INV_HPWM_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM2 -> INV_LPWM Pinmux
	//
	GPIO_setPinConfig(INV_LPWM_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(INV_LPWM_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(INV_LPWM_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(INV_LPWM_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(INV_LPWM_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(INV_LPWM_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM6 -> PuPu_PWM Pinmux
	//
	GPIO_setPinConfig(PuPu_PWM_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(PuPu_PWM_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(PuPu_PWM_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(PuPu_PWM_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(PuPu_PWM_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(PuPu_PWM_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM4 -> Rec_PWM Pinmux
	//
	GPIO_setPinConfig(Rec_PWM_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(Rec_PWM_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(Rec_PWM_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(Rec_PWM_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(Rec_PWM_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(Rec_PWM_EPWMB_GPIO, GPIO_QUAL_SYNC);

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
// ADC Configurations
//
//*****************************************************************************
void ADC_init(){
	myADC0_init();
	myADC1_init();
}

void myADC0_init(){
	//
	// ADC Initialization: Write ADC configurations and power up the ADC
	//
	// Configures the ADC module's offset trim
	//
	ADC_setOffsetTrimAll(ADC_REFERENCE_EXTERNAL,ADC_REFERENCE_2_5V);
	//
	// Configures the analog-to-digital converter module prescaler.
	//
	ADC_setPrescaler(myADC0_BASE, ADC_CLK_DIV_2_0);
	//
	// Sets the timing of the end-of-conversion pulse
	//
	ADC_setInterruptPulseMode(myADC0_BASE, ADC_PULSE_END_OF_CONV);
	//
	// Powers up the analog-to-digital converter core.
	//
	ADC_enableConverter(myADC0_BASE);
	//
	// Delay for 1ms to allow ADC time to power up
	//
	DEVICE_DELAY_US(500);
	//
	// SOC Configuration: Setup ADC EPWM channel and trigger settings
	//
	// Disables SOC burst mode.
	//
	ADC_disableBurstMode(myADC0_BASE);
	//
	// Sets the priority mode of the SOCs.
	//
	ADC_setSOCPriority(myADC0_BASE, ADC_PRI_THRU_SOC9_HIPRI);
	//
	// Start of Conversion 0 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 0
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN0
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC0_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN0, 9U);
	ADC_setInterruptSOCTrigger(myADC0_BASE, ADC_SOC_NUMBER0, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 1 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 1
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN1
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC0_BASE, ADC_SOC_NUMBER1, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN1, 9U);
	ADC_setInterruptSOCTrigger(myADC0_BASE, ADC_SOC_NUMBER1, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 2 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 2
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN2
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC0_BASE, ADC_SOC_NUMBER2, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN2, 9U);
	ADC_setInterruptSOCTrigger(myADC0_BASE, ADC_SOC_NUMBER2, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 3 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 3
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN3
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC0_BASE, ADC_SOC_NUMBER3, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN3, 9U);
	ADC_setInterruptSOCTrigger(myADC0_BASE, ADC_SOC_NUMBER3, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 4 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 4
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN4
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC0_BASE, ADC_SOC_NUMBER4, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN4, 9U);
	ADC_setInterruptSOCTrigger(myADC0_BASE, ADC_SOC_NUMBER4, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 5 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 5
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN5
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC0_BASE, ADC_SOC_NUMBER5, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN5, 9U);
	ADC_setInterruptSOCTrigger(myADC0_BASE, ADC_SOC_NUMBER5, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 6 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 6
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN6
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC0_BASE, ADC_SOC_NUMBER6, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN6, 9U);
	ADC_setInterruptSOCTrigger(myADC0_BASE, ADC_SOC_NUMBER6, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 7 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 7
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN7
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC0_BASE, ADC_SOC_NUMBER7, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN7, 9U);
	ADC_setInterruptSOCTrigger(myADC0_BASE, ADC_SOC_NUMBER7, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 8 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 8
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN9
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC0_BASE, ADC_SOC_NUMBER8, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN9, 9U);
	ADC_setInterruptSOCTrigger(myADC0_BASE, ADC_SOC_NUMBER8, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 9 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 9
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN10
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC0_BASE, ADC_SOC_NUMBER9, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN10, 9U);
	ADC_setInterruptSOCTrigger(myADC0_BASE, ADC_SOC_NUMBER9, ADC_INT_SOC_TRIGGER_NONE);
}
void myADC1_init(){
	//
	// ADC Initialization: Write ADC configurations and power up the ADC
	//
	// Configures the ADC module's offset trim
	//
	ADC_setOffsetTrimAll(ADC_REFERENCE_EXTERNAL,ADC_REFERENCE_2_5V);
	//
	// Configures the analog-to-digital converter module prescaler.
	//
	ADC_setPrescaler(myADC1_BASE, ADC_CLK_DIV_2_0);
	//
	// Sets the timing of the end-of-conversion pulse
	//
	ADC_setInterruptPulseMode(myADC1_BASE, ADC_PULSE_END_OF_ACQ_WIN);
	//
	// Sets the timing of early interrupt generation.
	//
	ADC_setInterruptCycleOffset(myADC1_BASE, 0U);
	//
	// Powers up the analog-to-digital converter core.
	//
	ADC_enableConverter(myADC1_BASE);
	//
	// Delay for 1ms to allow ADC time to power up
	//
	DEVICE_DELAY_US(500);
	//
	// SOC Configuration: Setup ADC EPWM channel and trigger settings
	//
	// Disables SOC burst mode.
	//
	ADC_disableBurstMode(myADC1_BASE);
	//
	// Sets the priority mode of the SOCs.
	//
	ADC_setSOCPriority(myADC1_BASE, ADC_PRI_THRU_SOC5_HIPRI);
	//
	// Start of Conversion 0 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 0
	//	  	Trigger			: ADC_TRIGGER_CPU1_TINT0
	//	  	Channel			: ADC_CH_ADCIN11
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC1_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_CPU1_TINT0, ADC_CH_ADCIN11, 9U);
	ADC_setInterruptSOCTrigger(myADC1_BASE, ADC_SOC_NUMBER0, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 1 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 1
	//	  	Trigger			: ADC_TRIGGER_CPU1_TINT0
	//	  	Channel			: ADC_CH_ADCIN0
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC1_BASE, ADC_SOC_NUMBER1, ADC_TRIGGER_CPU1_TINT0, ADC_CH_ADCIN0, 9U);
	ADC_setInterruptSOCTrigger(myADC1_BASE, ADC_SOC_NUMBER1, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 2 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 2
	//	  	Trigger			: ADC_TRIGGER_CPU1_TINT0
	//	  	Channel			: ADC_CH_ADCIN1
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC1_BASE, ADC_SOC_NUMBER2, ADC_TRIGGER_CPU1_TINT0, ADC_CH_ADCIN1, 9U);
	ADC_setInterruptSOCTrigger(myADC1_BASE, ADC_SOC_NUMBER2, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 3 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 3
	//	  	Trigger			: ADC_TRIGGER_CPU1_TINT0
	//	  	Channel			: ADC_CH_ADCIN4
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC1_BASE, ADC_SOC_NUMBER3, ADC_TRIGGER_CPU1_TINT0, ADC_CH_ADCIN4, 9U);
	ADC_setInterruptSOCTrigger(myADC1_BASE, ADC_SOC_NUMBER3, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 4 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 4
	//	  	Trigger			: ADC_TRIGGER_CPU1_TINT0
	//	  	Channel			: ADC_CH_ADCIN7
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC1_BASE, ADC_SOC_NUMBER4, ADC_TRIGGER_CPU1_TINT0, ADC_CH_ADCIN7, 9U);
	ADC_setInterruptSOCTrigger(myADC1_BASE, ADC_SOC_NUMBER4, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 5 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 5
	//	  	Trigger			: ADC_TRIGGER_CPU1_TINT0
	//	  	Channel			: ADC_CH_ADCIN6
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC1_BASE, ADC_SOC_NUMBER5, ADC_TRIGGER_CPU1_TINT0, ADC_CH_ADCIN6, 9U);
	ADC_setInterruptSOCTrigger(myADC1_BASE, ADC_SOC_NUMBER5, ADC_INT_SOC_TRIGGER_NONE);
}

//*****************************************************************************
//
// ASYSCTL Configurations
//
//*****************************************************************************
void ASYSCTL_init(){
	//
	// asysctl initialization
	//
	// Disables the temperature sensor output to the ADC.
	//
	ASysCtl_disableTemperatureSensor();
	//
	// Set the analog voltage reference selection to external.
	//
	ASysCtl_setAnalogReferenceExternal( ASYSCTL_VREFHIA | ASYSCTL_VREFHIC );
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
	CPUTimer_setPeriod(myCPUTIMER0_BASE, 5000U);
	CPUTimer_enableInterrupt(myCPUTIMER0_BASE);
	CPUTimer_stopTimer(myCPUTIMER0_BASE);

	CPUTimer_reloadTimerCounter(myCPUTIMER0_BASE);
}

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
void EPWM_init(){
    EPWM_enableGlobalLoad(INV_HPWM_BASE);	
    EPWM_setGlobalLoadTrigger(INV_HPWM_BASE, EPWM_GL_LOAD_PULSE_CNTR_PERIOD);	
    EPWM_setGlobalLoadEventPrescale(INV_HPWM_BASE, 1);	
    EPWM_setupEPWMLinks(INV_HPWM_BASE, EPWM_LINK_WITH_EPWM_1, EPWM_LINK_GLDCTL2);	
    EPWM_setEmulationMode(INV_HPWM_BASE, EPWM_EMULATION_FREE_RUN);	
    EPWM_setClockPrescaler(INV_HPWM_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(INV_HPWM_BASE, 2500);	
    EPWM_setupEPWMLinks(INV_HPWM_BASE, EPWM_LINK_WITH_EPWM_1, EPWM_LINK_TBPRD);	
    EPWM_setTimeBaseCounter(INV_HPWM_BASE, 0);	
    EPWM_setTimeBaseCounterMode(INV_HPWM_BASE, EPWM_COUNTER_MODE_UP_DOWN);	
    EPWM_disablePhaseShiftLoad(INV_HPWM_BASE);	
    EPWM_setPhaseShift(INV_HPWM_BASE, 0);	
    EPWM_enableSyncOutPulseSource(INV_HPWM_BASE, EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(INV_HPWM_BASE, EPWM_COUNTER_COMPARE_A, 1250);	
    EPWM_enableGlobalLoadRegisters(INV_HPWM_BASE, EPWM_GL_REGISTER_CMPA_CMPAHR);	
    EPWM_setCounterCompareShadowLoadMode(INV_HPWM_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_PERIOD);	
    EPWM_setupEPWMLinks(INV_HPWM_BASE, EPWM_LINK_WITH_EPWM_1, EPWM_LINK_COMP_A);	
    EPWM_setCounterCompareValue(INV_HPWM_BASE, EPWM_COUNTER_COMPARE_B, 1250);	
    EPWM_enableGlobalLoadRegisters(INV_HPWM_BASE, EPWM_GL_REGISTER_CMPB_CMPBHR);	
    EPWM_setCounterCompareShadowLoadMode(INV_HPWM_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_PERIOD);	
    EPWM_setupEPWMLinks(INV_HPWM_BASE, EPWM_LINK_WITH_EPWM_1, EPWM_LINK_COMP_B);	
    EPWM_enableGlobalLoadRegisters(INV_HPWM_BASE, EPWM_GL_REGISTER_AQCTLA_AQCTLA2);	
    EPWM_setActionQualifierShadowLoadMode(INV_HPWM_BASE, EPWM_ACTION_QUALIFIER_A, EPWM_AQ_LOAD_ON_CNTR_PERIOD);	
    EPWM_setActionQualifierAction(INV_HPWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(INV_HPWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(INV_HPWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(INV_HPWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(INV_HPWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(INV_HPWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_enableGlobalLoadRegisters(INV_HPWM_BASE, EPWM_GL_REGISTER_AQCTLB_AQCTLB2);	
    EPWM_setActionQualifierShadowLoadMode(INV_HPWM_BASE, EPWM_ACTION_QUALIFIER_B, EPWM_AQ_LOAD_ON_CNTR_PERIOD);	
    EPWM_setActionQualifierAction(INV_HPWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(INV_HPWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(INV_HPWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(INV_HPWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(INV_HPWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(INV_HPWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setDeadBandDelayPolarity(INV_HPWM_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);	
    EPWM_setDeadBandDelayMode(INV_HPWM_BASE, EPWM_DB_RED, true);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(INV_HPWM_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_setRisingEdgeDelayCount(INV_HPWM_BASE, 100);	
    EPWM_setDeadBandDelayMode(INV_HPWM_BASE, EPWM_DB_FED, true);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(INV_HPWM_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_setFallingEdgeDelayCount(INV_HPWM_BASE, 100);	
    EPWM_enableInterrupt(INV_HPWM_BASE);	
    EPWM_setInterruptSource(INV_HPWM_BASE, EPWM_INT_TBCTR_PERIOD);	
    EPWM_setInterruptEventCount(INV_HPWM_BASE, 1);	
    EPWM_enableInterruptEventCountInit(INV_HPWM_BASE);	
    EPWM_enableADCTrigger(INV_HPWM_BASE, EPWM_SOC_A);	
    EPWM_setADCTriggerSource(INV_HPWM_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_PERIOD);	
    EPWM_setADCTriggerEventPrescale(INV_HPWM_BASE, EPWM_SOC_A, 1);	
    EPWM_enableADCTriggerEventCountInit(INV_HPWM_BASE, EPWM_SOC_A);	
    EPWM_forceADCTriggerEventCountInit(INV_HPWM_BASE, EPWM_SOC_A);	
    EPWM_enableGlobalLoad(INV_LPWM_BASE);	
    EPWM_setGlobalLoadTrigger(INV_LPWM_BASE, EPWM_GL_LOAD_PULSE_CNTR_PERIOD);	
    EPWM_setGlobalLoadEventPrescale(INV_LPWM_BASE, 1);	
    EPWM_setupEPWMLinks(INV_LPWM_BASE, EPWM_LINK_WITH_EPWM_1, EPWM_LINK_GLDCTL2);	
    EPWM_setClockPrescaler(INV_LPWM_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(INV_LPWM_BASE, 2500);	
    EPWM_setupEPWMLinks(INV_LPWM_BASE, EPWM_LINK_WITH_EPWM_1, EPWM_LINK_TBPRD);	
    EPWM_setTimeBaseCounter(INV_LPWM_BASE, 0);	
    EPWM_setTimeBaseCounterMode(INV_LPWM_BASE, EPWM_COUNTER_MODE_UP);	
    EPWM_enablePhaseShiftLoad(INV_LPWM_BASE);	
    EPWM_setPhaseShift(INV_LPWM_BASE, 1);	
    EPWM_setCounterCompareValue(INV_LPWM_BASE, EPWM_COUNTER_COMPARE_A, 1250);	
    EPWM_enableGlobalLoadRegisters(INV_LPWM_BASE, EPWM_GL_REGISTER_CMPA_CMPAHR);	
    EPWM_setCounterCompareShadowLoadMode(INV_LPWM_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_PERIOD);	
    EPWM_setupEPWMLinks(INV_LPWM_BASE, EPWM_LINK_WITH_EPWM_2, EPWM_LINK_COMP_A);	
    EPWM_setCounterCompareValue(INV_LPWM_BASE, EPWM_COUNTER_COMPARE_B, 1250);	
    EPWM_enableGlobalLoadRegisters(INV_LPWM_BASE, EPWM_GL_REGISTER_CMPB_CMPBHR);	
    EPWM_setCounterCompareShadowLoadMode(INV_LPWM_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_PERIOD);	
    EPWM_setupEPWMLinks(INV_LPWM_BASE, EPWM_LINK_WITH_EPWM_2, EPWM_LINK_COMP_B);	
    EPWM_enableGlobalLoadRegisters(INV_LPWM_BASE, EPWM_GL_REGISTER_AQCTLA_AQCTLA2);	
    EPWM_setActionQualifierShadowLoadMode(INV_LPWM_BASE, EPWM_ACTION_QUALIFIER_A, EPWM_AQ_LOAD_ON_CNTR_PERIOD);	
    EPWM_setActionQualifierAction(INV_LPWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(INV_LPWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(INV_LPWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(INV_LPWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(INV_LPWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(INV_LPWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_enableGlobalLoadRegisters(INV_LPWM_BASE, EPWM_GL_REGISTER_AQCTLB_AQCTLB2);	
    EPWM_setActionQualifierShadowLoadMode(INV_LPWM_BASE, EPWM_ACTION_QUALIFIER_B, EPWM_AQ_LOAD_ON_CNTR_PERIOD);	
    EPWM_setActionQualifierAction(INV_LPWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(INV_LPWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(INV_LPWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(INV_LPWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(INV_LPWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(INV_LPWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setDeadBandDelayPolarity(INV_LPWM_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);	
    EPWM_setDeadBandDelayMode(INV_LPWM_BASE, EPWM_DB_RED, true);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(INV_LPWM_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_setRisingEdgeDelayCount(INV_LPWM_BASE, 100);	
    EPWM_setDeadBandDelayMode(INV_LPWM_BASE, EPWM_DB_FED, true);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(INV_LPWM_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_setFallingEdgeDelayCount(INV_LPWM_BASE, 100);	
    EPWM_enableGlobalLoad(PuPu_PWM_BASE);	
    EPWM_setGlobalLoadEventPrescale(PuPu_PWM_BASE, 1);	
    EPWM_setupEPWMLinks(PuPu_PWM_BASE, EPWM_LINK_WITH_EPWM_6, EPWM_LINK_GLDCTL2);	
    EPWM_setEmulationMode(PuPu_PWM_BASE, EPWM_EMULATION_FREE_RUN);	
    EPWM_setClockPrescaler(PuPu_PWM_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_selectPeriodLoadEvent(PuPu_PWM_BASE, EPWM_SHADOW_LOAD_MODE_COUNTER_SYNC);	
    EPWM_setTimeBasePeriod(PuPu_PWM_BASE, 2500);	
    EPWM_setupEPWMLinks(PuPu_PWM_BASE, EPWM_LINK_WITH_EPWM_4, EPWM_LINK_TBPRD);	
    EPWM_enableGlobalLoadRegisters(PuPu_PWM_BASE, EPWM_GL_REGISTER_TBPRD_TBPRDHR);	
    EPWM_setTimeBaseCounter(PuPu_PWM_BASE, 0);	
    EPWM_setTimeBaseCounterMode(PuPu_PWM_BASE, EPWM_COUNTER_MODE_UP_DOWN);	
    EPWM_setCountModeAfterSync(PuPu_PWM_BASE, EPWM_COUNT_MODE_UP_AFTER_SYNC);	
    EPWM_enablePhaseShiftLoad(PuPu_PWM_BASE);	
    EPWM_setPhaseShift(PuPu_PWM_BASE, 1);	
    EPWM_setSyncInPulseSource(PuPu_PWM_BASE, EPWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM4);	
    EPWM_setSyncPulseSource(PuPu_PWM_BASE, HRPWM_PWMSYNC_SOURCE_ZERO);	
    EPWM_setCounterCompareValue(PuPu_PWM_BASE, EPWM_COUNTER_COMPARE_A, 50);	
    EPWM_enableGlobalLoadRegisters(PuPu_PWM_BASE, EPWM_GL_REGISTER_CMPA_CMPAHR);	
    EPWM_setCounterCompareShadowLoadMode(PuPu_PWM_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setupEPWMLinks(PuPu_PWM_BASE, EPWM_LINK_WITH_EPWM_6, EPWM_LINK_COMP_A);	
    EPWM_setCounterCompareValue(PuPu_PWM_BASE, EPWM_COUNTER_COMPARE_B, 2450);	
    EPWM_enableGlobalLoadRegisters(PuPu_PWM_BASE, EPWM_GL_REGISTER_CMPB_CMPBHR);	
    EPWM_setCounterCompareShadowLoadMode(PuPu_PWM_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setupEPWMLinks(PuPu_PWM_BASE, EPWM_LINK_WITH_EPWM_6, EPWM_LINK_COMP_B);	
    EPWM_disableCounterCompareShadowLoadMode(PuPu_PWM_BASE, EPWM_COUNTER_COMPARE_C);	
    EPWM_disableCounterCompareShadowLoadMode(PuPu_PWM_BASE, EPWM_COUNTER_COMPARE_D);	
    EPWM_enableGlobalLoadRegisters(PuPu_PWM_BASE, EPWM_GL_REGISTER_AQCTLA_AQCTLA2);	
    EPWM_setActionQualifierAction(PuPu_PWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(PuPu_PWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(PuPu_PWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(PuPu_PWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(PuPu_PWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(PuPu_PWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_enableGlobalLoadRegisters(PuPu_PWM_BASE, EPWM_GL_REGISTER_AQCTLB_AQCTLB2);	
    EPWM_setActionQualifierAction(PuPu_PWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(PuPu_PWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(PuPu_PWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(PuPu_PWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(PuPu_PWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(PuPu_PWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(PuPu_PWM_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(PuPu_PWM_BASE);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(PuPu_PWM_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(PuPu_PWM_BASE);	
    EPWM_enableGlobalLoad(Rec_PWM_BASE);	
    EPWM_setGlobalLoadEventPrescale(Rec_PWM_BASE, 1);	
    EPWM_setupEPWMLinks(Rec_PWM_BASE, EPWM_LINK_WITH_EPWM_6, EPWM_LINK_GLDCTL2);	
    EPWM_setEmulationMode(Rec_PWM_BASE, EPWM_EMULATION_FREE_RUN);	
    EPWM_setClockPrescaler(Rec_PWM_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_selectPeriodLoadEvent(Rec_PWM_BASE, EPWM_SHADOW_LOAD_MODE_COUNTER_SYNC);	
    EPWM_setTimeBasePeriod(Rec_PWM_BASE, 2500);	
    EPWM_setupEPWMLinks(Rec_PWM_BASE, EPWM_LINK_WITH_EPWM_4, EPWM_LINK_TBPRD);	
    EPWM_setTimeBaseCounter(Rec_PWM_BASE, 0);	
    EPWM_setTimeBaseCounterMode(Rec_PWM_BASE, EPWM_COUNTER_MODE_UP_DOWN);	
    EPWM_setCountModeAfterSync(Rec_PWM_BASE, EPWM_COUNT_MODE_UP_AFTER_SYNC);	
    EPWM_disablePhaseShiftLoad(Rec_PWM_BASE);	
    EPWM_setPhaseShift(Rec_PWM_BASE, 0);	
    EPWM_setSyncInPulseSource(Rec_PWM_BASE, EPWM_SYNC_IN_PULSE_SRC_DISABLE);	
    EPWM_enableSyncOutPulseSource(Rec_PWM_BASE, EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(Rec_PWM_BASE, EPWM_COUNTER_COMPARE_A, 50);	
    EPWM_enableGlobalLoadRegisters(Rec_PWM_BASE, EPWM_GL_REGISTER_CMPA_CMPAHR);	
    EPWM_setCounterCompareShadowLoadMode(Rec_PWM_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setupEPWMLinks(Rec_PWM_BASE, EPWM_LINK_WITH_EPWM_4, EPWM_LINK_COMP_A);	
    EPWM_setCounterCompareValue(Rec_PWM_BASE, EPWM_COUNTER_COMPARE_B, 2450);	
    EPWM_enableGlobalLoadRegisters(Rec_PWM_BASE, EPWM_GL_REGISTER_CMPB_CMPBHR);	
    EPWM_setCounterCompareShadowLoadMode(Rec_PWM_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setupEPWMLinks(Rec_PWM_BASE, EPWM_LINK_WITH_EPWM_4, EPWM_LINK_COMP_B);	
    EPWM_enableGlobalLoadRegisters(Rec_PWM_BASE, EPWM_GL_REGISTER_AQCTLA_AQCTLA2);	
    EPWM_setActionQualifierAction(Rec_PWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(Rec_PWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(Rec_PWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(Rec_PWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(Rec_PWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(Rec_PWM_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_enableGlobalLoadRegisters(Rec_PWM_BASE, EPWM_GL_REGISTER_AQCTLB_AQCTLB2);	
    EPWM_setActionQualifierAction(Rec_PWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(Rec_PWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(Rec_PWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(Rec_PWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(Rec_PWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(Rec_PWM_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(Rec_PWM_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(Rec_PWM_BASE);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(Rec_PWM_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(Rec_PWM_BASE);	
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
	
	// Interrupt Setings for INT_INV_HPWM
	Interrupt_register(INT_INV_HPWM, &INT_INV_HPWM_ISR);
	Interrupt_enable(INT_INV_HPWM);
}
//*****************************************************************************
//
// SYNC Scheme Configurations
//
//*****************************************************************************
void SYNC_init(){
	SysCtl_setSyncOutputConfig(SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT);
	//
	// SOCA
	//
	SysCtl_enableExtADCSOCSource(0);
	//
	// SOCB
	//
	SysCtl_enableExtADCSOCSource(0);
}
