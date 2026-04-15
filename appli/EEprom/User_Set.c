/*
 * User_Set.c
 *
 *  Created on: 2026/04/09
 *      Author: wujw
 */

#include "h\EEprom\User_Set.h"

TY_st_User_Set User_Set;

//=============================================================================
// User_Set_Back_Def
// Load default values from technical document (FUNC 50~53)
//=============================================================================
void User_Set_Back_Def(void)
{
    User_Set.u16_IgSet      = 300;  // FUNC50  Ig Limit 30.0A
    User_Set.u16_Night_On   = 0;    // FUNC51  night mode Off
    User_Set.u16_Psav       = 5;    // FUNC52  Psav Limit 5W
    User_Set.u16_MuteAlarm  = 0;    // FUNC53  Mute Alarm Off
}
