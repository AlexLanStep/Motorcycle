/*
 * Model_01_work_2017_contr.h
 *
 * Code generation for model "Model_01_work_2017_contr".
 *
 * Model version              : 1.25
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Mon Dec 20 08:13:08 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Model_01_work_2017_contr_h_
#define RTW_HEADER_Model_01_work_2017_contr_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef Model_01_work_2017_contr_COMMON_INCLUDES_
# define Model_01_work_2017_contr_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* Model_01_work_2017_contr_COMMON_INCLUDES_ */

#include "Model_01_work_2017_contr_types.h"

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

/* Block signals for system '<Root>/MATLAB System2' */
typedef struct {
  real_T b[3072];
  real_T MATLABSystem2_o1;             /* '<Root>/MATLAB System2' */
  real_T MATLABSystem2_o2;             /* '<Root>/MATLAB System2' */
} B_MATLABSystem2_Model_01_work_T;

/* Block states (auto storage) for system '<Root>/MATLAB System2' */
typedef struct {
  WolchSimCode_Model_01_work_20_T obj; /* '<Root>/MATLAB System2' */
  void *MATLABSystem2_PWORK;           /* '<Root>/MATLAB System2' */
  boolean_T objisempty;                /* '<Root>/MATLAB System2' */
} DW_MATLABSystem2_Model_01_wor_T;

/* Block signals (auto storage) */
typedef struct {
  B_MATLABSystem2_Model_01_work_T MATLABSystem;/* '<Root>/MATLAB System' */
  B_MATLABSystem2_Model_01_work_T MATLABSystem1;/* '<Root>/MATLAB System1' */
  B_MATLABSystem2_Model_01_work_T MATLABSystem2;/* '<Root>/MATLAB System2' */
} B_Model_01_work_2017_contr_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  ModulSigmoid_Model_01_work_20_T obj; /* '<Root>/MATLAB System3' */
  void *MATLABSystem3_PWORK;           /* '<Root>/MATLAB System3' */
  boolean_T objisempty;                /* '<Root>/MATLAB System3' */
  DW_MATLABSystem2_Model_01_wor_T MATLABSystem;/* '<Root>/MATLAB System' */
  DW_MATLABSystem2_Model_01_wor_T MATLABSystem1;/* '<Root>/MATLAB System1' */
  DW_MATLABSystem2_Model_01_wor_T MATLABSystem2;/* '<Root>/MATLAB System2' */
} DW_Model_01_work_2017_contr_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T YawAcc;                       /* '<Root>/YawAcc' */
  real_T YawVel;                       /* '<Root>/YawVel' */
  real_T RollVel;                      /* '<Root>/RollVel' */
  real_T Belt;                         /* '<Root>/Belt' */
  real_T Rotv;                         /* '<Root>/Rotv' */
} ExtU_Model_01_work_2017_contr_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T NotStatic;                    /* '<Root>/NotStatic' */
  real_T YawAccNoNorm;                 /* '<Root>/YawAccNoNorm' */
  real_T YawVelNoNorm;                 /* '<Root>/YawVelNoNorm' */
  real_T RollVelNoNorm;                /* '<Root>/RollVelNoNorm' */
} ExtY_Model_01_work_2017_contr_T;

/* Parameters for system: '<Root>/MATLAB System2' */
struct P_MATLABSystem2_Model_01_work_T_ {
  real_T MATLABSystem2_kMul;           /* Expression: 100
                                        * Referenced by: '<Root>/MATLAB System2'
                                        */
};

/* Parameters (auto storage) */
struct P_Model_01_work_2017_contr_T_ {
  real_T MATLABSystem3_Rwheel;         /* Expression: 17*0.0254
                                        * Referenced by: '<Root>/MATLAB System3'
                                        */
  real_T MATLABSystem3_Transfer;       /* Expression: 3
                                        * Referenced by: '<Root>/MATLAB System3'
                                        */
  real_T MATLABSystem3_Kreset;         /* Expression: 0.6
                                        * Referenced by: '<Root>/MATLAB System3'
                                        */
  real_T MATLABSystem3_sd;             /* Expression: 6
                                        * Referenced by: '<Root>/MATLAB System3'
                                        */
  real_T MATLABSystem3_sdsn;           /* Expression: 0.25
                                        * Referenced by: '<Root>/MATLAB System3'
                                        */
  real_T MATLABSystem3_betta;          /* Expression: 0.6
                                        * Referenced by: '<Root>/MATLAB System3'
                                        */
  real_T MATLABSystem3_sm_bet;         /* Expression: 0.3
                                        * Referenced by: '<Root>/MATLAB System3'
                                        */
  real_T MATLABSystem3_alfa;           /* Expression: 1.0
                                        * Referenced by: '<Root>/MATLAB System3'
                                        */
  real_T MATLABSystem3_sm_alfa;        /* Expression: 0.3
                                        * Referenced by: '<Root>/MATLAB System3'
                                        */
  real_T MATLABSystem3_kStd;           /* Expression: 4
                                        * Referenced by: '<Root>/MATLAB System3'
                                        */
  real_T MATLABSystem3_alfaExp;        /* Expression: 0.75
                                        * Referenced by: '<Root>/MATLAB System3'
                                        */
  real_T YawAccNormKoef_Value;         /* Expression: 380
                                        * Referenced by: '<Root>/YawAccNormKoef'
                                        */
  real_T YawVelNormKoef_Value;         /* Expression: 5
                                        * Referenced by: '<Root>/YawVelNormKoef'
                                        */
  real_T RollVelNormKoef_Value;        /* Expression: 5
                                        * Referenced by: '<Root>/RollVelNormKoef'
                                        */
  P_MATLABSystem2_Model_01_work_T MATLABSystem;/* '<Root>/MATLAB System' */
  P_MATLABSystem2_Model_01_work_T MATLABSystem1;/* '<Root>/MATLAB System1' */
  P_MATLABSystem2_Model_01_work_T MATLABSystem2;/* '<Root>/MATLAB System2' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Model_01_work_2017_co_T {
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
extern P_Model_01_work_2017_contr_T Model_01_work_2017_contr_P;

/* Block signals (auto storage) */
extern B_Model_01_work_2017_contr_T Model_01_work_2017_contr_B;

/* Block states (auto storage) */
extern DW_Model_01_work_2017_contr_T Model_01_work_2017_contr_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_Model_01_work_2017_contr_T Model_01_work_2017_contr_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Model_01_work_2017_contr_T Model_01_work_2017_contr_Y;

/* Model entry point functions */
extern void Model_01_work_2017_contr_initialize(void);
extern void Model_01_work_2017_contr_step(void);
extern void Model_01_work_2017_contr_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Model_01_work_2017_c_T *const Model_01_work_2017_contr_M;

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
 * '<Root>' : 'Model_01_work_2017_contr'
 */
#endif                                 /* RTW_HEADER_Model_01_work_2017_contr_h_ */
