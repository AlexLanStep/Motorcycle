/*
 * Model_01_work_2017_contr_types.h
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

#ifndef RTW_HEADER_Model_01_work_2017_contr_types_h_
#define RTW_HEADER_Model_01_work_2017_contr_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef typedef_WolchSimCode_Model_01_work_20_T
#define typedef_WolchSimCode_Model_01_work_20_T

typedef struct {
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  real_T kMul;
  real_T nWht;
  real_T msp[64];
  real_T kw[3072];
} WolchSimCode_Model_01_work_20_T;

#endif                                 /*typedef_WolchSimCode_Model_01_work_20_T*/

#ifndef typedef_struct_T_Model_01_work_2017_c_T
#define typedef_struct_T_Model_01_work_2017_c_T

typedef struct {
  real_T f1[2];
  real_T f2[2];
} struct_T_Model_01_work_2017_c_T;

#endif                                 /*typedef_struct_T_Model_01_work_2017_c_T*/

#ifndef typedef_ModulSigmoid_Model_01_work_20_T
#define typedef_ModulSigmoid_Model_01_work_20_T

typedef struct {
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  real_T Rwheel;
  real_T Transfer;
  real_T Kreset;
  real_T sd;
  real_T sdsn;
  real_T betta;
  real_T sm_bet;
  real_T alfa;
  real_T sm_alfa;
  real_T kStd;
  real_T alfaExp;
  real_T d[606];
  real_T ind;
  real_T dSlipp[30];
  real_T lSlipp;
  real_T R;
  real_T alfa1;
  real_T Y0;
} ModulSigmoid_Model_01_work_20_T;

#endif                                 /*typedef_ModulSigmoid_Model_01_work_20_T*/

#ifndef typedef_struct_T_Model_01_work_2017_b_T
#define typedef_struct_T_Model_01_work_2017_b_T

typedef struct {
  real_T f1[2];
  real_T f2[2];
  real_T f3[2];
} struct_T_Model_01_work_2017_b_T;

#endif                                 /*typedef_struct_T_Model_01_work_2017_b_T*/

/* Parameters for system: '<Root>/MATLAB System2' */
typedef struct P_MATLABSystem2_Model_01_work_T_ P_MATLABSystem2_Model_01_work_T;

/* Parameters (auto storage) */
typedef struct P_Model_01_work_2017_contr_T_ P_Model_01_work_2017_contr_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Model_01_work_2017_co_T RT_MODEL_Model_01_work_2017_c_T;

#endif                                 /* RTW_HEADER_Model_01_work_2017_contr_types_h_ */
