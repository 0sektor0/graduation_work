/*
 * File: _coder_libNarxStatSys_api.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 05-Mar-2018 18:06:23
 */

#ifndef _CODER_LIBNARXSTATSYS_API_H
#define _CODER_LIBNARXSTATSYS_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_libNarxStatSys_api.h"

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
extern boolean_T EppsPallyCriterion(emxArray_real_T *Xj, real_T alpha);
extern void EppsPallyCriterion_api(const mxArray * const prhs[2], const mxArray *
  plhs[1]);
extern void GetSample(emxArray_real_T *vector_source, int32_T offset, int32_T
                      count, emxArray_real_T *sample);
extern void GetSample_api(const mxArray * const prhs[3], const mxArray *plhs[1]);
extern boolean_T GiriCriterion(emxArray_real_T *Xj, real_T alpha);
extern void GiriCriterion_api(const mxArray * const prhs[2], const mxArray *
  plhs[1]);
extern boolean_T HegazyGreenCriterion(emxArray_real_T *Xj, real_T alpha);
extern void HegazyGreenCriterion_api(const mxArray * const prhs[2], const
  mxArray *plhs[1]);
extern boolean_T ShapiroWeakCriterion(emxArray_real_T *Xj);
extern void ShapiroWeakCriterion_api(const mxArray * const prhs[1], const
  mxArray *plhs[1]);
extern void ShowPlot(emxArray_real_T *Xj);
extern void ShowPlot_api(const mxArray * const prhs[1]);
extern void SimulateNarx(emxArray_real_T *x1, emxArray_real_T *x2,
  emxArray_real_T *xi1, emxArray_real_T *xi2, emxArray_real_T *b_y1, real_T
  xf1_data[], int32_T xf1_size[2], real_T xf2_data[], int32_T xf2_size[2]);
extern void SimulateNarx_api(const mxArray * const prhs[4], const mxArray *plhs
  [3]);
extern void libNarxStatSys_atexit(void);
extern void libNarxStatSys_initialize(void);
extern void libNarxStatSys_terminate(void);
extern void libNarxStatSys_xil_terminate(void);

#endif

/*
 * File trailer for _coder_libNarxStatSys_api.h
 *
 * [EOF]
 */
