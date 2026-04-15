/*
 * PuRec.c
 *
 *  Created on: 2026¦~3¤ë30¤é
 *      Author: wujw
 */
#include "f28002x_device.h"
#include "device\device.h"
#include "h\PuRec.h"

TY_DC2DC PuPu;
void PuPu_Off(void)
{
    EALLOW;
        EPwm6Regs.AQCSFRC.bit.CSFA=1;
        EPwm6Regs.AQCSFRC.bit.CSFB=1;

        EPwm6Regs.CMPA.bit.CMPA = 0;
        EPwm6Regs.CMPB.bit.CMPB = 0;
    EDIS;
}

void PuPu_On(void)
{
    EALLOW;
        EPwm6Regs.AQCSFRC.bit.CSFA=0;
        EPwm6Regs.AQCSFRC.bit.CSFB=0;
    EDIS;

}

void Rec_Off(void)
{
    EALLOW;
        EPwm4Regs.AQCSFRC.bit.CSFA=1;
        EPwm4Regs.AQCSFRC.bit.CSFB=1;

        EPwm4Regs.CMPA.bit.CMPA = 0;
        EPwm4Regs.CMPB.bit.CMPB = 0;
    EDIS;
}

void Rec_On(void)
{
    EALLOW;
        EPwm4Regs.AQCSFRC.bit.CSFA=0;
        EPwm4Regs.AQCSFRC.bit.CSFB=0;
    EDIS;
}

void PuPu_SoftStart(void)
{
         if(PuPu.f_Buf < f_Duty_Min)     PuPu.f_Buf = f_Duty_Min;
    else if(PuPu.f_Buf > f_Duty_Max)     PuPu.f_Buf = f_Duty_Max;
    else                                 PuPu.f_Buf = PuPu.f_Buf + f_Duty_Delta;

     PuPu.u16_CMPA = (f_Duty_Center - PuPu.f_Buf) * PuRec_PWM_TBPRD;
     PuPu.u16_CMPB = (f_Duty_Center + PuPu.f_Buf) * PuRec_PWM_TBPRD;

}
