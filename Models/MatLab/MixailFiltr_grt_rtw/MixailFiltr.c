/*
 * MixailFiltr.c
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

#include "MixailFiltr.h"
#include "MixailFiltr_private.h"

/* Block signals (auto storage) */
B_MixailFiltr_T MixailFiltr_B;

/* Block states (auto storage) */
DW_MixailFiltr_T MixailFiltr_DW;

/* Real-time model */
RT_MODEL_MixailFiltr_T MixailFiltr_M_;
RT_MODEL_MixailFiltr_T *const MixailFiltr_M = &MixailFiltr_M_;
void RandSrcInitState_U_64(const uint32_T seed[], real_T state[], int32_T nChans)
{
  int32_T i;
  uint32_T j;
  int32_T k;
  int32_T n;
  real_T d;

  /* Start for S-Function (sdsprandsrc2): '<Root>/Random Source' */
  /* RandSrcInitState_U_64 */
  for (i = 0; i < nChans; i++) {
    j = seed[i] != 0U ? seed[i] : 2147483648U;
    state[35 * i + 34] = j;
    for (k = 0; k < 32; k++) {
      d = 0.0;
      for (n = 0; n < 53; n++) {
        j ^= j << 13;
        j ^= j >> 17;
        j ^= j << 5;
        d = (real_T)((int32_T)(j >> 19) & 1) + (d + d);
      }

      state[35 * i + k] = ldexp(d, -53);
    }

    state[35 * i + 32] = 0.0;
    state[35 * i + 33] = 0.0;
  }

  /* End of Start for S-Function (sdsprandsrc2): '<Root>/Random Source' */
}

void RandSrc_U_D(real_T y[], const real_T minVec[], int32_T minLen, const real_T
                 maxVec[], int32_T maxLen, real_T state[], int32_T nChans,
                 int32_T nSamps)
{
  int32_T one;
  int8_T *onePtr;
  int32_T chan;
  real_T min;
  real_T max;
  int32_T samps;
  real_T d;
  int32_T i;
  uint32_T j;
  int32_T ii[2];

  /* Start for S-Function (sdsprandsrc2): '<Root>/Random Source' */
  /* RandSrc_U_D */
  one = 1;
  onePtr = (int8_T *)&one;
  one = (onePtr[0U] == 0);
  for (chan = 0; chan < nChans; chan++) {
    min = minVec[minLen > 1 ? chan : 0];
    max = maxVec[maxLen > 1 ? chan : 0];
    max -= min;
    i = (int32_T)((uint32_T)state[chan * 35 + 33] & 31U);
    j = (uint32_T)state[chan * 35 + 34];
    for (samps = 0; samps < nSamps; samps++) {
      /* "Subtract with borrow" generator */
      d = state[((i + 20) & 31) + chan * 35];
      d -= state[((i + 5) & 31) + chan * 35];
      d -= state[chan * 35 + 32];
      if (d >= 0.0) {
        state[chan * 35 + 32] = 0.0;
      } else {
        d++;

        /* set 1 in LSB */
        state[chan * 35 + 32] = 1.1102230246251565E-16;
      }

      state[chan * 35 + i] = d;
      i = (i + 1) & 31;

      /* XOR with shift register sequence */
      memcpy(&ii[0U], &d, sizeof(real_T));
      ii[one] ^= j;
      j ^= j << 13;
      j ^= j >> 17;
      j ^= j << 5;
      ii[one ^ 1] ^= j & 1048575U;
      memcpy(&d, &ii[0U], sizeof(real_T));
      y[chan * nSamps + samps] = max * d + min;
    }

    state[chan * 35 + 33] = i;
    state[chan * 35 + 34] = j;
  }

  /* End of Start for S-Function (sdsprandsrc2): '<Root>/Random Source' */
}

void RandSrcCreateSeeds_64(uint32_T initSeed, uint32_T seedArray[], int32_T
  numSeeds)
{
  real_T state[35];
  real_T tmp;
  real_T min;
  real_T max;
  int32_T i;

  /* Start for S-Function (sdsprandsrc2): '<Root>/Random Source' */
  /* RandSrcCreateSeeds_64 */
  min = 0.0;
  max = 1.0;
  RandSrcInitState_U_64(&initSeed, state, 1);
  for (i = 0; i < numSeeds; i++) {
    RandSrc_U_D(&tmp, &min, 1, &max, 1, state, 1, 1);
    seedArray[i] = (uint32_T)(tmp * 2.147483648E+9);
  }

  /* End of Start for S-Function (sdsprandsrc2): '<Root>/Random Source' */
}

/* Model step function */
void MixailFiltr_step(void)
{
  /* local block i/o variables */
  real_T rtb_SineWave;
  real_T rtb_Sum;
  real_T numAccum;
  real_T denAccum;

  /* S-Function (sdspsine2): '<Root>/Sine Wave' */
  rtb_SineWave = MixailFiltr_P.SineWave_Amplitude * sin
    (MixailFiltr_DW.SineWave_AccFreqNorm);

  /* Update accumulated normalized freq value
     for next sample.  Keep in range [0 2*pi) */
  MixailFiltr_DW.SineWave_AccFreqNorm += MixailFiltr_P.SineWave_Frequency *
    0.062831853071795868;
  if (MixailFiltr_DW.SineWave_AccFreqNorm >= 6.2831853071795862) {
    MixailFiltr_DW.SineWave_AccFreqNorm -= 6.2831853071795862;
  } else {
    if (MixailFiltr_DW.SineWave_AccFreqNorm < 0.0) {
      MixailFiltr_DW.SineWave_AccFreqNorm += 6.2831853071795862;
    }
  }

  /* End of S-Function (sdspsine2): '<Root>/Sine Wave' */

  /* S-Function (sdsprandsrc2): '<Root>/Random Source' */
  RandSrc_U_D(&rtb_Sum, &MixailFiltr_P.RandomSource_MinVal, 1,
              &MixailFiltr_P.RandomSource_MaxVal, 1,
              MixailFiltr_DW.RandomSource_STATE_DWORK, 1, 1);

  /* Sum: '<Root>/Sum' */
  rtb_Sum += rtb_SineWave;

  /* S-Function (sdspbiquad): '<S1>/Digital Filter' */
  denAccum = (1.6318611446767519 * rtb_Sum - -0.96407180424987071 *
              MixailFiltr_DW.DigitalFilter_FILT_STATES[0]) - 0.36687355525178644
    * MixailFiltr_DW.DigitalFilter_FILT_STATES[1];
  numAccum = (1.8222520988065944 * MixailFiltr_DW.DigitalFilter_FILT_STATES[0] +
              denAccum) + MixailFiltr_DW.DigitalFilter_FILT_STATES[1];
  MixailFiltr_DW.DigitalFilter_FILT_STATES[1] =
    MixailFiltr_DW.DigitalFilter_FILT_STATES[0];
  MixailFiltr_DW.DigitalFilter_FILT_STATES[0] = denAccum;
  denAccum = (0.022752546154671007 * numAccum - -0.53665591932664913 *
              MixailFiltr_DW.DigitalFilter_FILT_STATES[2]) - 0.76752240273519168
    * MixailFiltr_DW.DigitalFilter_FILT_STATES[3];
  MixailFiltr_B.DigitalFilter = (1.1861760012314118 *
    MixailFiltr_DW.DigitalFilter_FILT_STATES[2] + denAccum) +
    MixailFiltr_DW.DigitalFilter_FILT_STATES[3];
  MixailFiltr_DW.DigitalFilter_FILT_STATES[3] =
    MixailFiltr_DW.DigitalFilter_FILT_STATES[2];
  MixailFiltr_DW.DigitalFilter_FILT_STATES[2] = denAccum;

  /* Matfile logging */
  rt_UpdateTXYLogVars(MixailFiltr_M->rtwLogInfo,
                      (&MixailFiltr_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(MixailFiltr_M)!=-1) &&
        !((rtmGetTFinal(MixailFiltr_M)-MixailFiltr_M->Timing.taskTime0) >
          MixailFiltr_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(MixailFiltr_M, "Simulation finished");
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
  if (!(++MixailFiltr_M->Timing.clockTick0)) {
    ++MixailFiltr_M->Timing.clockTickH0;
  }

  MixailFiltr_M->Timing.taskTime0 = MixailFiltr_M->Timing.clockTick0 *
    MixailFiltr_M->Timing.stepSize0 + MixailFiltr_M->Timing.clockTickH0 *
    MixailFiltr_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void MixailFiltr_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)MixailFiltr_M, 0,
                sizeof(RT_MODEL_MixailFiltr_T));
  rtmSetTFinal(MixailFiltr_M, 5.0);
  MixailFiltr_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    MixailFiltr_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(MixailFiltr_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(MixailFiltr_M->rtwLogInfo, (NULL));
    rtliSetLogT(MixailFiltr_M->rtwLogInfo, "tout");
    rtliSetLogX(MixailFiltr_M->rtwLogInfo, "");
    rtliSetLogXFinal(MixailFiltr_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(MixailFiltr_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(MixailFiltr_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(MixailFiltr_M->rtwLogInfo, 0);
    rtliSetLogDecimation(MixailFiltr_M->rtwLogInfo, 1);
    rtliSetLogY(MixailFiltr_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(MixailFiltr_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(MixailFiltr_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &MixailFiltr_B), 0,
                sizeof(B_MixailFiltr_T));

  /* states (dwork) */
  (void) memset((void *)&MixailFiltr_DW, 0,
                sizeof(DW_MixailFiltr_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(MixailFiltr_M->rtwLogInfo, 0.0, rtmGetTFinal
    (MixailFiltr_M), MixailFiltr_M->Timing.stepSize0, (&rtmGetErrorStatus
    (MixailFiltr_M)));

  {
    real_T arg;

    /* Start for S-Function (sdspsine2): '<Root>/Sine Wave' */
    /* Trigonometric mode: compute accumulated
       normalized trig fcn argument for each channel */
    /* Keep normalized value in range [0 2*pi) */
    arg = fmod(MixailFiltr_P.SineWave_Phase, 6.2831853071795862);
    if (arg < 0.0) {
      arg += 6.2831853071795862;
    }

    MixailFiltr_DW.SineWave_AccFreqNorm = arg;

    /* End of Start for S-Function (sdspsine2): '<Root>/Sine Wave' */

    /* Start for S-Function (sdsprandsrc2): '<Root>/Random Source' */
    RandSrcCreateSeeds_64((uint32_T)(100000 * rand()),
                          &MixailFiltr_DW.RandomSource_SEED_DWORK, 1);
    RandSrcInitState_U_64(&MixailFiltr_DW.RandomSource_SEED_DWORK,
                          MixailFiltr_DW.RandomSource_STATE_DWORK, 1);
  }

  {
    real_T arg;

    /* InitializeConditions for S-Function (sdspsine2): '<Root>/Sine Wave' */
    /* This code only executes when block is re-enabled in an
       enabled subsystem when the enabled subsystem states on
       re-enabling are set to 'Reset' */
    /* Reset to time zero on re-enable */
    /* Trigonometric mode: compute accumulated
       normalized trig fcn argument for each channel */
    /* Keep normalized value in range [0 2*pi) */
    arg = fmod(MixailFiltr_P.SineWave_Phase, 6.2831853071795862);
    if (arg < 0.0) {
      arg += 6.2831853071795862;
    }

    MixailFiltr_DW.SineWave_AccFreqNorm = arg;

    /* End of InitializeConditions for S-Function (sdspsine2): '<Root>/Sine Wave' */

    /* InitializeConditions for S-Function (sdspbiquad): '<S1>/Digital Filter' */
    MixailFiltr_DW.DigitalFilter_FILT_STATES[0] = 0.0;
    MixailFiltr_DW.DigitalFilter_FILT_STATES[1] = 0.0;
    MixailFiltr_DW.DigitalFilter_FILT_STATES[2] = 0.0;
    MixailFiltr_DW.DigitalFilter_FILT_STATES[3] = 0.0;
  }
}

/* Model terminate function */
void MixailFiltr_terminate(void)
{
  /* (no terminate code required) */
}
