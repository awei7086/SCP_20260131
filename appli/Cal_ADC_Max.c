/*
 * Cal_ADC_Max.c
 *
 *  Created on: 2026/04/13
 *      Author: wujw
 */

#include "h\Cal_ADC_Max.h"
#include "h\EEprom\EE_Set.h"

TY_ADC_Max ADC_Max;


//=============================================================================
// DCin max voltage lookup (V)
//   12V: 16.50V, 24V: 33.00V, 48V: 66.00V
//=============================================================================
static float Get_DCin_Max(unsigned int DCin)
{
    switch(DCin)
    {
        case 2400: return 33.00f;
        case 4800: return 66.00f;
        default:   return 16.50f;   // 1200
    }
}

//=============================================================================
// Max charging current (A)
//   Base: 50A @ 1000W/12V, scale by Watt and DCin
//   Formula: 50 * (Watt/1000) * (12/DCin)
//=============================================================================
static float Get_MaxChargeCurrent(unsigned int Watt, unsigned int DCin)
{
    float dcin_v = (float)DCin / 100.0f;
    return 50.0f * ((float)Watt / 1000.0f) * (12.0f / dcin_v);
}

//=============================================================================
// Vout(min): low voltage region=100V, high voltage region=200V
//=============================================================================
static float Get_Vout_Min(unsigned int ACout)
{
    return (ACout <= 1200) ? 100.0f : 200.0f;
}

//=============================================================================
// Cal_ADC_Max
//   Calculate ADC MAX values from EE_Set.Spec (ACout/DCin/Watt)
//   Called after InitEEpromData() loads settings from EEPROM
//=============================================================================
void Cal_ADC_Max(void)
{
    float ACout_v    = (float)EE_Set.Spec.ACout / 10.0f;
    float Watt       = (float)EE_Set.Spec.Watt;
    float Vout_min   = Get_Vout_Min(EE_Set.Spec.ACout);
    float DCin_max_v = Get_DCin_Max(EE_Set.Spec.DCin);

    ADC_Max.f_Igrid = 50.904f;                             // 30A fixed
    ADC_Max.f_Vgrid = ACout_v * 1.414f * 1.2f;             // Vout(max)*1.414*1.2
    ADC_Max.f_Ibat  = Get_MaxChargeCurrent(EE_Set.Spec.Watt, EE_Set.Spec.DCin) * 1.2f;
    ADC_Max.f_Io    = Watt * 2.0f / Vout_min * 1.2f;       // Pow*2/Vout(min)*1.2
    ADC_Max.f_IL    = Watt * 2.0f / Vout_min * 1.5f;       // Pow*2/Vout(min)*1.5
    ADC_Max.f_SavIo = 45.0f / Vout_min * 1.414f;           // 45W/Vout(min)*1.414
    ADC_Max.f_Vbus  = (EE_Set.Spec.ACout <= 1200) ? 300.0f : 600.0f;
    ADC_Max.f_Vo    = ACout_v * 1.414f * 1.2f;             // Vout(max)*1.414*1.2
    ADC_Max.f_VBAT  = DCin_max_v * 1.2f;                   // Dcin(max)*1.2
}
