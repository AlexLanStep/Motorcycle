#include "__cf_MixailFiltr_01.h"
#ifndef RTW_HEADER_MixailFiltr_01_h_
#define RTW_HEADER_MixailFiltr_01_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef MixailFiltr_01_COMMON_INCLUDES_
#define MixailFiltr_01_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "MixailFiltr_01_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME MixailFiltr_01
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (5) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T p1qmcfc30a ; real_T n3lntb2f5q ; real_T l03f01cll4 ;
real_T bkzkhyvz53 ; real_T awexmyqu3m ; } B ; typedef struct { pj5ytval2f
kyf3b2sjyq ; struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ;
} gj0s2nnyzv ; struct { void * LoggedData [ 3 ] ; } clnv2h1ae5 ; struct {
void * LoggedData [ 3 ] ; } lc3owvgl4m ; void * jfkyuweugx ; struct { int_T
PrevIndex ; } aaa20z1q0p ; boolean_T k4pqcmyyl5 ; } DW ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T
FromWorkspace_Time0 [ 350 ] ; real_T FromWorkspace_Data0 [ 350 ] ; } ; extern
const char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern DW rtDW ;
extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo *
MixailFiltr_01_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ;
extern const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern
const int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ;
extern const char * gblInportFileName ; extern const int_T
gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern const
int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern size_t gblCurrentSFcnIdx ;
extern size_t * gblChildIdxToInfoIdx ; extern DataMapInfo * rt_dataMapInfoPtr
; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs (
int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T tid ) ; void
MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( void ) ;
#endif
