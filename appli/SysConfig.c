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
#include "h\Cal_ADC_Max.h"
#include "h\EEprom\I2c_eeprom.h"


void SysConfig(void)
{
    SCI_init();
    EEprom_init();
    Cal_ADC_Max();
    Clr_ADC_Value();

}



void EEprom_init(void)
{
    //--- I2C Manual Init (bypass SysConfig GMUX bug on GPIO26) ---
    InitI2C();

    //--- Bus Recovery: release stuck SDA if needed ---
    if(I2caRegs.I2CSTR.bit.BB == 1)
    {
        I2C_BusRecovery();
    }

    //--- Initialize EEPROM data ---
    InitEEpromData();
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
