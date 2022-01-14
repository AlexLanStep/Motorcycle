#include "__cf_Moment_BASA_2017.h"
#ifndef RTW_HEADER_Moment_BASA_2017_h_
#define RTW_HEADER_Moment_BASA_2017_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef Moment_BASA_2017_COMMON_INCLUDES_
#define Moment_BASA_2017_COMMON_INCLUDES_
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
#include "Moment_BASA_2017_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME Moment_BASA_2017
#define NSAMPLE_TIMES (3) 
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
typedef struct { real_T j44oo2nwfp ; real_T epkse5fmgz ; real_T mu4wwayn2k ;
real_T ei3yovkn0u ; real_T cemcwpdwzd ; } B ; typedef struct { cs1kfuoqdv
frz31z3ma1 ; struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ;
} kjz4a5zlev ; struct { void * LoggedData [ 2 ] ; } gj4if4qtoj ; struct {
void * LoggedData [ 2 ] ; } mp5pi4ku5h ; void * lgbb3kzhq1 ; struct { int_T
PrevIndex ; } gwu30p5lw4 ; boolean_T kldnqzhn5o ; } DW ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T
FromWorkspace_Time0 [ 9000 ] ; real_T FromWorkspace_Data0 [ 9000 ] ; real_T
nPoint_Value ; real_T nPoint1_Value ; real_T nPoint2_Value ; real_T
CanError_Value ; } ; extern const char * RT_MEMORY_ALLOCATION_ERROR ; extern
B rtB ; extern DW rtDW ; extern P rtP ; extern const
rtwCAPI_ModelMappingStaticInfo * Moment_BASA_2017_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
size_t gblCurrentSFcnIdx ; extern size_t * gblChildIdxToInfoIdx ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
