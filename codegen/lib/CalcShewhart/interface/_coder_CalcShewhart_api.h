/*
 * File: _coder_CalcShewhart_api.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 20-Mar-2018 12:35:48
 */

#ifndef _CODER_CALCSHEWHART_API_H
#define _CODER_CALCSHEWHART_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_CalcShewhart_api.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void CalcShewhart(emxArray_real_T *Xj, real_T Xcp, real_T *ucl, real_T
  *lcl);
extern void CalcShewhart_api(const mxArray * const prhs[2], const mxArray *plhs
  [2]);
extern void CalcShewhart_atexit(void);
extern void CalcShewhart_initialize(void);
extern void CalcShewhart_terminate(void);
extern void CalcShewhart_xil_terminate(void);
extern boolean_T EppsPallyCriterion(emxArray_real_T *Xj, real_T alpha);
extern void EppsPallyCriterion_api(const mxArray * const prhs[2], const mxArray *
  plhs[1]);
extern void GetSample(emxArray_real_T *vector_source, real_T offset, real_T
                      count, emxArray_real_T *sample);
extern void GetSample_api(const mxArray * const prhs[3], const mxArray *plhs[1]);
extern boolean_T GiriCriterion(emxArray_real_T *Xj, real_T alpha);
extern void GiriCriterion_api(const mxArray * const prhs[2], const mxArray *
  plhs[1]);
extern boolean_T HegazyGreenCriterion(emxArray_real_T *Xj, real_T alpha);
extern void HegazyGreenCriterion_api(const mxArray * const prhs[2], const
  mxArray *plhs[1]);
extern void MakeMultipleNNPredicions(emxArray_real_T *input, real_T
  predictions_count, emxArray_real_T *prediction);
extern void MakeMultipleNNPredicions_api(const mxArray * const prhs[2], const
  mxArray *plhs[1]);
extern boolean_T ShapiroWeakCriterion(emxArray_real_T *Xj);
extern void ShapiroWeakCriterion_api(const mxArray * const prhs[1], const
  mxArray *plhs[1]);
extern void SimulateNarxNetwork(real_T x1, real_T x2, real_T xi1[5], real_T xi2
  [5], real_T *b_y1, real_T xf1[5], real_T xf2[5]);
extern void SimulateNarxNetwork_api(const mxArray * const prhs[4], const mxArray
  *plhs[3]);

#endif

/*
 * File trailer for _coder_CalcShewhart_api.h
 *
 * [EOF]
 */
