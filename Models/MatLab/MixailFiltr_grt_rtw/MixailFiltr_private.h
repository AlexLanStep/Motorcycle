/*
 * MixailFiltr_private.h
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

#ifndef RTW_HEADER_MixailFiltr_private_h_
#define RTW_HEADER_MixailFiltr_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

extern void RandSrcInitState_U_64(const uint32_T seed[], real_T state[], int32_T
  nChans);
extern void RandSrc_U_D(real_T y[], const real_T minVec[], int32_T minLen, const
  real_T maxVec[], int32_T maxLen, real_T state[], int32_T nChans, int32_T
  nSamps);
extern void RandSrcCreateSeeds_64(uint32_T initSeed, uint32_T seedArray[],
  int32_T numSeeds);

#endif                                 /* RTW_HEADER_MixailFiltr_private_h_ */
