#include "__cf_MixailFiltr_01.h"
#include "rt_logging_mmi.h"
#include "MixailFiltr_01_capi.h"
#include <math.h>
#include "MixailFiltr_01.h"
#include "MixailFiltr_01_private.h"
#include "MixailFiltr_01_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 1 , & stopRequested ) ; }
rtExtModeShutdown ( 1 ) ; } const int_T gblNumToFiles = 0 ; const int_T
gblNumFrFiles = 0 ; const int_T gblNumFrWksBlocks = 1 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 2 ; const char_T
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
"slprj\\raccel\\MixailFiltr_01\\MixailFiltr_01_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; void MdlStart ( void ) { int32_T k ; static const nr5np2tfz3 tmp =
{ 0.0 , 0.0 , 0.0 } ; static const real_T tmp_p [ 151 ] = {
1809.0424144560632 , 1636.984429995927 , 1481.299927584545 ,
1340.4307643944169 , 1212.9670744925763 , 1097.6331584284585 ,
993.27471560502534 , 898.84729165041676 , 813.4058251675433 ,
736.09518924197323 , 666.14163304436181 , 602.84503787208223 ,
545.571910125929 , 493.74904109325632 , 446.85777008251677 ,
404.42879349273511 , 366.03746786532861 , 331.29955990964856 ,
299.86740096706058 , 271.42640742615276 , 245.69193226422038 ,
222.40641620418717 , 201.33680997479183 , 182.27224187515122 ,
165.02190729990167 , 149.4131591025766 , 135.28977968493552 ,
122.51041751873485 , 110.94717245212343 , 100.48431564193386 ,
91.017131300521811 , 82.450868664968141 , 74.699793699595787 ,
67.686331040925154 , 61.34028759736195 , 55.598150033144215 ,
50.402449105530195 , 45.701184493300815 , 41.4473043600674 ,
37.598234443677974 , 34.115451958692312 , 30.964100047396997 ,
28.112638920657893 , 25.532530197109352 , 23.197951281441636 ,
21.085536923187668 , 19.17414536944306 , 17.444646771097048 ,
15.879731724872837 , 14.463738035001692 , 13.182493960703473 ,
12.023176380641601 , 10.974182454814718 , 10.025013499434118 ,
9.1661699125676463 , 8.3890560989306469 , 7.6858944422792659 ,
7.0496474644129421 , 6.4739473917272017 , 5.9530324243951167 ,
5.4816890703380654 , 5.0551999668446754 , 4.6692966676192444 ,
4.3201169227365472 , 4.004166023946433 , 3.7182818284590446 ,
3.459603111156949 , 3.2255409284924665 , 3.0137527074704757 ,
2.8221188003905082 , 2.6487212707001273 , 2.4918246976412708 ,
2.3498588075760036 , 2.22140275816017 , 2.1051709180756477 , 2.0 ,
1.9048374180359595 , 1.8187307530779817 , 1.7408182206817178 ,
1.6703200460356391 , 1.6065306597126339 , 1.5488116360940267 ,
1.4965853037914099 , 1.4493289641172218 , 1.4065696597405992 ,
1.3678794411714423 , 1.3328710836980795 , 1.3011942119122022 ,
1.2725317930340125 , 1.2465969639416064 , 1.22313016014843 ,
1.2018965179946552 , 1.1826835240527345 , 1.1652988882215867 ,
1.1495686192226351 , 1.1353352832366128 , 1.1224564282529819 ,
1.1108031583623339 , 1.1002588437228038 , 1.0907179532894125 ,
1.0820849986238987 , 1.0742735782143338 , 1.0672055127397497 ,
1.0608100626252179 , 1.0550232200564071 , 1.0497870683678638 ,
1.0450492023935578 , 1.0407622039783662 , 1.03688316740124 ,
1.0333732699603262 , 1.0301973834223186 , 1.0273237224472926 ,
1.0247235264703394 , 1.0223707718561656 , 1.0202419114458043 ,
1.0183156388887342 , 1.0165726754017612 , 1.0149955768204777 ,
1.013568559012201 , 1.0122773399030685 , 1.0111089965382423 ,
1.0100518357446335 , 1.0090952771016959 , 1.00822974704902 ,
1.0074465830709243 , 1.0067379469990854 , 1.0060967465655157 ,
1.0055165644207609 , 1.0049915939069103 , 1.0045165809426126 ,
1.004086771438464 , 1.0036978637164828 , 1.0033459654574712 ,
1.0030275547453757 , 1.0027394448187683 , 1.0024787521766663 ,
1.0022428677194859 , 1.0020294306362958 , 1.0018363047770289 ,
1.001661557273174 , 1.0015034391929776 , 1.0013603680375478 ,
1.0012309119026734 , 1.0011137751478447 , 1.0010077854290484 ,
1.0009118819655545 , 1.0008251049232659 , 1.0007465858083766 ,
1.0006755387751938 , 1.0006112527611295 , 1.0005530843701478 } ; { void * *
slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; void * r2 = ( NULL ) ; void *
* pOSigstreamManagerAddr = ( NULL ) ; const char *
errorCreatingOSigstreamManager = ( NULL ) ; const char *
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
fromwksInfo -> origWorkspaceVarName = "tImpuls" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace_Data0 ; fromwksInfo -> nDataPoints =
350 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace_Time0 ; rtDW .
gj0s2nnyzv . TimePtr = fromwksInfo -> time ; rtDW . gj0s2nnyzv . DataPtr =
fromwksInfo -> data ; rtDW . gj0s2nnyzv . RSimInfoPtr = fromwksInfo ; } rtDW
. aaa20z1q0p . PrevIndex = 0 ; } rtDW . kyf3b2sjyq . M1count = 151.0 ; rtDW .
kyf3b2sjyq . kxx = 0.0 ; rtDW . kyf3b2sjyq . ind = tmp ; rtDW . kyf3b2sjyq .
isInitialized = 0 ; rtDW . k4pqcmyyl5 = true ; rtDW . kyf3b2sjyq .
isInitialized = 1 ; rtDW . kyf3b2sjyq . u_sig_k = 0.0 ; for ( k = 0 ; k < 151
; k ++ ) { rtDW . kyf3b2sjyq . M1 [ k ] = 1.0 / tmp_p [ k ] ; } rtDW .
kyf3b2sjyq . nEma = 250.0 ; rtDW . kyf3b2sjyq . alfa_ema = 2.0 / ( rtDW .
kyf3b2sjyq . nEma + 1.0 ) ; { bool externalInputIsInDatasetFormat = false ;
void * pISigstreamManager = rt_GetISigstreamManager ( ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} } void MdlOutputs ( int_T tid ) { real_T varargout_3 ; real_T varargout_2 ;
real_T varargout_1 ; { real_T * pDataValues = ( real_T * ) rtDW . gj0s2nnyzv
. DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW . gj0s2nnyzv . TimePtr ;
int_T currTimeIndex = rtDW . aaa20z1q0p . PrevIndex ; real_T t =
ssGetTaskTime ( rtS , 0 ) ; int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . gj0s2nnyzv . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <=
pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . aaa20z1q0p . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { rtB . p1qmcfc30a =
pDataValues [ currTimeIndex ] ; } else { rtB . p1qmcfc30a = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; rtB . p1qmcfc30a = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ;
pDataValues += numPoints ; } } } varargout_1 = 0.0 ; varargout_2 = rtDW .
kyf3b2sjyq . ind . i ; varargout_3 = rtDW . kyf3b2sjyq . u_sig_k ; if ( ! (
rtB . p1qmcfc30a == 0.0 ) ) { rtDW . kyf3b2sjyq . kxx ++ ; varargout_3 = rtDW
. kyf3b2sjyq . kxx ; if ( rtDW . kyf3b2sjyq . ind . i < rtDW . kyf3b2sjyq .
M1count ) { rtDW . kyf3b2sjyq . ind . i ++ ; varargout_2 = rtDW . kyf3b2sjyq
. ind . i ; rtDW . kyf3b2sjyq . u_sig_k = rtDW . kyf3b2sjyq . M1 [ ( int32_T
) muDoubleScalarMax ( muDoubleScalarMin ( rtDW . kyf3b2sjyq . ind . i , rtDW
. kyf3b2sjyq . M1count ) , 1.0 ) - 1 ] ; varargout_3 = rtDW . kyf3b2sjyq .
u_sig_k ; varargout_1 = rtDW . kyf3b2sjyq . u_sig_k * 12.0 ; } else {
varargout_1 = rtDW . kyf3b2sjyq . M1 [ ( int32_T ) rtDW . kyf3b2sjyq .
M1count - 1 ] * 12.0 ; } } rtB . n3lntb2f5q = varargout_1 ; rtB . l03f01cll4
= varargout_2 ; rtB . bkzkhyvz53 = varargout_3 ; rtB . awexmyqu3m = 0.0 ;
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { UNUSED_PARAMETER
( tid ) ; } void MdlUpdateTID1 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
void MdlTerminate ( void ) { rt_FREE ( rtDW . gj0s2nnyzv . RSimInfoPtr ) ; if
( rtDW . kyf3b2sjyq . isInitialized == 1 ) { rtDW . kyf3b2sjyq .
isInitialized = 2 ; } { if ( rt_slioCatalogue ( ) != ( NULL ) ) { void * *
slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; rtwCreateSigstreamSlioClient (
rt_GetOSigstreamManager ( ) , rtwGetPointerFromUniquePtr ( rt_slioCatalogue (
) ) ) ; rtwSaveDatasetsToMatFile ( rtwGetPointerFromUniquePtr (
rt_slioCatalogue ( ) ) , rt_GetMatSigstreamLoggingFileName ( ) ) ;
rtwOSigstreamManagerDestroyInstance ( rt_GetOSigstreamManager ( ) ) ;
rtwTerminateSlioCatalogue ( slioCatalogueAddr ) ; * slioCatalogueAddr = (
NULL ) ; } } } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS ,
0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough
( rtS , 0 ) ; ssSetNumSampleTimes ( rtS , 1 ) ; ssSetNumBlocks ( rtS , 5 ) ;
ssSetNumBlockIO ( rtS , 5 ) ; ssSetNumBlockParams ( rtS , 700 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.01 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; } void raccel_set_checksum ( SimStruct *
rtS ) { ssSetChecksumVal ( rtS , 0 , 1495550621U ) ; ssSetChecksumVal ( rtS ,
1 , 1893309049U ) ; ssSetChecksumVal ( rtS , 2 , 3515473509U ) ;
ssSetChecksumVal ( rtS , 3 , 238414985U ) ; } SimStruct *
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
& dtInfo ) ; dtInfo . numDataTypes = 16 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; } MixailFiltr_01_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"MixailFiltr_01" ) ; ssSetPath ( rtS , "MixailFiltr_01" ) ; ssSetTStart ( rtS
, 0.0 ) ; ssSetTFinal ( rtS , 350.0 ) ; ssSetStepSize ( rtS , 0.01 ) ;
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
1495550621U ) ; ssSetChecksumVal ( rtS , 1 , 1893309049U ) ; ssSetChecksumVal
( rtS , 2 , 3515473509U ) ; ssSetChecksumVal ( rtS , 3 , 238414985U ) ; {
static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static
RTWExtModeInfo rt_ExtModeInfo ; static const sysRanDType * systemRan [ 2 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = &
rtAlwaysEnabled ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) ,
& ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo
( rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS
) , ssGetTPtr ( rtS ) ) ; } return rtS ; } const int_T gblParameterTuningTid
= 1 ; void MdlOutputsParameterSampleTime ( int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
