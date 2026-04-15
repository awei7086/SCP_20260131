/*
 * PuRec.h
 *
 *  Created on: 2026�~3��30��
 *      Author: wujw
 */

#ifndef H_PUREC_H_
#define H_PUREC_H_

#include "h\SysConfig.h"

#define PuRec_PWM_FREQ   60000UL
#define PuRec_PWM_TBPRD  SYSCLK_FREQ/(PuRec_PWM_FREQ*2)   // up/down counter = 833

#define Duty_Off  0
#define f_Duty_Center  0.5f
#define f_Duty_Min  0.1f
#define f_Duty_Max  0.45f
#define f_Duty_Delta  0.00001f




typedef struct
{
    float        f_Buf;
    unsigned int u16_CMPA;
    unsigned int u16_CMPB;

}TY_DC2DC;
extern  TY_DC2DC PuPu;






extern void PuPu_SoftStart(void);
extern void PuPu_Off(void);
extern void PuPu_On(void);
extern void Rec_Off(void);
extern void Rec_On(void);


#endif /* H_PUREC_H_ */
