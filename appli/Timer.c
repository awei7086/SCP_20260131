/*
 * Timer.c
 *
 *  Created on: 2026/04/15
 *      Author: wujw
 *
 *  Timer base: called from CPU Timer0 ISR (20KHz / 50us)
 *
 *  Timing chain:
 *    20 x 50us  = 1ms    → int1msec
 *     5 x 1ms   = 5ms    → int5msec
 *    20 x 5ms   = 100ms  → int100msec
 *    10 x 100ms = 1sec   → int1sec
 *    60 x 1sec  = 1min   → int1min
 */

#include "h\Timer.h"

TY_TimeReg TimeReg;

static unsigned int T1msecCou   = 0;
static unsigned int T5msecCou   = 0;
static unsigned int T100msecCou = 0;
static unsigned int T1secCou    = 0;
static unsigned int T1minCou    = 0;


void Time_Counter(void)
{
    //--- 1msec (20 x 50us) ---
    if(T1msecCou < 19)  { T1msecCou++; return; }

    T1msecCou = 0;
    TimeReg.Tflag.bit.int1msec = 1;

    //--- 5msec (5 x 1ms) ---
    if(T5msecCou < 4)   { T5msecCou++; return; }

    T5msecCou = 0;
    TimeReg.Tflag.bit.int5msec = 1;

    //--- 100msec (20 x 5ms) ---
    if(T100msecCou < 19) { T100msecCou++; return; }

    T100msecCou = 0;
    TimeReg.Tflag.bit.int100msec = 1;

    //--- 1sec (10 x 100ms) ---
    if(T1secCou < 9)     { T1secCou++; return; }

    T1secCou = 0;
    TimeReg.Tflag.bit.int1sec = 1;

    //--- 1min (60 x 1sec) ---
    if(T1minCou < 59)    { T1minCou++; return; }

    T1minCou = 0;
    TimeReg.Tflag.bit.int1min = 1;
}
