/*
 * Model_01_work_2017_contr.c
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

#include "Model_01_work_2017_contr.h"
#include "Model_01_work_2017_contr_private.h"

/* Block signals (auto storage) */
B_Model_01_work_2017_contr_T Model_01_work_2017_contr_B;

/* Block states (auto storage) */
DW_Model_01_work_2017_contr_T Model_01_work_2017_contr_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_Model_01_work_2017_contr_T Model_01_work_2017_contr_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Model_01_work_2017_contr_T Model_01_work_2017_contr_Y;

/* Real-time model */
RT_MODEL_Model_01_work_2017_c_T Model_01_work_2017_contr_M_;
RT_MODEL_Model_01_work_2017_c_T *const Model_01_work_2017_contr_M =
  &Model_01_work_2017_contr_M_;

/* Forward declaration for local functions */
static ModulSigmoid_Model_01_work_20_T *Model_ModulSigmoid_ModulSigmoid
  (ModulSigmoid_Model_01_work_20_T *obj);

/*
 * Start for atomic system:
 *    'synthesized block'
 *    'synthesized block'
 *    'synthesized block'
 */
void Model_01_wo_MATLABSystem2_Start(DW_MATLABSystem2_Model_01_wor_T *localDW,
  P_MATLABSystem2_Model_01_work_T *localP)
{
  static const int8_T tmp[3072] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1,
    -1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1,
    -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1,
    -1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, 1,
    1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, 1,
    -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1,
    -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1,
    1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1,
    -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1,
    1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, 1, -1,
    -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1,
    1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, 1,
    1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1,
    1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, 1, -1,
    -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1,
    1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, 1,
    1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1,
    1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1,
    -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1,
    -1, -1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1,
    -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1,
    -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1,
    -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1,
    1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1,
    1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1,
    -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1,
    -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1,
    1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1,
    1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1,
    -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1,
    -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1,
    -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1,
    1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1,
    1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, -1, -1, 1, 1,
    1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1,
    1, 1, 1, 1, -1, -1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1,
    -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1,
    -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1,
    -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, -1, -1,
    1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, -1, -1, -1, 1, 1,
    1, 1, -1, -1, -1, -1, 1, 1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1,
    -1, -1, 1, 1, -1, -1, -1, -1, 1, 1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1,
    1, 1, -1, -1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, -1, -1,
    1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, -1, -1, -1, 1, 1,
    1, 1, -1, -1, -1, -1, 1, 1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1,
    -1, -1, 1, 1, -1, -1, -1, -1, 1, 1, -1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, -1,
    -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, -1, -1, 1, 1, 1, 1, -1, -1, 1, 1,
    -1, -1, -1, -1, 1, 1, -1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, -1, -1, -1, 1, 1,
    -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, -1, -1, -1,
    1, 1, -1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1,
    -1, -1, 1, 1, -1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, -1, -1, -1, 1, 1, -1, -1,
    1, 1, 1, 1, -1, -1, 1, 1, -1, -1, -1, -1, 1, 1, -1, -1, 1, 1, 1, 1, -1, -1,
    1, 1, -1, -1, -1, -1, 1, 1, -1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1,
    -1, -1, -1, -1, 1, 1, -1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, -1, -1, -1, 1, 1,
    -1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, -1, -1, -1, 1, 1, -1, -1, 1, 1, 1, 1,
    -1, -1, 1, 1, -1, -1, -1, -1, 1, 1, -1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, -1,
    -1, -1, 1, 1, -1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, -1, -1, -1, 1, 1, -1, -1,
    1, 1, -1, -1, 1, 1, -1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, -1, -1, -1, 1, 1,
    -1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, -1, -1,
    1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, -1,
    -1, -1, 1, 1, -1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1,
    -1, -1, -1, -1, 1, 1, -1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, -1, -1, -1, 1, 1,
    -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1,
    -1, -1, 1, 1, -1, -1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1,
    1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1,
    -1, -1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, 1, 1, -1, -1,
    1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1,
    1, 1, -1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1,
    -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1,
    1, 1, -1, -1, 1, 1, -1, -1, 1, 1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1,
    1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1,
    -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, -1, -1, 1, 1, -1, -1, 1, 1,
    -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1,
    1, 1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1,
    1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1,
    -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1,
    1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1,
    -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1,
    1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1,
    -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1,
    1, -1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1,
    1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1,
    1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1,
    1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1,
    1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1,
    -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1,
    -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1,
    1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1,
    -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1,
    -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1,
    -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1,
    1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1,
    -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1,
    -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1,
    -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1,
    1, -1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1,
    1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1,
    1, -1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1,
    1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1,
    1, -1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1,
    1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1,
    1, -1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1,
    1, -1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1,
    -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1,
    1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1,
    1, -1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1,
    1, -1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1,
    -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1,
    1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1,
    -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1,
    1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1,
    -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1,
    -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1,
    1, -1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1,
    -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1,
    1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1,
    1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1,
    1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1,
    -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1,
    1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1,
    1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1,
    1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1,
    -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1,
    1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1,
    1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1,
    -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1,
    -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, -1, 1,
    -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1,
    -1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1,
    -1, 1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1,
    1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1,
    1, -1, -1, 1, -1, 1 };

  int32_T i;

  /* Start for MATLABSystem: '<Root>/MATLAB System2' */
  localDW->obj.nWht = 64.0;
  memset(&localDW->obj.msp[0], 0, sizeof(real_T) << 6U);
  for (i = 0; i < 3072; i++) {
    localDW->obj.kw[i] = tmp[i];
  }

  localDW->obj.isInitialized = 0;
  localDW->objisempty = true;
  if (localDW->obj.isInitialized == 1) {
    localDW->obj.TunablePropsChanged = true;
  }

  localDW->obj.kMul = localP->MATLABSystem2_kMul;
  localDW->obj.isInitialized = 1;

  /*  Validate related or interdependent property values */
  /*         %% Advanced functions */
  /*  Validate inputs to the step method at initialization */
  /*   handle &  matlab.system.mixin.Propagates */
  /*     properties */
  /*     end */
  /*    properties(SetAccess  = private) */
  /*          kw=[1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1; */
  /*                  1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1; */
  /*                  1 1 1 1 1 1 1 1 1 1 1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 1 1 1; */
  /*                  1 1 1 1 1 1 1 1 1 1 1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 -1 -1 -1; */
  /*                  1 1 1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1; */
  /*                  1 1 1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 1 1 1 1 1 1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 1 1 1 1 1 1 1 1 1 1 1; */
  /*                  1 1 1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 1 1 1 1 1 1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 1 1 1 1 1 1 1 1 -1 -1 -1; */
  /*                  1 1 1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 1 1 1 1 1 1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 1 1 1 1 1 1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 1 1 1; */
  /*                  1 -1 -1 -1 -1 -1 -1 -1 -1 1 1 1 1 1 1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 1 1 1 1 1 1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 1 1 1 1 1 1 1; */
  /*                  1 -1 -1 -1 -1 -1 -1 -1 -1 1 1 1 1 1 1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 1 1 1 1 -1 -1 -1 -1 -1 -1 -1; */
  /*                  1 -1 -1 -1 -1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 1 1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 1 1 1 1 1 1 1 1 -1 -1 -1 -1 1 1 1; */
  /*                  1 -1 -1 -1 -1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1; */
  /*                  1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 -1 -1 -1; */
  /*                  1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 1 1 1; */
  /*                  1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1; */
  /*                  1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1; */
  /*                  -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1; */
  /*                  -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1; */
  /*                  -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 1 1 -1; */
  /*                  -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 -1 -1 1; */
  /*                  -1 -1 -1 1 1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 -1 -1 1 1 1 1 -1 -1 -1 -1 1; */
  /*                  -1 -1 -1 1 1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 1 1 -1 -1 -1 -1 1 1 -1 -1 1 1 1 1 -1 -1 1 1 -1 -1 -1 -1 1 1 1 1 -1; */
  /*                  -1 -1 -1 1 1 -1 -1 1 1 1 1 -1 -1 1 1 -1 -1 -1 -1 1 1 -1 -1 1 1 1 1 -1 -1 -1 -1 1 1 1 1 -1 -1 1 1 -1 -1 -1 -1 1 1 -1 -1 1; */
  /*                  -1 -1 -1 1 1 -1 -1 1 1 1 1 -1 -1 1 1 -1 -1 -1 -1 1 1 -1 -1 1 1 1 1 -1 -1 1 1 -1 -1 -1 -1 1 1 -1 -1 1 1 1 1 -1 -1 1 1 -1; */
  /*                  -1 1 1 -1 -1 -1 -1 1 1 -1 -1 1 1 1 1 -1 -1 1 1 -1 -1 -1 -1 1 1 -1 -1 1 1 1 1 -1 -1 1 1 -1 -1 -1 -1 1 1 -1 -1 1 1 1 1 -1; */
  /*                  -1 1 1 -1 -1 -1 -1 1 1 -1 -1 1 1 1 1 -1 -1 1 1 -1 -1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 1 1 -1 -1 1 1 -1 -1 -1 -1 1; */
  /*                  -1 1 1 -1 -1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 1 1 -1 -1 1 1 -1 -1 -1 -1 1 1 -1 -1 1 1 1 1 -1 -1 1 1 -1 -1 1 1 -1; */
  /*                  -1 1 1 -1 -1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 -1 -1 1 1 -1 -1 1 1 -1 -1 1; */
  /*                  -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 -1 -1 1; */
  /*                  -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 1 1 -1; */
  /*                  -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1; */
  /*                  -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1; */
  /*                  1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1; */
  /*                  1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1; */
  /*                  1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 1 -1 -1; */
  /*                  1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 -1 1 1; */
  /*                  1 1 -1 -1 1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 -1 1 1 -1 -1 1 1 -1 -1 1 1; */
  /*                  1 1 -1 -1 1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 1 -1 -1 1 1 -1 -1 1 -1 1 1 -1 -1 1 1 -1 1 -1 -1 1 1 -1 -1 1 1 -1 -1; */
  /*                  1 1 -1 -1 1 -1 1 1 -1 -1 1 1 -1 1 -1 -1 1 1 -1 -1 1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 -1 1 1 -1 1 -1 -1 1 1 -1 -1 1 -1 1 1; */
  /*                  1 1 -1 -1 1 -1 1 1 -1 -1 1 1 -1 1 -1 -1 1 1 -1 -1 1 -1 1 1 -1 -1 1 1 -1 1 -1 -1 1 1 -1 -1 1 -1 1 1 -1 -1 1 1 -1 1 -1 -1; */
  /*                  1 -1 1 1 -1 -1 1 1 -1 1 -1 -1 1 1 -1 -1 1 -1 1 1 -1 -1 1 1 -1 1 -1 -1 1 1 -1 -1 1 -1 1 1 -1 -1 1 1 -1 1 -1 -1 1 1 -1 -1; */
  /*                  1 -1 1 1 -1 -1 1 1 -1 1 -1 -1 1 1 -1 -1 1 -1 1 1 -1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 1 -1 -1 1 -1 1 1 -1 -1 1 1; */
  /*                  1 -1 1 1 -1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 1 -1 -1 1 -1 1 1 -1 -1 1 1 -1 1 -1 -1 1 1 -1 -1 1 -1 1 1 -1 1 -1 -1; */
  /*                  1 -1 1 1 -1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 -1 1 1 -1 1 -1 -1 1 -1 1 1; */
  /*                  1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 -1 1 1; */
  /*                  1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 1 -1 -1; */
  /*                  1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1; */
  /*                  1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1; */
  /*                  -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1; */
  /*                  -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1; */
  /*                  -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 1 -1 1; */
  /*                  -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 -1 1 -1; */
  /*                  -1 -1 1 -1 1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 -1 1 -1 1 1 -1 1 -1 -1 1 -1; */
  /*                  -1 -1 1 -1 1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 1 -1 1 -1 -1 1 -1 1 -1 1 -1 1 1 -1 1 -1 1 -1 1 -1 -1 1 -1 1 1 -1 1; */
  /*                  -1 -1 1 -1 1 -1 1 -1 1 1 -1 1 -1 1 -1 1 -1 -1 1 -1 1 -1 1 -1 1 1 -1 1 -1 -1 1 -1 1 1 -1 1 -1 1 -1 1 -1 -1 1 -1 1 -1 1 -1; */
  /*                  -1 -1 1 -1 1 -1 1 -1 1 1 -1 1 -1 1 -1 1 -1 -1 1 -1 1 -1 1 -1 1 1 -1 1 -1 1 -1 1 -1 -1 1 -1 1 -1 1 -1 1 1 -1 1 -1 1 -1 1; */
  /*                  -1 1 -1 1 -1 -1 1 -1 1 -1 1 -1 1 1 -1 1 -1 1 -1 1 -1 -1 1 -1 1 -1 1 -1 1 1 -1 1 -1 1 -1 1 -1 -1 1 -1 1 -1 1 -1 1 1 -1 1; */
  /*                  -1 1 -1 1 -1 -1 1 -1 1 -1 1 -1 1 1 -1 1 -1 1 -1 1 -1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 1 -1 1 -1 1 -1 1 -1 -1 1 -1; */
  /*                  -1 1 -1 1 -1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 1 -1 1 -1 1 -1 1 -1 -1 1 -1 1 -1 1 -1 1 1 -1 1 -1 1 -1 1 -1 1 -1 1; */
  /*                  -1 1 -1 1 -1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 -1 1 -1 1 -1 1 -1 1 -1 1 -1; */
  /*                  -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 -1 1 -1; */
  /*                  -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 1 -1 1; */
  /*                  -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1; */
  /*                  -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1]         */
  /*  Public, non-tunable properties */
  /*  Pre-computed constants */
  /*  Constructor */
  /*  Support name-value pair arguments when constructing object */
  /*         %% Common functions */
  /*  Perform one-time calculations, such as computing constants */
  localDW->obj.TunablePropsChanged = false;

  /* End of Start for MATLABSystem: '<Root>/MATLAB System2' */
}

/*
 * Output and update for atomic system:
 *    'synthesized block'
 *    'synthesized block'
 *    'synthesized block'
 */
void Model_01_work_201_MATLABSystem2(real_T rtu_0, real_T rtu_1,
  B_MATLABSystem2_Model_01_work_T *localB, DW_MATLABSystem2_Model_01_wor_T
  *localDW, P_MATLABSystem2_Model_01_work_T *localP)
{
  real_T hoistedGlobal_kMul;
  boolean_T p;
  boolean_T p_0;
  WolchSimCode_Model_01_work_20_T *obj;
  int32_T i;
  real_T y[48];
  real_T a[64];
  real_T y_0[48];
  int32_T k;
  real_T varargin_1;
  real_T varargin_2;
  int32_T i_0;

  /* Start for MATLABSystem: '<Root>/MATLAB System2' incorporates:
   *  MATLABSystem: '<Root>/MATLAB System2'
   */
  hoistedGlobal_kMul = localDW->obj.kMul;
  p = false;
  p_0 = true;
  if (!(hoistedGlobal_kMul == localP->MATLABSystem2_kMul)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    p = (localDW->obj.isInitialized == 1);
    if (p) {
      localDW->obj.TunablePropsChanged = true;
    }

    localDW->obj.kMul = localP->MATLABSystem2_kMul;
  }

  obj = &localDW->obj;
  if (localDW->obj.TunablePropsChanged) {
    /*  Validate related or interdependent property values */
    localDW->obj.TunablePropsChanged = false;

    /*  Perform calculations if tunable properties change while */
    /*  system is running */
  }

  hoistedGlobal_kMul = localDW->obj.nWht - 1.0;
  if (1.0 > hoistedGlobal_kMul) {
    k = 0;
  } else {
    k = (int32_T)hoistedGlobal_kMul;
  }

  hoistedGlobal_kMul = localDW->obj.nWht;
  if (2.0 > hoistedGlobal_kMul) {
    i = 0;
  } else {
    i = 1;
  }

  for (i_0 = 0; i_0 < k; i_0++) {
    a[i_0] = localDW->obj.msp[i_0];
  }

  for (i_0 = 0; i_0 < k; i_0++) {
    obj->msp[i + i_0] = a[i_0];
  }

  obj->msp[0] = rtu_0;
  for (i = 0; i < 64; i++) {
    a[i] = obj->msp[i];
  }

  for (i = 0; i < 3072; i++) {
    localB->b[i] = obj->kw[i];
  }

  for (k = 0; k < 48; k++) {
    y[k] = 0.0;
    for (i = 0; i < 64; i++) {
      y[k] += localB->b[(k << 6) + i] * a[i];
    }

    y_0[k] = fabs(y[k]);
  }

  hoistedGlobal_kMul = y_0[0];
  for (k = 0; k < 47; k++) {
    hoistedGlobal_kMul += y_0[k + 1];
  }

  varargin_1 = hoistedGlobal_kMul / rtu_1 * obj->kMul;
  varargin_2 = obj->kMul;

  /* MATLABSystem: '<Root>/MATLAB System2' incorporates:
   *  Start for MATLABSystem: '<Root>/MATLAB System2'
   */
  localB->MATLABSystem2_o1 = hoistedGlobal_kMul;
  localB->MATLABSystem2_o2 = fmin(varargin_1, varargin_2);
}

/*
 * Termination for atomic system:
 *    'synthesized block'
 *    'synthesized block'
 *    'synthesized block'
 */
void Model_01_wor_MATLABSystem2_Term(DW_MATLABSystem2_Model_01_wor_T *localDW)
{
  /* Start for MATLABSystem: '<Root>/MATLAB System2' incorporates:
   *  Terminate for MATLABSystem: '<Root>/MATLAB System2'
   */
  if (localDW->obj.isInitialized == 1) {
    localDW->obj.isInitialized = 2;
  }

  /* End of Start for MATLABSystem: '<Root>/MATLAB System2' */
}

static ModulSigmoid_Model_01_work_20_T *Model_ModulSigmoid_ModulSigmoid
  (ModulSigmoid_Model_01_work_20_T *obj)
{
  ModulSigmoid_Model_01_work_20_T *obj_0;
  int32_T i;
  int32_T k;
  real_T tmp_data[101];
  boolean_T tmp[101];
  int8_T tmp_data_0[101];
  int32_T trueCount;
  ModulSigmoid_Model_01_work_20_T *this;
  real_T x;
  int32_T tmp_size_idx_1;

  /* Start for MATLABSystem: '<Root>/MATLAB System3' */
  obj_0 = obj;
  obj_0->Rwheel = 0.43179999999999996;
  obj_0->Transfer = 3.0;
  obj_0->sd = 6.0;
  obj_0->sdsn = 0.25;
  obj_0->betta = 0.6;
  obj_0->sm_bet = 0.3;
  obj_0->alfa = 1.0;
  obj_0->sm_alfa = 0.3;
  obj_0->alfaExp = 0.5;
  for (trueCount = 0; trueCount < 606; trueCount++) {
    obj_0->d[trueCount] = 0.0;
  }

  for (trueCount = 0; trueCount < 30; trueCount++) {
    obj_0->dSlipp[trueCount] = 0.0;
  }

  obj_0->Y0 = 0.0;

  /* Start for MATLABSystem: '<Root>/MATLAB System3' */
  this = obj_0;
  obj_0 = this;
  obj_0->isInitialized = 0;
  this = obj_0;
  obj_0 = this;
  obj_0->ind = 1.0;
  obj_0->R = obj_0->Rwheel * obj_0->Transfer;
  for (i = 0; i < 6; i++) {
    for (k = 0; k < 101; k++) {
      this = obj_0;

      /*  Public, tunable properties */
      /*  Public, non-tunable properties */
      /*  Pre-computed constants */
      /*  Constructor */
      /*  Support name-value pair arguments when constructing object */
      /*                  disp(k) */
      /*         %% Common functions */
      x = (((1.0 + (real_T)k) - 1.0) / 10.0 - (this->sd - ((1.0 + (real_T)i) -
             1.0) * this->sdsn)) * -(((1.0 + (real_T)i) - 1.0) * this->sm_bet +
        this->betta);
      x = (((1.0 + (real_T)i) - 1.0) * this->sm_alfa + this->alfa) * exp(x) +
        1.0;
      obj_0->d[i + 6 * k] = 1.0 / x;
    }
  }

  for (k = 0; k < 5; k++) {
    trueCount = (5 - k) + 1;
    for (tmp_size_idx_1 = 0; tmp_size_idx_1 < 101; tmp_size_idx_1++) {
      tmp[tmp_size_idx_1] = (obj_0->d[((5 - k) + 6 * tmp_size_idx_1) - 1] >
        obj_0->d[(6 * tmp_size_idx_1 + trueCount) - 1]);
    }

    trueCount = 0;
    for (i = 0; i < 101; i++) {
      if (tmp[i]) {
        trueCount++;
      }
    }

    tmp_size_idx_1 = trueCount;
    trueCount = 0;
    for (i = 0; i < 101; i++) {
      if (tmp[i]) {
        tmp_data_0[trueCount] = (int8_T)(i + 1);
        trueCount++;
      }
    }

    for (trueCount = 0; trueCount < tmp_size_idx_1; trueCount++) {
      tmp_data[trueCount] = obj_0->d[((tmp_data_0[trueCount] - 1) * 6 + (5 - k))
        - 1];
    }

    if (1 > tmp_size_idx_1) {
      i = 0;
    } else {
      i = tmp_size_idx_1;
    }

    trueCount = (5 - k) + 1;
    for (tmp_size_idx_1 = 0; tmp_size_idx_1 < i; tmp_size_idx_1++) {
      tmp_data[tmp_size_idx_1] = obj_0->d[(6 * tmp_size_idx_1 + trueCount) - 1];
    }

    for (trueCount = 0; trueCount < i; trueCount++) {
      obj_0->d[((5 - k) + 6 * trueCount) - 1] = tmp_data[trueCount];
    }
  }

  obj_0->lSlipp = 30.0;
  obj_0->alfa1 = 1.0 - obj_0->alfaExp;
  return obj_0;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void Model_01_work_2017_contr_step(void)
{
  boolean_T p;
  boolean_T p_0;
  ModulSigmoid_Model_01_work_20_T *obj;
  real_T x;
  real_T std4;
  real_T x_0[30];
  int32_T k;
  int32_T ix;
  real_T xbar;
  real_T r;
  int32_T i;

  /* Inport: '<Root>/YawAcc' incorporates:
   *  Constant: '<Root>/YawAccNormKoef'
   */
  Model_01_work_201_MATLABSystem2(Model_01_work_2017_contr_U.YawAcc,
    Model_01_work_2017_contr_P.YawAccNormKoef_Value,
    &Model_01_work_2017_contr_B.MATLABSystem,
    &Model_01_work_2017_contr_DW.MATLABSystem, (P_MATLABSystem2_Model_01_work_T *)
    &Model_01_work_2017_contr_P.MATLABSystem);

  /* Inport: '<Root>/YawVel' incorporates:
   *  Constant: '<Root>/YawVelNormKoef'
   */
  Model_01_work_201_MATLABSystem2(Model_01_work_2017_contr_U.YawVel,
    Model_01_work_2017_contr_P.YawVelNormKoef_Value,
    &Model_01_work_2017_contr_B.MATLABSystem1,
    &Model_01_work_2017_contr_DW.MATLABSystem1, (P_MATLABSystem2_Model_01_work_T
    *)&Model_01_work_2017_contr_P.MATLABSystem1);

  /* Inport: '<Root>/RollVel' incorporates:
   *  Constant: '<Root>/RollVelNormKoef'
   */
  Model_01_work_201_MATLABSystem2(Model_01_work_2017_contr_U.RollVel,
    Model_01_work_2017_contr_P.RollVelNormKoef_Value,
    &Model_01_work_2017_contr_B.MATLABSystem2,
    &Model_01_work_2017_contr_DW.MATLABSystem2, (P_MATLABSystem2_Model_01_work_T
    *)&Model_01_work_2017_contr_P.MATLABSystem2);

  /* Start for MATLABSystem: '<Root>/MATLAB System3' incorporates:
   *  Inport: '<Root>/Belt'
   *  Inport: '<Root>/Rotv'
   *  MATLABSystem: '<Root>/MATLAB System3'
   *  MinMax: '<Root>/MinMax'
   */
  x = Model_01_work_2017_contr_DW.obj.Rwheel;
  p = false;
  p_0 = true;
  if (!(x == Model_01_work_2017_contr_P.MATLABSystem3_Rwheel)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    p = (Model_01_work_2017_contr_DW.obj.isInitialized == 1);
    if (p) {
      Model_01_work_2017_contr_DW.obj.TunablePropsChanged = true;
    }

    Model_01_work_2017_contr_DW.obj.Rwheel =
      Model_01_work_2017_contr_P.MATLABSystem3_Rwheel;
  }

  x = Model_01_work_2017_contr_DW.obj.Transfer;
  p = false;
  p_0 = true;
  if (!(x == Model_01_work_2017_contr_P.MATLABSystem3_Transfer)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    p = (Model_01_work_2017_contr_DW.obj.isInitialized == 1);
    if (p) {
      Model_01_work_2017_contr_DW.obj.TunablePropsChanged = true;
    }

    Model_01_work_2017_contr_DW.obj.Transfer =
      Model_01_work_2017_contr_P.MATLABSystem3_Transfer;
  }

  x = Model_01_work_2017_contr_DW.obj.Kreset;
  p = false;
  p_0 = true;
  if (!(x == Model_01_work_2017_contr_P.MATLABSystem3_Kreset)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    p = (Model_01_work_2017_contr_DW.obj.isInitialized == 1);
    if (p) {
      Model_01_work_2017_contr_DW.obj.TunablePropsChanged = true;
    }

    Model_01_work_2017_contr_DW.obj.Kreset =
      Model_01_work_2017_contr_P.MATLABSystem3_Kreset;
  }

  x = Model_01_work_2017_contr_DW.obj.sd;
  p = false;
  p_0 = true;
  if (!(x == Model_01_work_2017_contr_P.MATLABSystem3_sd)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    p = (Model_01_work_2017_contr_DW.obj.isInitialized == 1);
    if (p) {
      Model_01_work_2017_contr_DW.obj.TunablePropsChanged = true;
    }

    Model_01_work_2017_contr_DW.obj.sd =
      Model_01_work_2017_contr_P.MATLABSystem3_sd;
  }

  x = Model_01_work_2017_contr_DW.obj.sdsn;
  p = false;
  p_0 = true;
  if (!(x == Model_01_work_2017_contr_P.MATLABSystem3_sdsn)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    p = (Model_01_work_2017_contr_DW.obj.isInitialized == 1);
    if (p) {
      Model_01_work_2017_contr_DW.obj.TunablePropsChanged = true;
    }

    Model_01_work_2017_contr_DW.obj.sdsn =
      Model_01_work_2017_contr_P.MATLABSystem3_sdsn;
  }

  x = Model_01_work_2017_contr_DW.obj.betta;
  p = false;
  p_0 = true;
  if (!(x == Model_01_work_2017_contr_P.MATLABSystem3_betta)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    p = (Model_01_work_2017_contr_DW.obj.isInitialized == 1);
    if (p) {
      Model_01_work_2017_contr_DW.obj.TunablePropsChanged = true;
    }

    Model_01_work_2017_contr_DW.obj.betta =
      Model_01_work_2017_contr_P.MATLABSystem3_betta;
  }

  x = Model_01_work_2017_contr_DW.obj.sm_bet;
  p = false;
  p_0 = true;
  if (!(x == Model_01_work_2017_contr_P.MATLABSystem3_sm_bet)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    p = (Model_01_work_2017_contr_DW.obj.isInitialized == 1);
    if (p) {
      Model_01_work_2017_contr_DW.obj.TunablePropsChanged = true;
    }

    Model_01_work_2017_contr_DW.obj.sm_bet =
      Model_01_work_2017_contr_P.MATLABSystem3_sm_bet;
  }

  x = Model_01_work_2017_contr_DW.obj.alfa;
  p = false;
  p_0 = true;
  if (!(x == Model_01_work_2017_contr_P.MATLABSystem3_alfa)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    p = (Model_01_work_2017_contr_DW.obj.isInitialized == 1);
    if (p) {
      Model_01_work_2017_contr_DW.obj.TunablePropsChanged = true;
    }

    Model_01_work_2017_contr_DW.obj.alfa =
      Model_01_work_2017_contr_P.MATLABSystem3_alfa;
  }

  x = Model_01_work_2017_contr_DW.obj.sm_alfa;
  p = false;
  p_0 = true;
  if (!(x == Model_01_work_2017_contr_P.MATLABSystem3_sm_alfa)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    p = (Model_01_work_2017_contr_DW.obj.isInitialized == 1);
    if (p) {
      Model_01_work_2017_contr_DW.obj.TunablePropsChanged = true;
    }

    Model_01_work_2017_contr_DW.obj.sm_alfa =
      Model_01_work_2017_contr_P.MATLABSystem3_sm_alfa;
  }

  x = Model_01_work_2017_contr_DW.obj.kStd;
  p = false;
  p_0 = true;
  if (!(x == Model_01_work_2017_contr_P.MATLABSystem3_kStd)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    p = (Model_01_work_2017_contr_DW.obj.isInitialized == 1);
    if (p) {
      Model_01_work_2017_contr_DW.obj.TunablePropsChanged = true;
    }

    Model_01_work_2017_contr_DW.obj.kStd =
      Model_01_work_2017_contr_P.MATLABSystem3_kStd;
  }

  x = Model_01_work_2017_contr_DW.obj.alfaExp;
  p = false;
  p_0 = true;
  if (!(x == Model_01_work_2017_contr_P.MATLABSystem3_alfaExp)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    p = (Model_01_work_2017_contr_DW.obj.isInitialized == 1);
    if (p) {
      Model_01_work_2017_contr_DW.obj.TunablePropsChanged = true;
    }

    Model_01_work_2017_contr_DW.obj.alfaExp =
      Model_01_work_2017_contr_P.MATLABSystem3_alfaExp;
  }

  obj = &Model_01_work_2017_contr_DW.obj;
  if (Model_01_work_2017_contr_DW.obj.TunablePropsChanged) {
    /*  Validate related or interdependent property values */
    Model_01_work_2017_contr_DW.obj.TunablePropsChanged = false;

    /*  Perform calculations if tunable properties change while */
    /*  system is running */
  }

  /*  , ss */
  x = 0.0;
  if (Model_01_work_2017_contr_U.Rotv >= 10.0) {
    x = Model_01_work_2017_contr_U.Rotv * Model_01_work_2017_contr_DW.obj.R;
    x = 1.0 - Model_01_work_2017_contr_U.Belt / x;
  }

  std4 = Model_01_work_2017_contr_DW.obj.lSlipp - 1.0;
  if (1.0 > std4) {
    k = 0;
  } else {
    k = (int32_T)std4;
  }

  std4 = Model_01_work_2017_contr_DW.obj.lSlipp;
  if (2.0 > std4) {
    ix = 0;
  } else {
    ix = 1;
  }

  for (i = 0; i < k; i++) {
    x_0[i] = Model_01_work_2017_contr_DW.obj.dSlipp[i];
  }

  for (i = 0; i < k; i++) {
    obj->dSlipp[ix + i] = x_0[i];
  }

  obj->dSlipp[0] = x;

  /*  I - Режим формирования массива dSlipp   */
  if (!(obj->dSlipp[(int32_T)obj->lSlipp - 1] == 0.0)) {
    for (i = 0; i < 30; i++) {
      x_0[i] = obj->dSlipp[i];
    }

    std4 = x_0[0];
    for (k = 0; k < 29; k++) {
      std4 += x_0[k + 1];
    }

    x = std4 / 30.0;
    for (i = 0; i < 30; i++) {
      x_0[i] = obj->dSlipp[i];
    }

    ix = 1;
    xbar = x_0[0] + x_0[1];
    for (k = 0; k < 28; k++) {
      ix++;
      xbar += x_0[ix];
    }

    xbar /= 30.0;
    ix = 0;
    r = x_0[0] - xbar;
    std4 = r * r;
    for (k = 0; k < 29; k++) {
      ix++;
      r = x_0[ix] - xbar;
      std4 += r * r;
    }

    std4 /= 29.0;
    std4 = sqrt(std4) * obj->kStd;

    /*  II - Режим ind == 1 */
    if (obj->ind == 1.0) {
      if (obj->dSlipp[0] > x + std4) {
        x = obj->ind + 1.0;
        obj->ind = fmin(x, 6.0);
      } else {
        if (obj->dSlipp[0] < x - std4) {
          x = obj->ind - 1.0;
          obj->ind = fmax(x, 1.0);
        }
      }
    } else {
      /*  III - Режим ind > 1 */
      if ((obj->dSlipp[0] > x + std4) && (obj->dSlipp[0] > obj->dSlipp[1])) {
        x = obj->ind + 1.0;
        obj->ind = fmin(x, 6.0);
      } else if ((obj->dSlipp[0] < x - std4) && (obj->dSlipp[0] < obj->dSlipp[1]))
      {
        x = obj->ind - 1.0;
        obj->ind = fmax(x, 1.0);
      } else {
        obj->dSlipp[0] = obj->dSlipp[1];
      }
    }
  }

  x = obj->d[(((int32_T)fmax(fmin(rt_roundd_snf(fmax(fmax
    (Model_01_work_2017_contr_B.MATLABSystem.MATLABSystem2_o2,
     Model_01_work_2017_contr_B.MATLABSystem1.MATLABSystem2_o2),
    Model_01_work_2017_contr_B.MATLABSystem2.MATLABSystem2_o2)), 100.0), 1.0) -
               1) * 6 + (int32_T)obj->ind) - 1];
  x = obj->alfaExp * x + obj->alfa1 * obj->Y0;
  x = fmin(x, 1.0);

  /*  без этой строчки может бать отрицательный момент - торможение */
  obj->Y0 = x;

  /* Outport: '<Root>/NotStatic' incorporates:
   *  Inport: '<Root>/Rotv'
   *  MATLABSystem: '<Root>/MATLAB System3'
   *  Start for MATLABSystem: '<Root>/MATLAB System3'
   *  Product: '<Root>/Divide'
   */
  Model_01_work_2017_contr_Y.NotStatic = (1.0 - x) *
    Model_01_work_2017_contr_U.Rotv;

  /* Outport: '<Root>/YawAccNoNorm' */
  Model_01_work_2017_contr_Y.YawAccNoNorm =
    Model_01_work_2017_contr_B.MATLABSystem.MATLABSystem2_o1;

  /* Outport: '<Root>/YawVelNoNorm' */
  Model_01_work_2017_contr_Y.YawVelNoNorm =
    Model_01_work_2017_contr_B.MATLABSystem1.MATLABSystem2_o1;

  /* Outport: '<Root>/RollVelNoNorm' */
  Model_01_work_2017_contr_Y.RollVelNoNorm =
    Model_01_work_2017_contr_B.MATLABSystem2.MATLABSystem2_o1;

  /* Matfile logging */
  rt_UpdateTXYLogVars(Model_01_work_2017_contr_M->rtwLogInfo,
                      (&Model_01_work_2017_contr_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(Model_01_work_2017_contr_M)!=-1) &&
        !((rtmGetTFinal(Model_01_work_2017_contr_M)-
           Model_01_work_2017_contr_M->Timing.taskTime0) >
          Model_01_work_2017_contr_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Model_01_work_2017_contr_M, "Simulation finished");
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
  if (!(++Model_01_work_2017_contr_M->Timing.clockTick0)) {
    ++Model_01_work_2017_contr_M->Timing.clockTickH0;
  }

  Model_01_work_2017_contr_M->Timing.taskTime0 =
    Model_01_work_2017_contr_M->Timing.clockTick0 *
    Model_01_work_2017_contr_M->Timing.stepSize0 +
    Model_01_work_2017_contr_M->Timing.clockTickH0 *
    Model_01_work_2017_contr_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Model_01_work_2017_contr_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Model_01_work_2017_contr_M, 0,
                sizeof(RT_MODEL_Model_01_work_2017_c_T));
  rtmSetTFinal(Model_01_work_2017_contr_M, 96.0);
  Model_01_work_2017_contr_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    Model_01_work_2017_contr_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Model_01_work_2017_contr_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Model_01_work_2017_contr_M->rtwLogInfo, (NULL));
    rtliSetLogT(Model_01_work_2017_contr_M->rtwLogInfo, "tout");
    rtliSetLogX(Model_01_work_2017_contr_M->rtwLogInfo, "");
    rtliSetLogXFinal(Model_01_work_2017_contr_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Model_01_work_2017_contr_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Model_01_work_2017_contr_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(Model_01_work_2017_contr_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Model_01_work_2017_contr_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &Model_01_work_2017_contr_Y.NotStatic,
        &Model_01_work_2017_contr_Y.YawAccNoNorm,
        &Model_01_work_2017_contr_Y.YawVelNoNorm,
        &Model_01_work_2017_contr_Y.RollVelNoNorm
      };

      rtliSetLogYSignalPtrs(Model_01_work_2017_contr_M->rtwLogInfo,
                            ((LogSignalPtrsType)rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        2,
        2,
        2,
        2
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1, 1,
        1, 1,
        1, 1,
        1, 1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0,
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL), (NULL),
        (NULL), (NULL),
        (NULL), (NULL),
        (NULL), (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4, 4,
        4, 4,
        4, 4,
        4, 4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0,
        0,
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "",
        "",
        "",
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "Model_01_work_2017_contr/NotStatic",
        "Model_01_work_2017_contr/YawAccNoNorm",
        "Model_01_work_2017_contr/YawVelNoNorm",
        "Model_01_work_2017_contr/RollVelNoNorm" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          4,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(Model_01_work_2017_contr_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[2] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[3] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[4] = &rt_LoggedOutputWidths[2];
      rt_LoggedCurrentSignalDimensions[5] = &rt_LoggedOutputWidths[2];
      rt_LoggedCurrentSignalDimensions[6] = &rt_LoggedOutputWidths[3];
      rt_LoggedCurrentSignalDimensions[7] = &rt_LoggedOutputWidths[3];
    }

    rtliSetLogY(Model_01_work_2017_contr_M->rtwLogInfo, "yout");
  }

  /* block I/O */
  (void) memset(((void *) &Model_01_work_2017_contr_B), 0,
                sizeof(B_Model_01_work_2017_contr_T));

  /* states (dwork) */
  (void) memset((void *)&Model_01_work_2017_contr_DW, 0,
                sizeof(DW_Model_01_work_2017_contr_T));

  /* external inputs */
  (void)memset((void *)&Model_01_work_2017_contr_U, 0, sizeof
               (ExtU_Model_01_work_2017_contr_T));

  /* external outputs */
  (void) memset((void *)&Model_01_work_2017_contr_Y, 0,
                sizeof(ExtY_Model_01_work_2017_contr_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Model_01_work_2017_contr_M->rtwLogInfo, 0.0,
    rtmGetTFinal(Model_01_work_2017_contr_M),
    Model_01_work_2017_contr_M->Timing.stepSize0, (&rtmGetErrorStatus
    (Model_01_work_2017_contr_M)));

  {
    boolean_T flag;

    /* Start for Inport: '<Root>/YawAcc' incorporates:
     *  Constant: '<Root>/YawAccNormKoef'
     */
    Model_01_wo_MATLABSystem2_Start(&Model_01_work_2017_contr_DW.MATLABSystem,
      (P_MATLABSystem2_Model_01_work_T *)
      &Model_01_work_2017_contr_P.MATLABSystem);

    /* Start for Inport: '<Root>/YawVel' incorporates:
     *  Constant: '<Root>/YawVelNormKoef'
     */
    Model_01_wo_MATLABSystem2_Start(&Model_01_work_2017_contr_DW.MATLABSystem1,
      (P_MATLABSystem2_Model_01_work_T *)
      &Model_01_work_2017_contr_P.MATLABSystem1);

    /* Start for Inport: '<Root>/RollVel' incorporates:
     *  Constant: '<Root>/RollVelNormKoef'
     */
    Model_01_wo_MATLABSystem2_Start(&Model_01_work_2017_contr_DW.MATLABSystem2,
      (P_MATLABSystem2_Model_01_work_T *)
      &Model_01_work_2017_contr_P.MATLABSystem2);

    /* Start for MATLABSystem: '<Root>/MATLAB System3' */
    Model_ModulSigmoid_ModulSigmoid(&Model_01_work_2017_contr_DW.obj);
    Model_01_work_2017_contr_DW.objisempty = true;
    flag = (Model_01_work_2017_contr_DW.obj.isInitialized == 1);
    if (flag) {
      Model_01_work_2017_contr_DW.obj.TunablePropsChanged = true;
    }

    Model_01_work_2017_contr_DW.obj.Rwheel =
      Model_01_work_2017_contr_P.MATLABSystem3_Rwheel;
    flag = (Model_01_work_2017_contr_DW.obj.isInitialized == 1);
    if (flag) {
      Model_01_work_2017_contr_DW.obj.TunablePropsChanged = true;
    }

    Model_01_work_2017_contr_DW.obj.Transfer =
      Model_01_work_2017_contr_P.MATLABSystem3_Transfer;
    flag = (Model_01_work_2017_contr_DW.obj.isInitialized == 1);
    if (flag) {
      Model_01_work_2017_contr_DW.obj.TunablePropsChanged = true;
    }

    Model_01_work_2017_contr_DW.obj.Kreset =
      Model_01_work_2017_contr_P.MATLABSystem3_Kreset;
    flag = (Model_01_work_2017_contr_DW.obj.isInitialized == 1);
    if (flag) {
      Model_01_work_2017_contr_DW.obj.TunablePropsChanged = true;
    }

    Model_01_work_2017_contr_DW.obj.sd =
      Model_01_work_2017_contr_P.MATLABSystem3_sd;
    flag = (Model_01_work_2017_contr_DW.obj.isInitialized == 1);
    if (flag) {
      Model_01_work_2017_contr_DW.obj.TunablePropsChanged = true;
    }

    Model_01_work_2017_contr_DW.obj.sdsn =
      Model_01_work_2017_contr_P.MATLABSystem3_sdsn;
    flag = (Model_01_work_2017_contr_DW.obj.isInitialized == 1);
    if (flag) {
      Model_01_work_2017_contr_DW.obj.TunablePropsChanged = true;
    }

    Model_01_work_2017_contr_DW.obj.betta =
      Model_01_work_2017_contr_P.MATLABSystem3_betta;
    flag = (Model_01_work_2017_contr_DW.obj.isInitialized == 1);
    if (flag) {
      Model_01_work_2017_contr_DW.obj.TunablePropsChanged = true;
    }

    Model_01_work_2017_contr_DW.obj.sm_bet =
      Model_01_work_2017_contr_P.MATLABSystem3_sm_bet;
    flag = (Model_01_work_2017_contr_DW.obj.isInitialized == 1);
    if (flag) {
      Model_01_work_2017_contr_DW.obj.TunablePropsChanged = true;
    }

    Model_01_work_2017_contr_DW.obj.alfa =
      Model_01_work_2017_contr_P.MATLABSystem3_alfa;
    flag = (Model_01_work_2017_contr_DW.obj.isInitialized == 1);
    if (flag) {
      Model_01_work_2017_contr_DW.obj.TunablePropsChanged = true;
    }

    Model_01_work_2017_contr_DW.obj.sm_alfa =
      Model_01_work_2017_contr_P.MATLABSystem3_sm_alfa;
    flag = (Model_01_work_2017_contr_DW.obj.isInitialized == 1);
    if (flag) {
      Model_01_work_2017_contr_DW.obj.TunablePropsChanged = true;
    }

    Model_01_work_2017_contr_DW.obj.kStd =
      Model_01_work_2017_contr_P.MATLABSystem3_kStd;
    flag = (Model_01_work_2017_contr_DW.obj.isInitialized == 1);
    if (flag) {
      Model_01_work_2017_contr_DW.obj.TunablePropsChanged = true;
    }

    Model_01_work_2017_contr_DW.obj.alfaExp =
      Model_01_work_2017_contr_P.MATLABSystem3_alfaExp;
    Model_01_work_2017_contr_DW.obj.isInitialized = 1;

    /*  Validate related or interdependent property values */
    /*         %% Advanced functions */
    /*  , ss */
    /*  Validate inputs to the step method at initialization */
    /*  Perform one-time calculations, such as computing constants */
    Model_01_work_2017_contr_DW.obj.TunablePropsChanged = false;

    /* End of Start for MATLABSystem: '<Root>/MATLAB System3' */
  }

  /* Start for MATLABSystem: '<Root>/MATLAB System3' incorporates:
   *  InitializeConditions for MATLABSystem: '<Root>/MATLAB System3'
   */
  /*  Initialize / reset discrete-state properties */
  memset(&Model_01_work_2017_contr_DW.obj.dSlipp[0], 0, 30U * sizeof(real_T));
}

/* Model terminate function */
void Model_01_work_2017_contr_terminate(void)
{
  Model_01_wor_MATLABSystem2_Term(&Model_01_work_2017_contr_DW.MATLABSystem);
  Model_01_wor_MATLABSystem2_Term(&Model_01_work_2017_contr_DW.MATLABSystem1);
  Model_01_wor_MATLABSystem2_Term(&Model_01_work_2017_contr_DW.MATLABSystem2);

  /* Start for MATLABSystem: '<Root>/MATLAB System3' incorporates:
   *  Terminate for MATLABSystem: '<Root>/MATLAB System3'
   */
  if (Model_01_work_2017_contr_DW.obj.isInitialized == 1) {
    Model_01_work_2017_contr_DW.obj.isInitialized = 2;
  }

  /* End of Start for MATLABSystem: '<Root>/MATLAB System3' */
}
