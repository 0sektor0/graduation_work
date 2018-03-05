/*
 * MATLAB Compiler: 6.5 (R2017b)
 * Date: Mon Mar  5 02:44:58 2018
 * Arguments:
 * "-B""macro_default""-W""lib:libNarxStatSystem""-T""link:lib""-d""/home/sektor
 * /mydocs/projects/MatLab/VKR/libNarxStatSystem/for_testing""-v""/home/sektor/m
 * ydocs/projects/MatLab/VKR/CalcShewhart.m""/home/sektor/mydocs/projects/MatLab
 * /VKR/CheckNormality.m""/home/sektor/mydocs/projects/MatLab/VKR/EppsPallyCrite
 * rion.m""/home/sektor/mydocs/projects/MatLab/VKR/GetSample.m""/home/sektor/myd
 * ocs/projects/MatLab/VKR/GiriCriterion.m""/home/sektor/mydocs/projects/MatLab/
 * VKR/HegazyGreenCriterion.m""/home/sektor/mydocs/projects/MatLab/VKR/ShapiroWe
 * akCriterion.m""/home/sektor/mydocs/projects/MatLab/VKR/SimulateNarx.m"
 */

#include <stdio.h>
#define EXPORTING_libNarxStatSystem 1
#include "libNarxStatSystem.h"

static HMCRINSTANCE _mcr_inst = NULL;

#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultPrintHandler(const char *s)
{
    return mclWrite(1 /* stdout */, s, sizeof(char)*strlen(s));
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultErrorHandler(const char *s)
{
    int written = 0;
    size_t len = 0;
    len = strlen(s);
    written = mclWrite(2 /* stderr */, s, sizeof(char)*len);
    if (len > 0 && s[ len-1 ] != '\n')
        written += mclWrite(2 /* stderr */, "\n", sizeof(char));
    return written;
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_libNarxStatSystem_C_API
#define LIB_libNarxStatSystem_C_API /* No special import/export declaration */
#endif

LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV libNarxStatSystemInitializeWithHandlers(
    mclOutputHandlerFcn error_handler,
    mclOutputHandlerFcn print_handler)
{
    int bResult = 0;
    if (_mcr_inst != NULL)
        return true;
    if (!mclmcrInitialize())
        return false;
    {
        mclCtfStream ctfStream = 
            mclGetEmbeddedCtfStream((void *)(libNarxStatSystemInitializeWithHandlers));
        if (ctfStream) {
            bResult = mclInitializeComponentInstanceEmbedded(&_mcr_inst,
                                                             error_handler, 
                                                             print_handler,
                                                             ctfStream);
            mclDestroyStream(ctfStream);
        } else {
            bResult = 0;
        }
    }  
    if (!bResult)
    return false;
    return true;
}

LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV libNarxStatSystemInitialize(void)
{
    return libNarxStatSystemInitializeWithHandlers(mclDefaultErrorHandler, 
                                                 mclDefaultPrintHandler);
}

LIB_libNarxStatSystem_C_API 
void MW_CALL_CONV libNarxStatSystemTerminate(void)
{
    if (_mcr_inst != NULL)
        mclTerminateInstance(&_mcr_inst);
}

LIB_libNarxStatSystem_C_API 
void MW_CALL_CONV libNarxStatSystemPrintStackTrace(void) 
{
    char** stackTrace;
    int stackDepth = mclGetStackTrace(&stackTrace);
    int i;
    for(i=0; i<stackDepth; i++)
    {
        mclWrite(2 /* stderr */, stackTrace[i], sizeof(char)*strlen(stackTrace[i]));
        mclWrite(2 /* stderr */, "\n", sizeof(char)*strlen("\n"));
    }
    mclFreeStackTrace(&stackTrace, stackDepth);
}


LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV mlxCalcShewhart(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "CalcShewhart", nlhs, plhs, nrhs, prhs);
}

LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV mlxCheckNormality(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "CheckNormality", nlhs, plhs, nrhs, prhs);
}

LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV mlxEppsPallyCriterion(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                        *prhs[])
{
    return mclFeval(_mcr_inst, "EppsPallyCriterion", nlhs, plhs, nrhs, prhs);
}

LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV mlxGetSample(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "GetSample", nlhs, plhs, nrhs, prhs);
}

LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV mlxGiriCriterion(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "GiriCriterion", nlhs, plhs, nrhs, prhs);
}

LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV mlxHegazyGreenCriterion(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                          *prhs[])
{
    return mclFeval(_mcr_inst, "HegazyGreenCriterion", nlhs, plhs, nrhs, prhs);
}

LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV mlxShapiroWeakCriterion(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                          *prhs[])
{
    return mclFeval(_mcr_inst, "ShapiroWeakCriterion", nlhs, plhs, nrhs, prhs);
}

LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV mlxSimulateNarx(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "SimulateNarx", nlhs, plhs, nrhs, prhs);
}

LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV mlfCalcShewhart(int nargout, mxArray** ucl, mxArray** lcl, mxArray* Xj, 
                                  mxArray* Xcp)
{
    return mclMlfFeval(_mcr_inst, "CalcShewhart", nargout, 2, 2, ucl, lcl, Xj, Xcp);
}

LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV mlfCheckNormality(int nargout, mxArray** IsNormal, mxArray* sample)
{
    return mclMlfFeval(_mcr_inst, "CheckNormality", nargout, 1, 1, IsNormal, sample);
}

LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV mlfEppsPallyCriterion(int nargout, mxArray** IsNormal, mxArray* Xj, 
                                        mxArray* alpha)
{
    return mclMlfFeval(_mcr_inst, "EppsPallyCriterion", nargout, 1, 2, IsNormal, Xj, alpha);
}

LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV mlfGetSample(int nargout, mxArray** sample, mxArray* vector_source, 
                               mxArray* offset, mxArray* count)
{
    return mclMlfFeval(_mcr_inst, "GetSample", nargout, 1, 3, sample, vector_source, offset, count);
}

LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV mlfGiriCriterion(int nargout, mxArray** IsNormal, mxArray* sample, 
                                   mxArray* alpha)
{
    return mclMlfFeval(_mcr_inst, "GiriCriterion", nargout, 1, 2, IsNormal, sample, alpha);
}

LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV mlfHegazyGreenCriterion(int nargout, mxArray** IsNormal, mxArray* 
                                          sample, mxArray* alpha)
{
    return mclMlfFeval(_mcr_inst, "HegazyGreenCriterion", nargout, 1, 2, IsNormal, sample, alpha);
}

LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV mlfShapiroWeakCriterion(int nargout, mxArray** IsNormal, mxArray* 
                                          sample)
{
    return mclMlfFeval(_mcr_inst, "ShapiroWeakCriterion", nargout, 1, 1, IsNormal, sample);
}

LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV mlfSimulateNarx(int nargout, mxArray** y1, mxArray** xf1, mxArray** 
                                  xf2, mxArray* x1, mxArray* x2, mxArray* xi1, mxArray* 
                                  xi2)
{
    return mclMlfFeval(_mcr_inst, "SimulateNarx", nargout, 3, 4, y1, xf1, xf2, x1, x2, xi1, xi2);
}

