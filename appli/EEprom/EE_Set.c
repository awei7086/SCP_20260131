/*
 * EE_Set.c
 *
 *  Created on: 2026/04/09
 *      Author: wujw
 */

#include "h\EEprom\EE_Set.h"

TY_st_EE_Set EE_Set;

//=============================================================================
// EE_Set_Back_Def
// Load default values from technical document (FUNC 100~122)
//=============================================================================
void EE_Set_Back_Def(void)
{
    //--- Spec (FUNC 100~102) ---
    EE_Set.Spec.ACout   = 1200;     // FUNC100  120.0Vac
    EE_Set.Spec.DCin    = 1200;     // FUNC101  12.00V
    EE_Set.Spec.Watt    = 2000;     // FUNC102  2000W

    //--- u16_Gain (FUNC 103~112) ---
    EE_Set.u16_Gain.Vgrid   = 2048; // FUNC103
    EE_Set.u16_Gain.Igrid   = 2048; // FUNC104
    EE_Set.u16_Gain.Vo      = 2048; // FUNC105
    EE_Set.u16_Gain.Io      = 2048; // FUNC106
    EE_Set.u16_Gain.IL      = 2048; // FUNC107
    EE_Set.u16_Gain.SavIo   = 2048; // FUNC108
    EE_Set.u16_Gain.VBAT    = 2048; // FUNC109
    EE_Set.u16_Gain.ExVbat  = 2048; // FUNC110
    EE_Set.u16_Gain.Ibat    = 2048; // FUNC111
    EE_Set.u16_Gain.Vbus    = 2048; // FUNC112

    //--- u16_Offset (FUNC 113~122) ---
    EE_Set.u16_Offset.Vgrid   = 2048; // FUNC113
    EE_Set.u16_Offset.Igrid   = 2048; // FUNC114
    EE_Set.u16_Offset.Vo      = 2048; // FUNC115
    EE_Set.u16_Offset.Io      = 2048; // FUNC116
    EE_Set.u16_Offset.IL      = 2048; // FUNC117
    EE_Set.u16_Offset.SavIo   = 2048; // FUNC118
    EE_Set.u16_Offset.VBAT    = 2048; // FUNC119
    EE_Set.u16_Offset.ExVbat  = 2048; // FUNC120
    EE_Set.u16_Offset.Ibat    = 2048; // FUNC121
    EE_Set.u16_Offset.Vbus    = 2048; // FUNC122
}
