/*
 * MixailFiltr.h
 *
 * Code generation for model "MixailFiltr".
 *
 * Model version              : 1.35
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Tue Jan 18 07:53:17 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MixailFiltr_h_
#define RTW_HEADER_MixailFiltr_h_
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef MixailFiltr_COMMON_INCLUDES_
# define MixailFiltr_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "stdlib.h"
#endif                                 /* MixailFiltr_COMMON_INCLUDES_ */

#include "MixailFiltr_types.h"

/* Shared type includes */
#include "multiword_types.h"
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

/* Block signals (auto storage) */
typedef struct {
  real_T DigitalFilter;                /* '<S1>/Digital Filter' */
} B_MixailFiltr_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SineWave_AccFreqNorm;         /* '<Root>/Sine Wave' */
  real_T DigitalFilter_FILT_STATES[4]; /* '<S1>/Digital Filter' */
  real_T RandomSource_STATE_DWORK[35]; /* '<Root>/Random Source' */
  struct {
    void *LoggedData[3];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  uint32_T RandomSource_SEED_DWORK;    /* '<Root>/Random Source' */
} DW_MixailFiltr_T;

/* Parameters (auto storage) */
struct P_MixailFiltr_T_ {
  real_T SineWave_Amplitude;           /* Mask Parameter: SineWave_Amplitude
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Frequency;           /* Mask Parameter: SineWave_Frequency
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T RandomSource_MaxVal;          /* Mask Parameter: RandomSource_MaxVal
                                        * Referenced by: '<Root>/Random Source'
                                        */
  real_T RandomSource_MinVal;          /* Mask Parameter: RandomSource_MinVal
                                        * Referenced by: '<Root>/Random Source'
                                        */
  real_T SineWave_Phase;               /* Mask Parameter: SineWave_Phase
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_MixailFiltr_T {
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
extern P_MixailFiltr_T MixailFiltr_P;

/* Block signals (auto storage) */
extern B_MixailFiltr_T MixailFiltr_B;

/* Block states (auto storage) */
extern DW_MixailFiltr_T MixailFiltr_DW;

/* Model entry point functions */
extern void MixailFiltr_initialize(void);
extern void MixailFiltr_step(void);
extern void MixailFiltr_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MixailFiltr_T *const MixailFiltr_M;

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
 * '<Root>' : 'MixailFiltr'
 * '<S1>'   : 'MixailFiltr/Digital Filter Design'
 * '<S2>'   : 'MixailFiltr/Digital Filter Design/Check Signal Attributes'
 */
#endif                                 /* RTW_HEADER_MixailFiltr_h_ */
