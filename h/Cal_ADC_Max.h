/*
 * Cal_ADC_Max.h
 *
 *  Created on: 2026/04/13
 *      Author: wujw
 */

#ifndef H_CAL_ADC_MAX_H_
#define H_CAL_ADC_MAX_H_


// ADC MAX values (calculated from EE_Set.Spec)
typedef struct
{
    float    f_Igrid;       // 30A fixed = 50.904
    float    f_Vgrid;       // Vout(max)*1.414*1.2
    float    f_Ibat;        // MaxChargeCurrent*1.2
    float    f_Io;          // Pow*2/Vout(min)*1.2
    float    f_IL;          // Pow*2/Vout(min)*1.5
    float    f_SavIo;       // 45W/Vout(min)*1.414
    float    f_Vbus;        // 300 or 600
    float    f_Vo;          // Vout(max)*1.414*1.2
    float    f_VBAT;        // Dcin(max)*1.2
}TY_ADC_Max;


extern  TY_ADC_Max ADC_Max;

extern void Cal_ADC_Max(void);


#endif /* H_CAL_ADC_MAX_H_ */
