#include "__cf_Moment_BASA_2017.h"
#include "rt_logging_mmi.h"
#include "Moment_BASA_2017_capi.h"
#include <math.h>
#include "Moment_BASA_2017.h"
#include "Moment_BASA_2017_private.h"
#include "Moment_BASA_2017_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; } const int_T gblNumToFiles = 0 ; const int_T
gblNumFrFiles = 0 ; const int_T gblNumFrWksBlocks = 1 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 1 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "8.12 (R2017a) 16-Feb-2017" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\Moment_BASA_2017\\Moment_BASA_2017_Jpattern.mat" ; const
int_T gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; static real_T dlcdpa3qdp ( const real_T x_data [ ] , const int32_T
x_size [ 2 ] ) ; static void ay2xdqpfc2 ( const real_T a_data [ ] , const
int32_T a_size [ 2 ] , real_T y_data [ ] , int32_T y_size [ 2 ] ) ; static
real_T dlcdpa3qdp ( const real_T x_data [ ] , const int32_T x_size [ 2 ] ) {
real_T y ; int32_T k ; if ( x_size [ 1 ] == 0 ) { y = 0.0 ; } else { y =
x_data [ 0 ] ; for ( k = 1 ; k + 1 <= x_size [ 1 ] ; k ++ ) { y += x_data [ k
] ; } } return y ; } static void ay2xdqpfc2 ( const real_T a_data [ ] , const
int32_T a_size [ 2 ] , real_T y_data [ ] , int32_T y_size [ 2 ] ) { int32_T k
; y_size [ 0 ] = 1 ; y_size [ 1 ] = a_size [ 1 ] ; for ( k = 0 ; k + 1 <=
a_size [ 1 ] ; k ++ ) { y_data [ k ] = a_data [ k ] * a_data [ k ] ; } } void
MdlStart ( void ) { { void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ;
void * r2 = ( NULL ) ; void * * pOSigstreamManagerAddr = ( NULL ) ; const
char * errorCreatingOSigstreamManager = ( NULL ) ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ) ; if (
errorCreatingOSigstreamManager != ( NULL ) ) { * pOSigstreamManagerAddr = (
NULL ) ; ssSetErrorStatus ( rtS , errorCreatingOSigstreamManager ) ; return ;
} } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1
, sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "tMoment" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace_Data0 ; fromwksInfo -> nDataPoints =
9000 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace_Time0 ; rtDW .
kjz4a5zlev . TimePtr = fromwksInfo -> time ; rtDW . kjz4a5zlev . DataPtr =
fromwksInfo -> data ; rtDW . kjz4a5zlev . RSimInfoPtr = fromwksInfo ; } rtDW
. gwu30p5lw4 . PrevIndex = 0 ; } memset ( & rtDW . frz31z3ma1 . m [ 0 ] , 0 ,
200U * sizeof ( real_T ) ) ; rtDW . frz31z3ma1 . isInitialized = 0 ; rtDW .
frz31z3ma1 . NCount = 200.0 ; rtDW . frz31z3ma1 . nm = 20.0 ; rtDW .
kldnqzhn5o = true ; rtDW . frz31z3ma1 . isInitialized = 1 ; { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } } void MdlOutputs ( int_T tid ) {
cs1kfuoqdv * obj ; real_T n ; real_T x0_data [ 200 ] ; real_T xsum ; real_T
z0 ; real_T yy_data [ 200 ] ; real_T ysum ; int32_T i ; int32_T i_p ; real_T
tmp ; real_T x0_data_p [ 200 ] ; int32_T i_e ; int32_T loop_ub ; int32_T
x0_size [ 2 ] ; int32_T yy_size [ 2 ] ; int32_T x0_size_p [ 2 ] ; int32_T
x0_size_e [ 2 ] ; { real_T * pDataValues = ( real_T * ) rtDW . kjz4a5zlev .
DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW . kjz4a5zlev . TimePtr ;
int_T currTimeIndex = rtDW . gwu30p5lw4 . PrevIndex ; real_T t =
ssGetTaskTime ( rtS , 0 ) ; int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . kjz4a5zlev . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <=
pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . gwu30p5lw4 . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { rtB . j44oo2nwfp =
pDataValues [ currTimeIndex ] ; } else { rtB . j44oo2nwfp = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; rtB . j44oo2nwfp = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ;
pDataValues += numPoints ; } } } rtB . epkse5fmgz = rtB . j44oo2nwfp ; obj =
& rtDW . frz31z3ma1 ; n = muDoubleScalarMax ( muDoubleScalarMin ( rtB .
mu4wwayn2k , 200.0 ) , 6.0 ) ; rtDW . frz31z3ma1 . nm = n ; ysum = rtDW .
frz31z3ma1 . NCount ; if ( 2.0 > ysum ) { i_p = 0 ; i = 0 ; } else { i_p = 1
; i = ( int32_T ) ysum ; } loop_ub = i - i_p ; for ( i_e = 0 ; i_e < loop_ub
; i_e ++ ) { x0_data [ i_e ] = rtDW . frz31z3ma1 . m [ i_p + i_e ] ; }
loop_ub = i - i_p ; for ( i_p = 0 ; i_p < loop_ub ; i_p ++ ) { obj -> m [ i_p
] = x0_data [ i_p ] ; } obj -> m [ ( int32_T ) obj -> NCount - 1 ] = rtB .
epkse5fmgz ; if ( obj -> NCount != rtB . mu4wwayn2k ) { obj -> NCount = rtB .
mu4wwayn2k ; } x0_size [ 0 ] = 1 ; x0_size [ 1 ] = ( int32_T )
muDoubleScalarFloor ( n - 1.0 ) + 1 ; loop_ub = ( int32_T )
muDoubleScalarFloor ( n - 1.0 ) ; for ( i_p = 0 ; i_p <= loop_ub ; i_p ++ ) {
x0_data [ i_p ] = i_p ; } x0_size_e [ 0 ] = 1 ; x0_size_e [ 1 ] = ( int32_T )
n ; loop_ub = ( int32_T ) n ; for ( i_p = 0 ; i_p < loop_ub ; i_p ++ ) {
x0_data_p [ i_p ] = x0_data [ i_p ] ; } xsum = dlcdpa3qdp ( x0_data_p ,
x0_size_e ) ; ay2xdqpfc2 ( x0_data , x0_size , x0_data_p , x0_size_e ) ; z0 =
dlcdpa3qdp ( x0_data_p , x0_size_e ) / ( xsum * xsum ) ; xsum = 1.0 / xsum ;
ysum = ( obj -> NCount - obj -> nm ) + 1.0 ; tmp = obj -> NCount ; if ( ysum
> tmp ) { i_p = 0 ; i = 0 ; } else { i_p = ( int32_T ) ysum - 1 ; i = (
int32_T ) tmp ; } yy_size [ 0 ] = 1 ; yy_size [ 1 ] = i - i_p ; loop_ub = i -
i_p ; for ( i = 0 ; i < loop_ub ; i ++ ) { yy_data [ i ] = obj -> m [ i_p + i
] ; } ysum = dlcdpa3qdp ( yy_data , yy_size ) ; x0_size_p [ 0 ] = 1 ;
x0_size_p [ 1 ] = x0_size [ 1 ] ; loop_ub = x0_size [ 1 ] ; for ( i_p = 0 ;
i_p < loop_ub ; i_p ++ ) { x0_data_p [ i_p ] = x0_data [ i_p ] * yy_data [
i_p ] ; } z0 = 1.0 / ( 1.0 - z0 * n ) * ( dlcdpa3qdp ( x0_data_p , x0_size_p
) * xsum - z0 * ysum ) ; rtB . ei3yovkn0u = ( ysum - z0 * n ) * xsum * ( n -
muDoubleScalarRound ( n / 3.0 ) ) + z0 ; rtB . cemcwpdwzd = n ;
UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID2 ( int_T tid ) { rtB .
mu4wwayn2k = muDoubleScalarMin ( muDoubleScalarMax ( rtP . nPoint_Value , rtP
. nPoint1_Value ) , rtP . nPoint2_Value ) ; UNUSED_PARAMETER ( tid ) ; } void
MdlUpdate ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2 (
int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlTerminate ( void ) {
rt_FREE ( rtDW . kjz4a5zlev . RSimInfoPtr ) ; if ( rtDW . frz31z3ma1 .
isInitialized == 1 ) { rtDW . frz31z3ma1 . isInitialized = 2 ; } { if (
rt_slioCatalogue ( ) != ( NULL ) ) { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; rtwCreateSigstreamSlioClient (
rt_GetOSigstreamManager ( ) , rtwGetPointerFromUniquePtr ( rt_slioCatalogue (
) ) ) ; rtwSaveDatasetsToMatFile ( rtwGetPointerFromUniquePtr (
rt_slioCatalogue ( ) ) , rt_GetMatSigstreamLoggingFileName ( ) ) ;
rtwOSigstreamManagerDestroyInstance ( rt_GetOSigstreamManager ( ) ) ;
rtwTerminateSlioCatalogue ( slioCatalogueAddr ) ; * slioCatalogueAddr = (
NULL ) ; } } } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS ,
0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough
( rtS , 0 ) ; ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 12 ) ;
ssSetNumBlockIO ( rtS , 5 ) ; ssSetNumBlockParams ( rtS , 18004 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.01 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 0.0 ) ; } void raccel_set_checksum ( SimStruct *
rtS ) { ssSetChecksumVal ( rtS , 0 , 3722520344U ) ; ssSetChecksumVal ( rtS ,
1 , 3591558024U ) ; ssSetChecksumVal ( rtS , 2 , 1201126038U ) ;
ssSetChecksumVal ( rtS , 3 , 2853595024U ) ; } SimStruct *
raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo ; ( void )
memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( (
char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr (
rtS , & mdlInfo ) ; { static time_T mdlPeriod [ NSAMPLE_TIMES ] ; static
time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T mdlTaskTimes [
NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ; static int_T
mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T mdlTNextWasAdjustedPtr [
NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits [ NSAMPLE_TIMES *
NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [ NSAMPLE_TIMES ] ; {
int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) { mdlPeriod [ i ] = 0.0 ;
mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ; mdlTsMap [ i ] = i ;
mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS , & mdlPeriod [ 0 ] )
; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr (
rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , & mdlTaskTimes [ 0 ] ) ;
ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ; ssSetTNextWasAdjustedPtr
( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ; ssSetPerTaskSampleHitsPtr ( rtS ,
& mdlPerTaskSampleHits [ 0 ] ) ; ssSetTimeOfNextSampleHitPtr ( rtS , &
mdlTimeOfNextSampleHit [ 0 ] ) ; } ssSetSolverMode ( rtS ,
SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS , ( ( void * ) & rtB ) ) ;
( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; }
ssSetDefaultParam ( rtS , ( real_T * ) & rtP ) ; { void * dwork = ( void * )
& rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 ,
sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset ( (
char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS ,
& dtInfo ) ; dtInfo . numDataTypes = 15 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; } Moment_BASA_2017_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"Moment_BASA_2017" ) ; ssSetPath ( rtS , "Moment_BASA_2017" ) ; ssSetTStart (
rtS , 0.0 ) ; ssSetTFinal ( rtS , 9000.0 ) ; ssSetStepSize ( rtS , 0.01 ) ;
ssSetFixedStepSize ( rtS , 0.01 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) ,
( NULL ) ) ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
ssSolverInfo slvrInfo ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "FixedStepDiscrete" ) ; ssSetVariableStepSolver ( rtS
, 0 ) ; ssSetSolverConsistencyChecking ( rtS , 0 ) ;
ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ; ssSetSolverRobustResetMethod (
rtS , 0 ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetTNextTid ( rtS , INT_MIN ) ;
ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; } ssSetChecksumVal ( rtS , 0 ,
3722520344U ) ; ssSetChecksumVal ( rtS , 1 , 3591558024U ) ; ssSetChecksumVal
( rtS , 2 , 1201126038U ) ; ssSetChecksumVal ( rtS , 3 , 2853595024U ) ; {
static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static
RTWExtModeInfo rt_ExtModeInfo ; static const sysRanDType * systemRan [ 2 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = &
rtAlwaysEnabled ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) ,
& ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo
( rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS
) , ssGetTPtr ( rtS ) ) ; } return rtS ; } const int_T gblParameterTuningTid
= 2 ; void MdlOutputsParameterSampleTime ( int_T tid ) { MdlOutputsTID2 ( tid
) ; }
