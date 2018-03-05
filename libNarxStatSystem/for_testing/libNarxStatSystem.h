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

#ifndef __libNarxStatSystem_h
#define __libNarxStatSystem_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#ifdef __cplusplus
extern "C" {
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_libNarxStatSystem_C_API 
#define LIB_libNarxStatSystem_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV libNarxStatSystemInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV libNarxStatSystemInitialize(void);

extern LIB_libNarxStatSystem_C_API 
void MW_CALL_CONV libNarxStatSystemTerminate(void);

extern LIB_libNarxStatSystem_C_API 
void MW_CALL_CONV libNarxStatSystemPrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV mlxCalcShewhart(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV mlxCheckNormality(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV mlxEppsPallyCriterion(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                        *prhs[]);

extern LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV mlxGetSample(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV mlxGiriCriterion(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV mlxHegazyGreenCriterion(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                          *prhs[]);

extern LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV mlxShapiroWeakCriterion(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                          *prhs[]);

extern LIB_libNarxStatSystem_C_API 
bool MW_CALL_CONV mlxSimulateNarx(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

/* C INTERFACE -- MLF WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_libNarxStatSystem_C_API bool MW_CALL_CONV mlfCalcShewhart(int nargout, mxArray** ucl, mxArray** lcl, mxArray* Xj, mxArray* Xcp);

extern LIB_libNarxStatSystem_C_API bool MW_CALL_CONV mlfCheckNormality(int nargout, mxArray** IsNormal, mxArray* sample);

extern LIB_libNarxStatSystem_C_API bool MW_CALL_CONV mlfEppsPallyCriterion(int nargout, mxArray** IsNormal, mxArray* Xj, mxArray* alpha);

extern LIB_libNarxStatSystem_C_API bool MW_CALL_CONV mlfGetSample(int nargout, mxArray** sample, mxArray* vector_source, mxArray* offset, mxArray* count);

extern LIB_libNarxStatSystem_C_API bool MW_CALL_CONV mlfGiriCriterion(int nargout, mxArray** IsNormal, mxArray* sample, mxArray* alpha);

extern LIB_libNarxStatSystem_C_API bool MW_CALL_CONV mlfHegazyGreenCriterion(int nargout, mxArray** IsNormal, mxArray* sample, mxArray* alpha);

extern LIB_libNarxStatSystem_C_API bool MW_CALL_CONV mlfShapiroWeakCriterion(int nargout, mxArray** IsNormal, mxArray* sample);

extern LIB_libNarxStatSystem_C_API bool MW_CALL_CONV mlfSimulateNarx(int nargout, mxArray** y1, mxArray** xf1, mxArray** xf2, mxArray* x1, mxArray* x2, mxArray* xi1, mxArray* xi2);

#ifdef __cplusplus
}
#endif
/* C INTERFACE -- MLF WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#endif
