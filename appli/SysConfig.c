/*
 * SysConfig.c
 *
 *  Created on: 2025�~10��10��
 *      Author: wujw
 */

#include "f28002x_device.h"
#include "device\device.h"
#include "h\SysConfig.h"
#include "h\ADC.h"
#include "h\PuRec.h"
#include "h\I2c_eeprom.h"

/*
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


    EDIS;






    SCI_init();
    Init_Def_EE_Set();
    Clr_ADC_Value();
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
    //--- Bus Recovery: release stuck SDA if needed ---
    if(I2caRegs.I2CSTR.bit.BB == 1)
    {
        I2C_BusRecovery();
    }

    //--- Initialize EEPROM data ---
    InitEEpromData();
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
    DEVICE_DELAY_US(5000);              //delay 5msec�T�OADCí�w
    EALLOW;
    AdccRegs.ADCSOCFRC1.bit.SOC0 = 1;   //Ĳ�o SOC0 (LAYOUT NAME : DipSW)
    EDIS;

    DEVICE_DELAY_US(50);                //����50usec(Sample Time >90ns)
 */
    return(AdccResultRegs.ADCRESULT0);

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
