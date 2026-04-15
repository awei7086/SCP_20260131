/*
 * SI_Set.h
 *
 *  Created on: 2026/04/09
 *      Author: wujw
 */

#ifndef H_SI_SET_H_
#define H_SI_SET_H_


//=============================================================================
// SI_Set.Bat_Protect (FUNC 0~7) - Battery protection
//=============================================================================
typedef struct
{
    unsigned int    u16_BOVP;       // FUNC0   def=1700  Battery OVP Limit
    unsigned int    u16_BOVR;       // FUNC1   def=100   Battery OVP Recovery
    unsigned int    u16_BUVP;       // FUNC2   def=1050  Battery UVP Limit
    unsigned int    u16_BUVR;       // FUNC3   def=200   Battery UVP Recovery
    unsigned int    u16_BUVALARM;   // FUNC4   def=1050  Battery UV Alarm
    unsigned int    u16_BHVCI;      // FUNC5   def=1700  High Battery Cut IN
    unsigned int    u16_BLVCI;      // FUNC6   def=680   Low Battery Cut IN
    unsigned int    u16_DelayBUVP;  // FUNC7   def=10    Battery UVP delay time

}TY_Bat_Protect;


//=============================================================================
// SI_Set.Cha_Set (FUNC 8~17) - Charging Set
//=============================================================================
typedef struct
{
    unsigned int    u16_CusVbulk;   // FUNC8   def=1410  Custom set Bulk vol
    unsigned int    u16_CusVabs;    // FUNC9   def=1410  Custom set ABS vol
    unsigned int    u16_CusVfloat;  // FUNC10  def=1360  Custom set Float vol
    unsigned int    u16_CusVequ;    // FUNC11  def=1410  Custom set Equalize vol
    unsigned int    u16_CusVrecha;  // FUNC12  def=1250  Custom set Recharge vol
    unsigned int    u16_Tbulk;      // FUNC13  def=0     Bulk Max charging Time(hour)
    unsigned int    u16_Tabs;       // FUNC14  def=20    ABS Max charging Time(hour)
    unsigned int    u16_MaxChaRate; // FUNC15  def=80    max charging rate
    unsigned int    u16_Equ_Time;   // FUNC16  def=0     Equalize On/Off (0:Off 1~4:1~4 hour)
    unsigned int    u16_Force_Ch;   // FUNC17  def=0     Force mode (0:Disable 1:Bulk 2:Float)

}TY_Cha_Set;


//=============================================================================
// SI_Set.Bat_Set (FUNC 18~19) - Battery Set
//=============================================================================
typedef struct
{
    unsigned int    u16_BatType;    // FUNC18  def=2   (0:GEl 1:Flooded 2:AGM1 3:AGM2 4:Custom 5:GP_LFP)
    unsigned int    u16_BatAH;      // FUNC19  def=200 Battery AH setting

}TY_Bat_Set;


//=============================================================================
// SI_Set.Grid_Protect (FUNC 20~25) - Grid protection
//=============================================================================
typedef struct
{
    unsigned int    u16_GOVP;       // FUNC20  def=1400  Grid OVP Limit
    unsigned int    u16_GOVPR;      // FUNC21  def=50    Grid OVP Recovery
    unsigned int    u16_GUVP;       // FUNC22  def=650   Grid UVP Limit
    unsigned int    u16_GUVPR;      // FUNC23  def=50    Grid UVP Recovery
    unsigned int    u16_GHVCI;      // FUNC24  def=1400  High Grid Cut IN
    unsigned int    u16_GLVCI;      // FUNC25  def=850   Low Grid Cut IN

}TY_Grid_Protect;


//=============================================================================
// SI_Set.Inv_Set (FUNC 22~25) - Inverter Set
//=============================================================================
typedef struct
{
    unsigned int    u16_VoSett;     // FUNC22  def=3   (0:100V 1:110V 2:115V 3:120V)
    unsigned int    u16_FreqSett;   // FUNC23  def=1   (0:50Hz 1:60Hz)
    unsigned int    u16_FrLoLimit;  // FUNC24  def=53  Grid frequency low level limit
    unsigned int    u16_FrHiLimit;  // FUNC25  def=67  Grid frequency high level limit

}TY_Inv_Set;


//=============================================================================
// SI_Set.Saving_Set (FUNC 26~27) - Saving Set
//=============================================================================
typedef struct
{
    unsigned int    u16_Tsearch;    // FUNC26  def=25  Searching Time (1~40=0.1~4.0sec)
    unsigned int    u16_SavTout;    // FUNC27  def=0   Saving mode shut down delay time

}TY_Saving_Set;


//=============================================================================
// SI_Set.ID_Set (FUNC 28) - System Set
//=============================================================================
typedef struct
{
    unsigned int    u16_ID;         // FUNC28  def=0   GoPower charger mode ID

}TY_ID_Set;


//=============================================================================
// SI_Set (FUNC 0~28)
//=============================================================================
typedef struct
{
    TY_Bat_Protect    Bat_Protect;    // FUNC0~7
    TY_Cha_Set        Cha_Set;        // FUNC8~17
    TY_Bat_Set        Bat_Set;        // FUNC18~19
    TY_Grid_Protect   Grid_Protect;   // FUNC20~25
    TY_Inv_Set        Inv_Set;        // FUNC22~25
    TY_Saving_Set     Saving_Set;     // FUNC26~27
    TY_ID_Set         ID_Set;         // FUNC28

}TY_st_SI_Set;

extern TY_st_SI_Set SI_Set;

extern void SI_Set_Back_Def(void);

#endif /* H_SI_SET_H_ */
