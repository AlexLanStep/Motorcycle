/*
 * Moment_BASA_2017.h
 *
 * Code generation for model "Moment_BASA_2017".
 *
 * Model version              : 1.26
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Fri Jan 14 15:39:42 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Moment_BASA_2017_h_
#define RTW_HEADER_Moment_BASA_2017_h_
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef Moment_BASA_2017_COMMON_INCLUDES_
# define Moment_BASA_2017_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* Moment_BASA_2017_COMMON_INCLUDES_ */

#include "Moment_BASA_2017_types.h"

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
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T FromWorkspace;                /* '<Root>/From Workspace' */
} B_Moment_BASA_2017_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  CMoment_Moment_BASA_2017_T obj;      /* '<Root>/MATLAB System4' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace_PWORK;               /* '<Root>/From Workspace' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  void *MATLABSystem4_PWORK;           /* '<Root>/MATLAB System4' */
  struct {
    int_T PrevIndex;
  } FromWorkspace_IWORK;               /* '<Root>/From Workspace' */

  boolean_T objisempty;                /* '<Root>/MATLAB System4' */
} DW_Moment_BASA_2017_T;

/* Parameters (auto storage) */
struct P_Moment_BASA_2017_T_ {
  real_T nPoint_Value;                 /* Expression: 50
                                        * Referenced by: '<Root>/nPoint'
                                        */
  real_T nPoint1_Value;                /* Expression: 20
                                        * Referenced by: '<Root>/nPoint1'
                                        */
  real_T nPoint2_Value;                /* Expression: 200
                                        * Referenced by: '<Root>/nPoint2'
                                        */
  real_T CanError_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/CanError'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Moment_BASA_2017_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Moment_BASA_2017_T Moment_BASA_2017_P;

/* Block signals (auto storage) */
extern B_Moment_BASA_2017_T Moment_BASA_2017_B;

/* Block states (auto storage) */
extern DW_Moment_BASA_2017_T Moment_BASA_2017_DW;

/* Model entry point functions */
extern void Moment_BASA_2017_initialize(void);
extern void Moment_BASA_2017_step(void);
extern void Moment_BASA_2017_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Moment_BASA_2017_T *const Moment_BASA_2017_M;

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
 * '<Root>' : 'Moment_BASA_2017'
 */
#endif                                 /* RTW_HEADER_Moment_BASA_2017_h_ */
