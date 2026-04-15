/*
 * User_Set.h
 *
 *  Created on: 2026/04/09
 *      Author: wujw
 */

#ifndef H_USER_SET_H_
#define H_USER_SET_H_


//=============================================================================
// User_Set (FUNC 50~53)
//=============================================================================
typedef struct
{
    unsigned int    u16_IgSet;      // FUNC50  def=300  Ig Limit (5.0~50.0A, 1div=10)
    unsigned int    u16_Night_On;   // FUNC51  def=0    night mode (0:Off 1:On)
    unsigned int    u16_Psav;       // FUNC52  def=5    Psav Limit (5W~50W, 0=OFF)
    unsigned int    u16_MuteAlarm;  // FUNC53  def=0    Mute Alarm (0:Off 1:On)

}TY_st_User_Set;

extern TY_st_User_Set User_Set;

extern void User_Set_Back_Def(void);

#endif /* H_USER_SET_H_ */
