#ifndef __MovAvg_H__
#define __MovAvg_H__



/***************************************************************************************
 Function             : MOV_AVG2_MACRO
 Input                 : none
 Output               :  none
 Description          :

 ****************************************************************************************/
typedef struct  {  float input;
                   float data1;
                   float data2;
                   float output;
                 }TY_MovAvg2;



#define MOV_AVG2_DEFAULT {  0,\
                            0,\
                            0,\
                            0,\
                         }

#define MOV_AVG2_MACRO(v)               \
     v.data2 = v.data1;                 \
     v.data1 = v.input;                 \
     v.output= (v.data1+v.data2)*0.5;   \



/***************************************************************************************
 Function             : MOV_AVG4_MACRO
 Input                 : none
 Output               :  none
 Description          :

****************************************************************************************/

typedef struct  {  float input;
                   float data1;
                   float data2;
                   float data3;
                   float data4;
                   float output;
                 }TY_MovAvg4;



#define MOV_AVG4_DEFAULT {  0,\
                            0,\
                            0,\
                            0,\
                            0,\
                            0,\
                         }

#define MOV_AVG4_MACRO(v)                   \
        v.data4 = v.data3;                  \
        v.data3 = v.data2;                  \
        v.data2 = v.data1;                  \
        v.data1 = v.input;                  \
        v.output= (v.data1+v.data2+v.data3+v.data4)*0.25;   \


 /***************************************************************************************
  Function             : MOV_AVG8_MACRO
  Input                : none
  Output               : none
  Description          :

 ****************************************************************************************/

 typedef struct {  float input;
                   float data1;
                   float data2;
                   float data3;
                   float data4;
                   float data5;
                   float data6;
                   float data7;
                   float data8;
                   float output;
                 }TY_MovAvg8;

#define MOV_AVG8_DEFAULT {  0,\
                            0,\
                            0,\
                            0,\
                            0,\
                            0,\
                            0,\
                            0,\
                            0,\
                            0,\
                         }

#define MOV_AVG8_MACRO(v)                   \
        v.data8 = v.data7;                  \
        v.data7 = v.data6;                  \
        v.data6 = v.data5;                  \
        v.data5 = v.data4;                  \
        v.data4 = v.data3;                  \
        v.data3 = v.data2;                  \
        v.data2 = v.data1;                  \
        v.data1 = v.input;                  \
        v.output= (v.data1+v.data2+v.data3+v.data4+v.data5+v.data6+v.data7+v.data8)*0.125;\




#endif // __MovAvg_H__

