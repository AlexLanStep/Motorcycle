/*
 * Moment_work_2017_types.h
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

#ifndef RTW_HEADER_Moment_work_2017_types_h_
#define RTW_HEADER_Moment_work_2017_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef typedef_CMoment_Moment_work_2017_T
#define typedef_CMoment_Moment_work_2017_T

typedef struct {
  int32_T isInitialized;
  real_T X[16];
  real_T Y[4];
  real_T Z[64];
} CMoment_Moment_work_2017_T;

#endif                                 /*typedef_CMoment_Moment_work_2017_T*/

#ifndef typedef_struct_T_Moment_work_2017_T
#define typedef_struct_T_Moment_work_2017_T

typedef struct {
  real_T f1[2];
  real_T f2[2];
} struct_T_Moment_work_2017_T;

#endif                                 /*typedef_struct_T_Moment_work_2017_T*/

/* Parameters (auto storage) */
typedef struct P_Moment_work_2017_T_ P_Moment_work_2017_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Moment_work_2017_T RT_MODEL_Moment_work_2017_T;

#endif                                 /* RTW_HEADER_Moment_work_2017_types_h_ */
