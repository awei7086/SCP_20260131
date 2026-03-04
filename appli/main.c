//#############################################################################

//#############################################################################
//
// Included Files
//
#include <math.h>
#include "f28002x_device.h"
#include "driverlib.h"
#include "device\device.h"
#include "board.h"
#include "c2000ware_libraries.h"
#include "h\SysConfig.h"
#include "h\ADC.h"

/*
#include "h\Charger.h"
#include "h\Timer.h"
#include "h\RS232.h"
#include "h\PID.h"
#include "h\Compensation.h"
#include "h\DrPWM.h"
#include "h\Protection.h"
#include "h\FanControl.h"
#include "h\PWM.h"

extern en_ChaCtr_Stage ChaCtr_Stage;

__interrupt void INT_myCPUTIMER0_ISR(void);
__interrupt void INT_myCPUTIMER1_ISR(void);
__interrupt void sciaRxFifoIsr(void);
*/
void main(void)
{

    //memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t)&RamfuncsLoadSize);
    //
    // Initialize device clock and peripherals
    //
    Device_init();

    //
    // Disable pin locks and enable internal pull-ups.
    //
    Device_initGPIO();

    //
    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    //
    Interrupt_initModule();

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();




/*
    //設定TripZone
    EPWM_setTripZoneAction(EPWM2_BASE, EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_LOW);
    EPWM_setTripZoneAction(EPWM2_BASE, EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_LOW);

    EPWM_setTripZoneAction(EPWM3_BASE, EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_LOW);
    EPWM_setTripZoneAction(EPWM3_BASE, EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_LOW);

    //disable PWM
    Dis_PWM();
*/




    //
    // PinMux and Peripheral Initialization
    //
    Board_init();
    //EPwm6Regs.AQCSFRC.bit.CSFA=1;
    //EPwm6Regs.AQCSFRC.bit.CSFB=1;

    //
    // C2000Ware Library initialization
    //
    C2000Ware_libraries_init();





    SysConfig();

/*
    Interrupt_register(INT_SCIA_RX, &sciaRxFifoIsr);
    Interrupt_enable(INT_SCIA_RX);
*/
    CPUTimer_startTimer(CPUTIMER0_BASE);

/*
    CPUTimer_startTimer(CPUTIMER1_BASE);


    //Enable PWM
    En_PWM();

*/

    EALLOW;
    EPwm2Regs.TZCLR.all = 0xFF;      // 清除TZ殘留旗標
    EDIS;
    //
    // Enable Global Interrupt (INTM) and real time interrupt (DBGM)
    //
    EINT;
    ERTM;






    while(1)
    {


    }
}



float wt = 0.0f;
float f = 60.0f;        // 60Hz
float Ts = 0.00005f;    // 20kHz ISR
float Sinwt = 0;
int Duty=0;
unsigned int TimeDelay=0;
unsigned int ShotDown=0;

__interrupt void INT_INV_HPWM_ISR(void)
{

    GpioDataRegs.GPBTOGGLE.bit.GPIO40=1;


    wt += 2.0f * 3.1415926f * f * Inv_PWM_Ts; // 2*pi*f*t
    if(wt >= 2.0f * 3.1415926f)
    {
        wt -= 2.0f * 3.1415926f;
        GpioDataRegs.GPATOGGLE.bit.GPIO14 = 1;


    }

    Sinwt = sinf(wt);   // -1 ~ +1



    if( Sinwt < 0)
    {
        EALLOW;
        EPwm1Regs.CMPA.bit.CMPA = (Sinwt + 1.0f) * INV_PWM_TBPRD;
        EPwm2Regs.CMPA.bit.CMPA = 0;
        EDIS;
    }
    else
    {
        EALLOW;
        EPwm1Regs.CMPA.bit.CMPA = Sinwt  * INV_PWM_TBPRD;
        EPwm2Regs.CMPA.bit.CMPA = INV_PWM_TBPRD+1;
        EDIS;
    }



    EPwm1Regs.ETCLR.bit.INT = 1;
    PieCtrlRegs.PIEACK.all = INTERRUPT_ACK_GROUP3;
}














__interrupt void INT_myCPUTIMER0_ISR(void)
{//20KHz (50usec)

    /*

    CpuTimer0Regs.TCR.bit.TIF = 1;      //中斷嵌套 (interrupt nesting)


    Fast_speed_ADCRESULT_to_Reg();



    theta += 2.0f * 3.1415926f * f * Ts;
    if(theta >= 2.0f * 3.1415926f)
    {
        theta -= 2.0f * 3.1415926f;
        GpioDataRegs.GPATOGGLE.bit.GPIO14 = 1;


    }

    sine = sinf(theta);   // -1 ~ +1



    if( sine < 0)
    {
        EALLOW;
        EPwm1Regs.CMPA.bit.CMPA = (sine + 1.0f) * 2500;
        EPwm2Regs.CMPA.bit.CMPA = 0;
        EDIS;
    }
    else
    {
        EALLOW;
        EPwm1Regs.CMPA.bit.CMPA = sine  * 2500;
        EPwm2Regs.CMPA.bit.CMPA = 2501;
        EDIS;
    }

 //   EPwm2Regs.CMPA.bit.CMPA = EPwm1Regs.CMPA.bit.CMPA;
//    EPwm2Regs.CMPA.bit.CMPA = (sine  * 25000) +2500;


    TimeDelay++;
    if(TimeDelay >= 250)
    {
        TimeDelay = 0;
        if(Duty<=1200)   Duty++;

        EPwm6Regs.AQCSFRC.bit.CSFA=0;
        EPwm6Regs.AQCSFRC.bit.CSFB=0;

        EALLOW;
        EPwm4Regs.CMPA.bit.CMPA = 1250-Duty;
        EPwm4Regs.CMPB.bit.CMPB = 1250+Duty;

        EPwm6Regs.CMPA.bit.CMPA = 1250-Duty;
        EPwm6Regs.CMPB.bit.CMPB = 1250+Duty;
        EDIS;



    }
*/


/*
    ChaCompPara.Go_Rescue = Off; //for test

    if(ChaCompPara.Go_Rescue == On)
    {
        BB2SB_Compensation();

        BB2SB_DrivePWM();

        ChaCtr_Stage = PerCh;           //設定PerCh mode, 準備結束 rescue 進入 SB2BB_Compensation()

        Clr_SB2BB_Vbank_Loop();
        Clr_SB2BB_Vstart_Loop();
        Clr_SB2BB_Cur_Loop();
    }
    else
    {
        SB2BB_Compensation();

        SB2BB_DrivePWM();

        Clr_BB2SB_SV_Loop();
        Clr_BB2SB_SI_Loop();
    }
*/



    //EINT;                                         //中斷嵌套 (interrupt nesting) disable EINT
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);  //中斷嵌套 (interrupt nesting)
}


/*

__interrupt void INT_myCPUTIMER1_ISR(void)
{//1kHz (1msec)
    CpuTimer1Regs.TCR.bit.TIF = 1;                      //中斷嵌套 (interrupt nesting)

    TimeReg.Tflag.bit.int1msec = 1;

    EINT;                                               //中斷嵌套 (interrupt nesting) disable EINT
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);  //中斷嵌套 (interrupt nesting)
}


__interrupt void sciaRxFifoIsr(void)
{

    unsigned int TempPIEIER;
    TempPIEIER = PieCtrlRegs.PIEIER9.all; // Save PIEIER register for later
    IER |= M_INT3;                         // Set global priority by adjusting IER
    IER &= M_INT3;
                                            // Set group priority by adjusting PIEIER(only self group) to allow INTX.X to interrupt current ISR
    PieCtrlRegs.PIEACK.all = 0xFFFF;      // Enable PIE interrupts
    asm("       NOP");                    // Wait one cycle
    EINT;                                 // Clear INTM to enable interrupts
    //
    // Insert ISR Code here.......
    // for now just insert a delay
    //


        SysFlag_1.bit.GoUartRX=1;
        SciReceive();
        SysFlag_1.bit.GoUartRX=0;



    SciaRegs.SCIFFRX.bit.RXFFINTCLR=1;   // Clear Interrupt flag

    //
    // Restore registers saved:
    //
    DINT;
    PieCtrlRegs.PIEIER9.all = TempPIEIER;
}

__interrupt void INT_TZ_ISR(void)
{
    //EALLOW;
    //    EPwm2Regs.TZCLR.all = 0xff;         // 清中斷旗標
    //EDIS;


    CT_OCP_Flag = 1;

    DINT;                                           //中斷嵌套 (interrupt nesting)
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP2);
}
*/
