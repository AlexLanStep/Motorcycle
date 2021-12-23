/*
 * Moment_work_2017.c
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

#include "Moment_work_2017.h"
#include "Moment_work_2017_private.h"

/* Block states (auto storage) */
DW_Moment_work_2017_T Moment_work_2017_DW;

/* Real-time model */
RT_MODEL_Moment_work_2017_T Moment_work_2017_M_;
RT_MODEL_Moment_work_2017_T *const Moment_work_2017_M = &Moment_work_2017_M_;

/* Model step function */
void Moment_work_2017_step(void)
{
  /*  Implement algorithm. Calculate y as a function of input u and */
  /*  discrete states. */

  /* Matfile logging */
  rt_UpdateTXYLogVars(Moment_work_2017_M->rtwLogInfo,
                      (&Moment_work_2017_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(Moment_work_2017_M)!=-1) &&
        !((rtmGetTFinal(Moment_work_2017_M)-Moment_work_2017_M->Timing.taskTime0)
          > Moment_work_2017_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Moment_work_2017_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Moment_work_2017_M->Timing.clockTick0)) {
    ++Moment_work_2017_M->Timing.clockTickH0;
  }

  Moment_work_2017_M->Timing.taskTime0 = Moment_work_2017_M->Timing.clockTick0 *
    Moment_work_2017_M->Timing.stepSize0 +
    Moment_work_2017_M->Timing.clockTickH0 *
    Moment_work_2017_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Moment_work_2017_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Moment_work_2017_M, 0,
                sizeof(RT_MODEL_Moment_work_2017_T));
  rtmSetTFinal(Moment_work_2017_M, -1);
  Moment_work_2017_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    Moment_work_2017_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Moment_work_2017_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Moment_work_2017_M->rtwLogInfo, (NULL));
    rtliSetLogT(Moment_work_2017_M->rtwLogInfo, "tout");
    rtliSetLogX(Moment_work_2017_M->rtwLogInfo, "");
    rtliSetLogXFinal(Moment_work_2017_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Moment_work_2017_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Moment_work_2017_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Moment_work_2017_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Moment_work_2017_M->rtwLogInfo, 1);
    rtliSetLogY(Moment_work_2017_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Moment_work_2017_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Moment_work_2017_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&Moment_work_2017_DW, 0,
                sizeof(DW_Moment_work_2017_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Moment_work_2017_M->rtwLogInfo, 0.0,
    rtmGetTFinal(Moment_work_2017_M), Moment_work_2017_M->Timing.stepSize0,
    (&rtmGetErrorStatus(Moment_work_2017_M)));

  {
    static const uint16_T tmp[16] = { 600U, 1000U, 1250U, 1500U, 1750U, 2000U,
      2250U, 2500U, 2750U, 3000U, 3500U, 4000U, 4500U, 5000U, 57500U, 65000U };

    static const real_T tmp_0[64] = { 0.0, 35.9, 80.2, 123.2, 0.0, 28.5, 68.6,
      105.5, 0.0, 23.0, 58.5, 95.1, 0.0, 18.1, 53.3, 87.2, 0.0, 16.2, 47.0, 81.0,
      0.0, 14.2, 45.0, 75.9, 0.0, 10.7, 42.1, 71.9, 0.0, 9.7, 39.8, 68.6, 0.0,
      9.1, 38.0, 64.8, 0.0, 9.8, 36.7, 64.6, 0.0, 10.9, 38.0, 64.4, 0.0, 11.8,
      35.3, 62.4, 0.0, 13.4, 36.4, 62.3, 0.0, 16.3, 38.1, 63.0, 0.0, 19.0, 43.0,
      65.0, 0.0, 20.0, 42.0, 64.2 };

    int32_T i;

    /* Start for MATLABSystem: '<Root>/MATLAB System4' */
    for (i = 0; i < 16; i++) {
      Moment_work_2017_DW.obj.X[i] = tmp[i];
    }

    Moment_work_2017_DW.obj.Y[0] = 0.0;
    Moment_work_2017_DW.obj.Y[1] = 5.0049;
    Moment_work_2017_DW.obj.Y[2] = 9.9976;
    Moment_work_2017_DW.obj.Y[3] = 15.0024;
    memcpy(&Moment_work_2017_DW.obj.Z[0], &tmp_0[0], sizeof(real_T) << 6U);
    Moment_work_2017_DW.obj.isInitialized = 0;
    Moment_work_2017_DW.objisempty = true;
    Moment_work_2017_DW.obj.isInitialized = 1;

    /* End of Start for MATLABSystem: '<Root>/MATLAB System4' */
    /*  Validate related or interdependent property values */
    /*         %% Advanced functions */
    /*  Validate inputs to the step method at initialization */
    /*  Untitled2 Add summary here */
    /*  */
    /*  NOTE: When renaming the class name Untitled2, the file name */
    /*  and constructor name must be updated to use the class name. */
    /*  */
    /*  This template includes most, but not all, possible properties, */
    /*  attributes, and methods that you can implement for a System object. */
    /*  Public, tunable properties */
    /*  Public, non-tunable properties */
    /*  Pre-computed constants */
    /*  Constructor */
    /*  Support name-value pair arguments when constructing object */
    /*         %% Common functions */
    /*  Perform one-time calculations, such as computing constants */
  }
}

/* Model terminate function */
void Moment_work_2017_terminate(void)
{
  /* Start for MATLABSystem: '<Root>/MATLAB System4' incorporates:
   *  Terminate for MATLABSystem: '<Root>/MATLAB System4'
   */
  if (Moment_work_2017_DW.obj.isInitialized == 1) {
    Moment_work_2017_DW.obj.isInitialized = 2;
  }

  /* End of Start for MATLABSystem: '<Root>/MATLAB System4' */
}
