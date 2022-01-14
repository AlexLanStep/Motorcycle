#include "Moment_BASA_2017_capi_host.h"
static Moment_BASA_2017_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        Moment_BASA_2017_host_InitializeDataMapInfo(&(root), "Moment_BASA_2017");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
