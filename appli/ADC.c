/*
 * ADC.c
 *
 *  Created on: 2024年7月9日
 *      Author: wujw
 */

#include "f28002x_device.h"
#include "h\ADC.h"
#include "h\MovAvg.h"
#include <math.h>
#include "h\SysConfig.h"
//#include "h\Compensation.h"

#define Q24 16777216
#define Q23 8388608

TY_MovAvg8  MovAvg_AMP_A = MOV_AVG8_DEFAULT;
TY_MovAvg8  MovAvg_AMP_B = MOV_AVG8_DEFAULT;
TY_MovAvg8  MovAvg_AMP_C = MOV_AVG8_DEFAULT;

TY_MovAvg8  MovAvg_VOL_A = MOV_AVG8_DEFAULT;
TY_MovAvg8  MovAvg_VOL_B = MOV_AVG8_DEFAULT;
TY_MovAvg8  MovAvg_VOL_C = MOV_AVG8_DEFAULT;

TY_MovAvg8  MovAvg_VOL = MOV_AVG8_DEFAULT;

TY_st_Ad_Value st_Ad_Value;
TY_st_EE_Set EE_Set;

void Clr_ADC_Value(void)
{
    //clear Fast speed AD sensor
    st_Ad_Value.ADC_Fast_Speed.f_AMP_A = 0;
    st_Ad_Value.ADC_Fast_Speed.f_AMP_B = 0;
    st_Ad_Value.ADC_Fast_Speed.f_AMP_C = 0;
    st_Ad_Value.ADC_Fast_Speed.f_AMP = 0;
    st_Ad_Value.ADC_Fast_Speed.f_VOL_A = 0;
    st_Ad_Value.ADC_Fast_Speed.f_VOL_B = 0;
    st_Ad_Value.ADC_Fast_Speed.f_VOL_C = 0;
    st_Ad_Value.ADC_Fast_Speed.f_VOL = 0;
    st_Ad_Value.ADC_Fast_Speed.f_ACIN = 0;

    //clear Low speed AD sensor
    st_Ad_Value.ADC_Low_Speed.s16_NTC1 = 0;
    st_Ad_Value.ADC_Low_Speed.s16_NTC2 = 0;
}


float s16_Temp=0;

void Fast_speed_ADCRESULT_to_Reg(void)
{

    MovAvg_AMP_A.input = (float)AdcaResultRegs.ADCRESULT0 * EE_Set.AD_Gain.u16_AMP_A / Q24;
    MOV_AVG8_MACRO(MovAvg_AMP_A);
    st_Ad_Value.ADC_Fast_Speed.f_AMP_A = MovAvg_AMP_A.output;

    MovAvg_AMP_B.input = (float)AdcaResultRegs.ADCRESULT1 * EE_Set.AD_Gain.u16_AMP_B / Q24;
    MOV_AVG8_MACRO(MovAvg_AMP_B);
    st_Ad_Value.ADC_Fast_Speed.f_AMP_B = MovAvg_AMP_B.output;

    MovAvg_AMP_C.input = (float)AdcaResultRegs.ADCRESULT2 * EE_Set.AD_Gain.u16_AMP_C / Q24;
    MOV_AVG8_MACRO(MovAvg_AMP_C);
    st_Ad_Value.ADC_Fast_Speed.f_AMP_C = MovAvg_AMP_C.output;

    MovAvg_VOL_A.input = (float)AdcaResultRegs.ADCRESULT5 * EE_Set.AD_Gain.u16_VOL_A / Q24;
    MOV_AVG8_MACRO(MovAvg_VOL_A);
    st_Ad_Value.ADC_Fast_Speed.f_VOL_A = MovAvg_VOL_A.output;

    MovAvg_VOL_B.input = (float)AdcaResultRegs.ADCRESULT6 * EE_Set.AD_Gain.u16_VOL_B / Q24;
    MOV_AVG8_MACRO(MovAvg_VOL_B);
    st_Ad_Value.ADC_Fast_Speed.f_VOL_B = MovAvg_VOL_B.output;

    MovAvg_VOL_C.input = (float)AdcaResultRegs.ADCRESULT7 * EE_Set.AD_Gain.u16_VOL_C / Q24;
    MOV_AVG8_MACRO(MovAvg_VOL_C);
    st_Ad_Value.ADC_Fast_Speed.f_VOL_C = MovAvg_VOL_C.output;

    MovAvg_VOL.input = (float)AdcaResultRegs.ADCRESULT4 * EE_Set.AD_Gain.u16_VOL / Q24;
    MOV_AVG8_MACRO(MovAvg_VOL);
    st_Ad_Value.ADC_Fast_Speed.f_VOL = MovAvg_VOL.output;

    //計算rms (float)AdcaResultRegs.ADCRESULT10 * EE_Set.AD_Gain.u16_VOL / Q24;
}


unsigned int u16_WaitAdcStableCou=0;
void Low_speed_ADCRESULT_to_Reg(void)
{//period 1msec


    st_Ad_Value.ADC_Low_Speed.s16_NTC1 = TranTemp_NTC(AdccResultRegs.ADCRESULT8>>2);    //only used 10bit (0~1024)
    st_Ad_Value.ADC_Low_Speed.s16_NTC2 = TranTemp_NTC(AdccResultRegs.ADCRESULT9>>2);    //only used 10bit (0~1024)

}


int TranTemp_NTC(int Temper)
{
    int RetTemp=0;
    /*此轉換表適用於 TbatAD & TevirAD
    ------------------------------------------------------------------------------------
    Temp        oC                          RetTemp
    ------------------------------------------------------------------------------------
    1024                    -30oC>RetTemp           (((987-Temper)*86)>>5)-300
    ------------------------------------------------------------------------------------
    987         -30         -30oC<RetTemp<-20oC     (((969-Temper)*177)>>5)-200
    ------------------------------------------------------------------------------------
    969         -20         -20oC<RetTemp<-10oC     (((930-Temper)*82)>>5)-100
    ------------------------------------------------------------------------------------
    930         -10         -10oC<RetTemp<0oC       (((847-Temper)*38)>>5)
    ------------------------------------------------------------------------------------
    847         0           0oC<RetTemp<10oC        (((782-Temper)*49)>>5)+100
    ------------------------------------------------------------------------------------
    782          10         10oC<RetTemp<20oC       (((697-Temper)*37)>>5)+200
    ------------------------------------------------------------------------------------
    697          20         20oC<RetTemp<30oC       (((601-Temper)*33)>>5)+300
    ------------------------------------------------------------------------------------
    601          30         30oC<RetTemp<40oC       (((482-Temper)*26)>>5)+400
    ------------------------------------------------------------------------------------
    482          40         40oC<RetTemp<50oC       (((356-Temper)*25)>>5)+500
    ------------------------------------------------------------------------------------
    356          50         50oC<RetTemp<60oC       (((269-Temper)*36)>>5)+600
    ------------------------------------------------------------------------------------
    269          60         60oC<RetTemp<70oC       (((204-Temper)*49)>>5)+700
    ------------------------------------------------------------------------------------
    204         70          RetTemp<70oC            700
    ------------------------------------------------------------------------------------
    */
            if(Temper>987)      RetTemp=-300;                           //Temper<-30
        else if(Temper>969)     RetTemp=(((969-Temper)*177)>>5)-200;    //-30<Temper<-20
        else if(Temper>930)     RetTemp=(((930-Temper)*82)>>5)-100;     //-20<Temper<-10
        else if(Temper>847)     RetTemp=(((847-Temper)*38)>>5);         //-10<Temper<0
        else if(Temper>782)     RetTemp=(((782-Temper)*49)>>5)+100;     //0<Temper<10
        else if(Temper>697)     RetTemp=(((697-Temper)*37)>>5)+200;     //10<Temper<20
        else if(Temper>601)     RetTemp=(((601-Temper)*33)>>5)+300;     //20<Temper<30
        else if(Temper>482)     RetTemp=(((482-Temper)*26)>>5)+400;     //30<Temper<40
        else if(Temper>356)     RetTemp=(((356-Temper)*25)>>5)+500;     //40<Temper<50
        else if(Temper>269)     RetTemp=(((269-Temper)*36)>>5)+600;     //50<Temper<60
        else if(Temper>204)     RetTemp=(((204-Temper)*49)>>5)+700;     //60<Temper<70
        else if(Temper<=204)    RetTemp=(((204-Temper)*49)>>5)+700;     //70<Temper

        return(RetTemp/10); //不取小數點
}


