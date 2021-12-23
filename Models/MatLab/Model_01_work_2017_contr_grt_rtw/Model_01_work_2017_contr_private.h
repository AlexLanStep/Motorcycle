/*
 * Model_01_work_2017_contr_private.h
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

#ifndef RTW_HEADER_Model_01_work_2017_contr_private_h_
#define RTW_HEADER_Model_01_work_2017_contr_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "Model_01_work_2017_contr.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

extern real_T rt_roundd_snf(real_T u);
extern void Model_01_wo_MATLABSystem2_Start(DW_MATLABSystem2_Model_01_wor_T
  *localDW, P_MATLABSystem2_Model_01_work_T *localP);
extern void Model_01_work_201_MATLABSystem2(real_T rtu_0, real_T rtu_1,
  B_MATLABSystem2_Model_01_work_T *localB, DW_MATLABSystem2_Model_01_wor_T
  *localDW, P_MATLABSystem2_Model_01_work_T *localP);
extern void Model_01_wor_MATLABSystem2_Term(DW_MATLABSystem2_Model_01_wor_T
  *localDW);

#endif                                 /* RTW_HEADER_Model_01_work_2017_contr_private_h_ */
