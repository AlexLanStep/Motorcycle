/*
 * Moment_BASA_2017_types.h
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

#ifndef RTW_HEADER_Moment_BASA_2017_types_h_
#define RTW_HEADER_Moment_BASA_2017_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
  void *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray__common*/

#ifndef typedef_emxArray__common_Moment_BASA__T
#define typedef_emxArray__common_Moment_BASA__T

typedef struct emxArray__common emxArray__common_Moment_BASA__T;

#endif                                 /*typedef_emxArray__common_Moment_BASA__T*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T_Moment_BASA_2_T
#define typedef_emxArray_real_T_Moment_BASA_2_T

typedef struct emxArray_real_T emxArray_real_T_Moment_BASA_2_T;

#endif                                 /*typedef_emxArray_real_T_Moment_BASA_2_T*/

#ifndef typedef_CMoment_Moment_BASA_2017_T
#define typedef_CMoment_Moment_BASA_2017_T

typedef struct {
  int32_T isInitialized;
  real_T NCount;
  real_T nm;
  real_T m[200];
  emxArray_real_T_Moment_BASA_2_T *x0;
  real_T xsum;
  real_T x2sum;
  real_T x_sr;
  emxArray_real_T_Moment_BASA_2_T *x_0;
  real_T x_01;
  real_T x_001;
  real_T xsum2;
  real_T z0;
  real_T z01;
  real_T z002;
} CMoment_Moment_BASA_2017_T;

#endif                                 /*typedef_CMoment_Moment_BASA_2017_T*/

#ifndef typedef_struct_T_Moment_BASA_2017_T
#define typedef_struct_T_Moment_BASA_2017_T

typedef struct {
  real_T f1[2];
  real_T f2[2];
  real_T f3[2];
} struct_T_Moment_BASA_2017_T;

#endif                                 /*typedef_struct_T_Moment_BASA_2017_T*/

/* Parameters (auto storage) */
typedef struct P_Moment_BASA_2017_T_ P_Moment_BASA_2017_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Moment_BASA_2017_T RT_MODEL_Moment_BASA_2017_T;

#endif                                 /* RTW_HEADER_Moment_BASA_2017_types_h_ */
