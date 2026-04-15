/*
 * SI_Set.c
 *
 *  Created on: 2026/04/09
 *      Author: wujw
 */

#include "h\EEprom\SI_Set.h"

TY_st_SI_Set SI_Set;

//=============================================================================
// SI_Set_Back_Def
// Load default values from technical document (FUNC 0~28)
//=============================================================================
void SI_Set_Back_Def(void)
{
    //--- Bat_Protect (FUNC 0~7) ---
    SI_Set.Bat_Protect.u16_BOVP       = 1700;   // FUNC0   Battery OVP Limit
    SI_Set.Bat_Protect.u16_BOVR       = 100;    // FUNC1   Battery OVP Recovery
    SI_Set.Bat_Protect.u16_BUVP       = 1050;   // FUNC2   Battery UVP Limit
    SI_Set.Bat_Protect.u16_BUVR       = 200;    // FUNC3   Battery UVP Recovery
    SI_Set.Bat_Protect.u16_BUVALARM   = 1050;   // FUNC4   Battery UV Alarm
    SI_Set.Bat_Protect.u16_BHVCI      = 1700;   // FUNC5   High Battery Cut IN
    SI_Set.Bat_Protect.u16_BLVCI      = 680;    // FUNC6   Low Battery Cut IN
    SI_Set.Bat_Protect.u16_DelayBUVP  = 10;     // FUNC7   Battery UVP delay time

    //--- Cha_Set (FUNC 8~17) ---
    SI_Set.Cha_Set.u16_CusVbulk   = 1410;  // FUNC8   Custom set Bulk vol
    SI_Set.Cha_Set.u16_CusVabs    = 1410;  // FUNC9   Custom set ABS vol
    SI_Set.Cha_Set.u16_CusVfloat  = 1360;  // FUNC10  Custom set Float vol
    SI_Set.Cha_Set.u16_CusVequ    = 1410;  // FUNC11  Custom set Equalize vol
    SI_Set.Cha_Set.u16_CusVrecha  = 1250;  // FUNC12  Custom set Recharge vol
    SI_Set.Cha_Set.u16_Tbulk      = 0;     // FUNC13  Bulk Max charging Time
    SI_Set.Cha_Set.u16_Tabs       = 20;    // FUNC14  ABS Max charging Time
    SI_Set.Cha_Set.u16_MaxChaRate = 80;    // FUNC15  max charging rate
    SI_Set.Cha_Set.u16_Equ_Time   = 0;     // FUNC16  Equalize Off
    SI_Set.Cha_Set.u16_Force_Ch   = 0;     // FUNC17  Force mode Disable

    //--- Bat_Set (FUNC 18~19) ---
    SI_Set.Bat_Set.u16_BatType = 2;     // FUNC18  AGM1
    SI_Set.Bat_Set.u16_BatAH   = 200;   // FUNC19  200AH

    //--- Grid_Protect (FUNC 20~25) ---
    SI_Set.Grid_Protect.u16_GOVP   = 1400;  // FUNC20  Grid OVP Limit
    SI_Set.Grid_Protect.u16_GOVPR  = 50;    // FUNC21  Grid OVP Recovery
    SI_Set.Grid_Protect.u16_GUVP   = 650;   // FUNC22  Grid UVP Limit
    SI_Set.Grid_Protect.u16_GUVPR  = 50;    // FUNC23  Grid UVP Recovery
    SI_Set.Grid_Protect.u16_GHVCI  = 1400;  // FUNC24  High Grid Cut IN
    SI_Set.Grid_Protect.u16_GLVCI  = 850;   // FUNC25  Low Grid Cut IN

    //--- Inv_Set (FUNC 22~25) ---
    SI_Set.Inv_Set.u16_VoSett     = 3;     // FUNC22  120V
    SI_Set.Inv_Set.u16_FreqSett   = 1;     // FUNC23  60Hz
    SI_Set.Inv_Set.u16_FrLoLimit  = 53;    // FUNC24  Grid freq low limit
    SI_Set.Inv_Set.u16_FrHiLimit  = 67;    // FUNC25  Grid freq high limit

    //--- Saving_Set (FUNC 26~27) ---
    SI_Set.Saving_Set.u16_Tsearch  = 25;   // FUNC26  Searching Time
    SI_Set.Saving_Set.u16_SavTout  = 0;    // FUNC27  Saving shut down delay

    //--- ID_Set (FUNC 28) ---
    SI_Set.ID_Set.u16_ID = 0;              // FUNC28  GoPower charger mode ID
}
