#include "__cf_Moment_BASA_2017.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "Moment_BASA_2017_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "Moment_BASA_2017.h"
#include "Moment_BASA_2017_capi.h"
#include "Moment_BASA_2017_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"Moment_BASA_2017/From Workspace" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
0 } , { 1 , 0 , TARGET_STRING ( "Moment_BASA_2017/Max1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 2 , 0 , TARGET_STRING (
"Moment_BASA_2017/Zero-Order Hold" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
2 } , { 3 , 1 , TARGET_STRING ( "Moment_BASA_2017/MATLAB System4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 4 , 1 , TARGET_STRING (
"Moment_BASA_2017/MATLAB System4" ) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 ,
2 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 5 , TARGET_STRING (
"Moment_BASA_2017/CanError" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 6
, TARGET_STRING ( "Moment_BASA_2017/nPoint" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 7 , TARGET_STRING ( "Moment_BASA_2017/nPoint1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 8 , TARGET_STRING (
"Moment_BASA_2017/nPoint2" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 9
, TARGET_STRING ( "Moment_BASA_2017/From Workspace" ) , TARGET_STRING (
"Time0" ) , 0 , 1 , 0 } , { 10 , TARGET_STRING (
"Moment_BASA_2017/From Workspace" ) , TARGET_STRING ( "Data0" ) , 0 , 1 , 0 }
, { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , ( NULL ) , 0 , 0 , 0
} } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . j44oo2nwfp , & rtB . mu4wwayn2k ,
& rtB . epkse5fmgz , & rtB . ei3yovkn0u , & rtB . cemcwpdwzd , & rtP .
CanError_Value , & rtP . nPoint_Value , & rtP . nPoint1_Value , & rtP .
nPoint2_Value , & rtP . FromWorkspace_Time0 [ 0 ] , & rtP .
FromWorkspace_Data0 [ 0 ] , } ; static int32_T * rtVarDimsAddrMap [ ] = { (
NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 9000 , 1 } ; static const
real_T rtcapiStoredFloats [ ] = { 0.0 , 0.01 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } , { ( NULL ) , ( NULL ) ,
2 , 0 } , { ( const void * ) & rtcapiStoredFloats [ 1 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , 1 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 5 , ( NULL ) , 0 , ( NULL ) , 0 } , {
rtBlockParameters , 6 , rtModelParameters , 0 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 3722520344U , 3591558024U , 1201126038U ,
2853595024U } , ( NULL ) , 0 , 0 } ; const rtwCAPI_ModelMappingStaticInfo *
Moment_BASA_2017_GetCAPIStaticMap ( ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void Moment_BASA_2017_InitializeDataMapInfo ( ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void Moment_BASA_2017_host_InitializeDataMapInfo (
Moment_BASA_2017_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
