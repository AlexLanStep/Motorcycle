/*
 * Moment_work_2017.h
 *
 * Code generation for model "Moment_work_2017".
 *
 * Model version              : 1.25
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Thu Dec 23 14:11:11 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Moment_work_2017_h_
#define RTW_HEADER_Moment_work_2017_h_
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef Moment_work_2017_COMMON_INCLUDES_
# define Moment_work_2017_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* Moment_work_2017_COMMON_INCLUDES_ */

#include "Moment_work_2017_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  CMoment_Moment_work_2017_T obj;      /* '<Root>/MATLAB System4' */
  void *MATLABSystem4_PWORK;           /* '<Root>/MATLAB System4' */
  boolean_T objisempty;                /* '<Root>/MATLAB System4' */
} DW_Moment_work_2017_T;

/* Parameters (auto storage) */
struct P_Moment_work_2017_T_ {
  real_T Moment_Value;                 /* Expression: 600
                                        * Referenced by: '<Root>/Moment'
                                        */
  real_T MomentMin_Value;              /* Expression: 600
                                        * Referenced by: '<Root>/MomentMin'
                                        */
  real_T MomentMax_Value;              /* Expression: 6500
                                        * Referenced by: '<Root>/MomentMax'
                                        */
  real_T Acc_Value;                    /* Expression: 10
                                        * Referenced by: '<Root>/Acc '
                                        */
  real_T Constant4_Value;              /* Expression: 100
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T uDLookupTable_tableData[256]; /* Expression: [0.0000000000000000	7.6928601264953613	17.1857147216796870	26.3999996185302730	37.2428703308105470	47.8285865783691410	62.8499984741210940	83.4214019775390630	104.849998474121090     198.9795837402343700    257.1428527832031200	385.7142944335937500	420.0000000000000000	450.0000000000000000	669.0000000000000000	699.0000000000000000;
                                          0.0000000000000000	6.1071400642395020	14.7000007629394530	22.6071395874023440	32.4642906188964840	42.5142898559570310	54.5999984741210940	70.7786026000976560	90.5999984741210940	174.5204315185546900	238.7754974365234400	372.8570861816406200	366.0000000000000000	415.7142944335937500	627.0000000000000000	666.0000000000000000;
                                          0.0000000000000000	4.9285702705383301	12.5357151031494140	20.3785705566406250	29.7214317321777340	39.3214187622070310	51.1928482055664060	67.1143035888671880	85.6286010742187500	165.7040710449218700	223.1632995605468700	366.0000000000000000	411.4285888671875000	445.7142944335937500	663.0000000000000000	696.0000000000000000;
                                          0.0000000000000000	3.8785710334777832	11.4214296340942380	18.6857147216796880	27.8142852783203130	37.0499992370605470	48.7285804748535160	64.6714019775390630	81.9000015258789060	158.0816497802734400	205.4387817382812500	362.1429138183593700	407.1429138183593700	443.5714111328125000	660.0000000000000000	693.0000000000000000;
                                          0.0000000000000000	3.4714291095733643	10.1999998092651370	17.3571395874023440	26.1000003814697270	35.0571289062500000	46.5642890930175780	62.3357009887695310	79.4142990112304690	150.5816497802734400	197.0204315185546900	359.1429138183593700	402.8570861816406200	441.4285888671875000	657.0000000000000000	690.0000000000000000;
                                          0.0000000000000000	3.0428578853607178	9.6428604125976562	16.2642898559570310	24.7071456909179690	33.4071311950683590	44.7642898559570310	60.6213989257812500	77.3357009887695310	145.6837158203125000	190.3775634765625000	344.1429138183593800	398.5714111328125000	439.2857055664062500	654.0000000000000000	687.0000000000000000;
                                          0.0000000000000000	2.2928578853607178	9.0214300155639648	15.4071397781372070	23.7857151031494140	31.8214225769042970	43.2642898559570310	58.9928550720214840	75.7928466796875000	141.9795684814453100	185.0204315185546900	339.0000000000000000	387.5571899414062500	437.1429138183593700	651.0000000000000000	684.0000000000000000;
                                          0.0000000000000000	2.0785710811614990	8.5285701751708984	14.7000007629394530	22.6071395874023440	30.6642875671386720	42.2142868041992190	57.8142967224121090	74.2928466796875000	139.0102233886718700	181.4081420898437500	336.4285888671875000	385.9285888671875000	435.0000000000000000	648.0000000000000000	681.0000000000000000;
                                          0.0000000000000000	1.9500000476837158	8.1428604125976563	13.8857145309448240	22.0071392059326170	30.1071300506591800	41.3357086181640630	56.8499946594238280	73.4356994628906250	136.4387817382812500	177.8571472167968700	334.7142944335937500	384.3428039550781200	432.8570861816406200	645.0000000000000000	678.0000000000000000;
                                          0.0000000000000000	2.0999999046325684	7.8642854690551758	13.8428602218627930	21.3214302062988280	29.0357151031494140	40.6071281433105470	56.0142974853515630	72.5142974853515630	133.8367156982421900	174.2142791748046900	332.5714111328125000	381.4285888671875000	430.8857116699218700	642.0000000000000000	675.0000000000000000;
                                          0.0000000000000000	2.3357129096984863	8.1428604125976563	13.8000001907348630	20.9142856597900390	28.3285694122314450	39.9428710937500000	55.2000007629394530	71.7428512573242190	130.3162841796875000	169.1327056884765600	327.6429138183593700	378.2142944335937500	429.2142944335937500	639.5999755859375000	669.0000000000000000;
                                          0.0000000000000000	2.5285708904266357	7.5642852783203125	13.3714303970336910	20.3785705566406250	27.7500000000000000	38.7857131958007810	54.1071510314941410	70.0928497314453130	128.4795684814453100	165.2448577880859400	321.8570861816406200	374.5714111328125000	425.4428100585937500	632.5800170898437500	663.0000000000000000;
                                          0.0000000000000000	2.8714289665222168	7.8000001907348633	13.3500003814697270	20.1000003814697270	27.2357158660888670	38.3571281433105470	53.5499992370605470	69.6213989257812500	127.0407867431640600	162.5509948730468700	318.6429138183593700	370.9285888671875000	420.0427856445312500	622.0800170898437500	654.0000000000000000;
                                          0.0000000000000000	3.4928579330444336	8.1642847061157227	13.5000000000000000	19.9928607940673830	27.1285705566406250	37.9285736083984380	53.2500000000000000	69.6213989257812500	126.3979949951171900	161.5102233886718700	315.0000000000000000	366.4285888671875000	413.8713989257812500	609.1799926757812500	642.0000000000000000;
                                          0.0000000000000000	4.0714297294616699	9.2142848968505859	13.9285688400268550	19.8214302062988280	26.7857151031494140	37.5000000000000000	52.5000000000000000	68.7856979370117190	125.2041397094726600	160.7142791748046900	309.0000000000000000	358.7142944335937500	399.1286010742187500	579.9600219726562500	600.0000000000000000;
                                          0.0000000000000000	4.2857131958007812	9.0000000000000000	13.7571401596069340	19.6499996185302730	26.2714252471923830	37.0071296691894530	51.8143005371093750	68.1213989257812500	123.5204315185546900	158.8469238281250000	303.2142944335937500	351.6429138183593700	377.2713928222656200	537.9000244140625000	540.0000000000000000]
                                        * Referenced by: '<Root>/2-D Lookup Table'
                                        */
  real_T uDLookupTable_bp01Data[16];   /* Expression:  [600 1000 1250 1500 1750 2000 2250 2500 2750 3000 3500 4000 4500 5000 5750 6500]
                                        * Referenced by: '<Root>/2-D Lookup Table'
                                        */
  real_T uDLookupTable_bp02Data[16];   /* Expression: [0 5.004882813 9.997558594 15.00244141 19.99511719 25 30.00488281 34.99755859 40.00244141 44.99511719 50 59.99755859 69.99511719 80.00488281 90.00244141 100]
                                        * Referenced by: '<Root>/2-D Lookup Table'
                                        */
  real_T CanError_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/CanError'
                                        */
  uint32_T uDLookupTable_maxIndex[2];  /* Computed Parameter: uDLookupTable_maxIndex
                                        * Referenced by: '<Root>/2-D Lookup Table'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Moment_work_2017_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Moment_work_2017_T Moment_work_2017_P;

/* Block states (auto storage) */
extern DW_Moment_work_2017_T Moment_work_2017_DW;

/* Model entry point functions */
extern void Moment_work_2017_initialize(void);
extern void Moment_work_2017_step(void);
extern void Moment_work_2017_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Moment_work_2017_T *const Moment_work_2017_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Moment_work_2017'
 */
#endif                                 /* RTW_HEADER_Moment_work_2017_h_ */