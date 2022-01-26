#include "MixailFiltr_01_capi_host.h"
static MixailFiltr_01_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        MixailFiltr_01_host_InitializeDataMapInfo(&(root), "MixailFiltr_01");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
