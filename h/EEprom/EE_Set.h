/*
 * EE_Set.h
 *
 *  Created on: 2026/04/09
 *      Author: wujw
 */

#ifndef H_EE_SET_H_
#define H_EE_SET_H_


//=============================================================================
// EESet.Spec (FUNC 100~102)
//=============================================================================
typedef struct
{
    unsigned int    ACout;      // FUNC100  def=1200  (100.0~240.0)
    unsigned int    DCin;       // FUNC101  def=1200  (12.00/24.00/48.00)
    unsigned int    Watt;       // FUNC102  def=2000  (1000/2000/3000)

}TY_Spec;


//=============================================================================
// EESet.u16_Gain  (FUNC 103~112)
// EESet.u16_Offset(FUNC 113~122)
//=============================================================================
typedef struct
{
    unsigned int    Vgrid;      // FUNC103/113  def=2048  grid voltage
    unsigned int    Igrid;      // FUNC104/114  def=2048  grid current
    unsigned int    Vo;         // FUNC105/115  def=2048  inverter output voltage
    unsigned int    Io;         // FUNC106/116  def=2048  inverter output current
    unsigned int    IL;         // FUNC107/117  def=2048  inductor current
    unsigned int    SavIo;      // FUNC108/118  def=2048  saving current
    unsigned int    VBAT;       // FUNC109/119  def=2048  internal battery voltage
    unsigned int    ExVbat;     // FUNC110/120  def=2048  external battery voltage
    unsigned int    Ibat;       // FUNC111/121  def=2048  battery current
    unsigned int    Vbus;       // FUNC112/122  def=2048  bus voltage

}TY_Tune;


//=============================================================================
// EESet  (FUNC 100~122)
//=============================================================================
typedef struct
{
    TY_Spec   Spec;             // FUNC100~102
    TY_Tune   u16_Gain;         // FUNC103~112
    TY_Tune   u16_Offset;       // FUNC113~122

}TY_st_EE_Set;

extern TY_st_EE_Set EE_Set;

extern void EE_Set_Back_Def(void);

#endif /* H_EE_SET_H_ */
