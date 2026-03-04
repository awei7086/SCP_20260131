/*
 * ADC.h
 *
 *  Created on: 2024¦~7¤ë9¤é
 *      Author: wujw
 */

#ifndef H_ADC_H_
#define H_ADC_H_


typedef struct
{
    float    f_AMP_A;
    float    f_AMP_B;
    float    f_AMP_C;
    float    f_AMP;
    float    f_VOL_A;
    float    f_VOL_B;
    float    f_VOL_C;
    float    f_VOL;
    float    f_ACIN;

}TY_Fast_sensor;

typedef struct
{
    int             s16_NTC1;
    int             s16_NTC2;
}TY_Low_sensor;


typedef struct
{
    TY_Fast_sensor  ADC_Fast_Speed;
    TY_Low_sensor   ADC_Low_Speed;
}TY_st_Ad_Value;



extern  TY_st_Ad_Value st_Ad_Value;


extern void Clr_ADC_Value(void);
extern void Fast_speed_ADCRESULT_to_Reg(void);
extern void Low_speed_ADCRESULT_to_Reg(void);

extern int TranTemp_NTC(int Temper);

#endif /* H_ADC_H_ */
