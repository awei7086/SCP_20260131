/*
 * ADC.c
 *
 *  Created on: 2024嚙羯7嚙踝蕭9嚙踝蕭
 *      Author: wujw
 */

#include "f28002x_device.h"
#include "h\ADC.h"
#include "h\MovAvg.h"
#include "h\SysConfig.h"
#include "h\Cal_ADC_Max.h"
#include "h\EEprom\EE_Set.h"


#define Q22  (1.0f / 4194304.0f)     // 1/2^22 = 1/(2048*2048), for AC (with offset)
#define Q23  (1.0f / 8388608.0f)     // 1/2^23 = 1/(2048*4096), for DC (no offset)

TY_MovAvg8  MovAvg_VOL = MOV_AVG8_DEFAULT;

TY_st_Ad_Value st_Ad_Value;


void Clr_ADC_Value(void)
{
    // Pu values
    st_Ad_Value.Pu.f_Igrid = 0;
    st_Ad_Value.Pu.f_Vgrid = 0;
    st_Ad_Value.Pu.f_Ibat  = 0;
    st_Ad_Value.Pu.f_Io    = 0;
    st_Ad_Value.Pu.f_IL    = 0;
    st_Ad_Value.Pu.f_SavIo = 0;
    st_Ad_Value.Pu.f_Vbus  = 0;
    st_Ad_Value.Pu.f_Vo    = 0;
    st_Ad_Value.Pu.f_Vbat  = 0;
    st_Ad_Value.ADC_Low_Speed.s16_Tbat = 25;
    st_Ad_Value.ADC_Low_Speed.s16_Tmos1 = 25;
}




void Fast_speed_ADC_to_Pu(void)
{
    // AC Pu values (range: -1.0 ~ 1.0)
    st_Ad_Value.Pu.f_Igrid = ((float)AdcaResultRegs.ADCRESULT0 - (float)EE_Set.u16_Offset.Igrid)
                           * (float)EE_Set.u16_Gain.Igrid * Q22;
    st_Ad_Value.Pu.f_Vgrid = ((float)AdcaResultRegs.ADCRESULT1 - (float)EE_Set.u16_Offset.Vgrid)
                           * (float)EE_Set.u16_Gain.Vgrid * Q22;
    st_Ad_Value.Pu.f_Io    = ((float)AdcaResultRegs.ADCRESULT3 - (float)EE_Set.u16_Offset.Io)
                           * (float)EE_Set.u16_Gain.Io    * Q22;
    st_Ad_Value.Pu.f_IL    = ((float)AdcaResultRegs.ADCRESULT4 - (float)EE_Set.u16_Offset.IL)
                           * (float)EE_Set.u16_Gain.IL    * Q22;
    st_Ad_Value.Pu.f_SavIo = ((float)AdcaResultRegs.ADCRESULT5 - (float)EE_Set.u16_Offset.SavIo)
                           * (float)EE_Set.u16_Gain.SavIo * Q22;
    st_Ad_Value.Pu.f_Vo    = ((float)AdcaResultRegs.ADCRESULT7 - (float)EE_Set.u16_Offset.Vo)
                           * (float)EE_Set.u16_Gain.Vo    * Q22;

    // DC Pu values (range: 0 ~ 1.0, no offset)
    st_Ad_Value.Pu.f_Ibat  = (float)AdcaResultRegs.ADCRESULT2
                           * (float)EE_Set.u16_Gain.Ibat  * Q23;
    st_Ad_Value.Pu.f_Vbus  = (float)AdcaResultRegs.ADCRESULT6
                           * (float)EE_Set.u16_Gain.Vbus  * Q23;
    st_Ad_Value.Pu.f_Vbat  = (float)AdcaResultRegs.ADCRESULT8
                           * (float)EE_Set.u16_Gain.VBAT  * Q23;
}



//=============================================================================
// TranTemp_NTC
//   TTC05104JSY (100K NTC) + 56.2K pull-up + 3.3V
//   Input : 10-bit ADC value (12-bit >> 2)
//   Output: temperature (°C)
//=============================================================================
int TranTemp_NTC(int Temper)
{
    //                       -30   -20   -10     0    10    20    30    40    50    60    70
    static const int adc[] = {987, 969, 930, 847, 782, 697, 601, 482, 356, 269, 204};
    static const int slp[] = {  0, 177,  82,  38,  49,  37,  33,  26,  25,  36,  49};
    static const int tmp[] = {-300,-200,-100,   0, 100, 200, 300, 400, 500, 600, 700};
    int i;

    if(Temper > adc[0]) return tmp[0] / 10;        // < -30°C clamp

    for(i = 1; i < 11; i++)
    {
        if(Temper > adc[i])
            return (((adc[i] - Temper) * slp[i] >> 5) + tmp[i]) / 10;
    }

    return (((adc[10] - Temper) * slp[10] >> 5) + tmp[10]) / 10;   // > 70°C
}


void Low_speed_ADCRESULT_to_Reg(void)
{//period 1msec
    // ADCC SOC1~SOC2 (Trigger: CPU Timer0) - NTC temperature
    st_Ad_Value.ADC_Low_Speed.s16_Tbat     = TranTemp_NTC(AdccResultRegs.ADCRESULT1 >> 2);  // C11, Pin24
    st_Ad_Value.ADC_Low_Speed.s16_Tmos1    = TranTemp_NTC(AdccResultRegs.ADCRESULT2 >> 2);  // C0,  Pin16

    // ADCC SOC3~SOC5 (Trigger: CPU Timer0)
    st_Ad_Value.ADC_Low_Speed.f_Reserver2  = (float)AdccResultRegs.ADCRESULT3;  // C1,  Pin22
    st_Ad_Value.ADC_Low_Speed.f_Reserver3  = (float)AdccResultRegs.ADCRESULT4;  // C4,  Pin15
    st_Ad_Value.ADC_Low_Speed.f_Reserver4  = (float)AdccResultRegs.ADCRESULT5;  // C7,  Pin14
}


