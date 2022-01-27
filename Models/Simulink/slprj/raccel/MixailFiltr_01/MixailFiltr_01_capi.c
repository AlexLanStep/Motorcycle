#include "__cf_MixailFiltr_01.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "MixailFiltr_01_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "MixailFiltr_01.h"
#include "MixailFiltr_01_capi.h"
#include "MixailFiltr_01_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"MixailFiltr_01/From Workspace" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 1 , 1 , TARGET_STRING ( "MixailFiltr_01/MATLAB System1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 2 , 1 , TARGET_STRING (
"MixailFiltr_01/MATLAB System1" ) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0
} , { 3 , 1 , TARGET_STRING ( "MixailFiltr_01/MATLAB System1" ) ,
TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 0 } , { 4 , 1 , TARGET_STRING (
"MixailFiltr_01/MATLAB System1" ) , TARGET_STRING ( "" ) , 3 , 0 , 0 , 0 , 0
} , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 5 , TARGET_STRING (
"MixailFiltr_01/From Workspace" ) , TARGET_STRING ( "Time0" ) , 0 , 1 , 0 } ,
{ 6 , TARGET_STRING ( "MixailFiltr_01/From Workspace" ) , TARGET_STRING (
"Data0" ) , 0 , 1 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static
const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , ( NULL ) , 0 ,
0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . p1qmcfc30a , & rtB . n3lntb2f5q ,
& rtB . l03f01cll4 , & rtB . bkzkhyvz53 , & rtB . awexmyqu3m , & rtP .
FromWorkspace_Time0 [ 0 ] , & rtP . FromWorkspace_Data0 [ 0 ] , } ; static
int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 350 , 1 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.01 , 0.0 } ; static const rtwCAPI_FixPtMap
rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , 0 }
, } ; static const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const
void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [
1 ] , 0 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { {
rtBlockSignals , 5 , ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockParameters , 2
, rtModelParameters , 0 } , { ( NULL ) , 0 } , { rtDataTypeMap ,
rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap ,
rtDimensionArray } , "float" , { 1495550621U , 1893309049U , 3515473509U ,
238414985U } , ( NULL ) , 0 , 0 } ; const rtwCAPI_ModelMappingStaticInfo *
MixailFiltr_01_GetCAPIStaticMap ( ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void MixailFiltr_01_InitializeDataMapInfo ( ) { rtwCAPI_SetVersion ( ( *
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
void MixailFiltr_01_host_InitializeDataMapInfo (
MixailFiltr_01_host_DataMapInfo_T * dataMap , const char * path ) {
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