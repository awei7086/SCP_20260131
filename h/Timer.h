/*
 * Timer.h
 *
 *  Created on: 2026/04/15
 *      Author: wujw
 */

#ifndef H_TIMER_H_
#define H_TIMER_H_


typedef struct
{
    union
    {
        unsigned int ALL;
        struct
        {
            unsigned int int1msec   : 1;
            unsigned int int5msec   : 1;
            unsigned int int100msec : 1;
            unsigned int int1sec    : 1;
            unsigned int int1min    : 1;
            unsigned int            : 11;
        }bit;
    }Tflag;

}TY_TimeReg;


extern TY_TimeReg TimeReg;

extern void Time_Counter(void);


#endif /* H_TIMER_H_ */
