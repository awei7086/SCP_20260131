/*
 * ADC.h
 *
 *  Created on: 2024�~7��9��
 *      Author: wujw
 */

#ifndef H_ADC_H_
#define H_ADC_H_


// ADCC - Low_sensor (Trigger: CPU Timer0)
typedef struct
{
    int      s16_Tbat;      // SOC1, C11, Pin24, NTC temperature (°C)
    int      s16_Tmos1;     // SOC2, C0,  Pin16, NTC temperature (°C)
    float    f_Reserver2;   // SOC3, C1,  Pin22
    float    f_Reserver3;   // SOC4, C4,  Pin15
    float    f_Reserver4;   // SOC5, C7,  Pin14
}TY_Low_sensor;


// Per-unit values (calibrated, range: -1.0 ~ 1.0)
typedef struct
{
    float    f_Igrid;
    float    f_Vgrid;
    float    f_Ibat;        // DC, no offset
    float    f_Io;
    float    f_IL;
    float    f_SavIo;
    float    f_Vbus;        // DC, no offset
    float    f_Vo;
    float    f_Vbat;        // DC, no offset
}TY_Pu_sensor;

typedef struct
{
    TY_Low_sensor   ADC_Low_Speed;
    TY_Pu_sensor    Pu;
}TY_st_Ad_Value;



extern  TY_st_Ad_Value st_Ad_Value;

extern void Clr_ADC_Value(void);
extern void Fast_speed_ADC_to_Pu(void);
extern void Low_speed_ADCRESULT_to_Reg(void);
extern int  TranTemp_NTC(int Temper);


#endif /* H_ADC_H_ */
