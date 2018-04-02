/*
 * File: _coder_CalcShewhart_api.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 20-Mar-2018 12:35:48
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_CalcShewhart_api.h"
#include "_coder_CalcShewhart_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131451U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "CalcShewhart",                      /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static const mxArray *b_emlrt_marshallOut(const boolean_T u);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Xcp, const
  char_T *identifier);
static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u);
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static const mxArray *d_emlrt_marshallOut(const real_T u[5]);
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *xi1,
  const char_T *identifier))[5];
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Xj, const
  char_T *identifier, emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(const real_T u);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[5];
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[5];

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  g_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const boolean_T u
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const boolean_T u)
{
  const mxArray *y;
  const mxArray *m1;
  y = NULL;
  m1 = emlrtCreateLogicalScalar(u);
  emlrtAssign(&y, m1);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *Xcp
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Xcp, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(Xcp), &thisId);
  emlrtDestroyArray(&Xcp);
  return y;
}

/*
 * Arguments    : const emxArray_real_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m2;
  static const int32_T iv0[2] = { 0, 0 };

  y = NULL;
  m2 = emlrtCreateNumericArray(2, iv0, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m2, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m2, u->size, 2);
  emlrtAssign(&y, m2);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const real_T u[5]
 * Return Type  : const mxArray *
 */
static const mxArray *d_emlrt_marshallOut(const real_T u[5])
{
  const mxArray *y;
  const mxArray *m3;
  static const int32_T iv1[2] = { 0, 0 };

  static const int32_T iv2[2] = { 1, 5 };

  y = NULL;
  m3 = emlrtCreateNumericArray(2, iv1, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m3, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m3, *(int32_T (*)[2])&iv2[0], 2);
  emlrtAssign(&y, m3);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *xi1
 *                const char_T *identifier
 * Return Type  : real_T (*)[5]
 */
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *xi1,
  const char_T *identifier))[5]
{
  real_T (*y)[5];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(xi1), &thisId);
  emlrtDestroyArray(&xi1);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *Xj
 *                const char_T *identifier
 *                emxArray_real_T *y
 * Return Type  : void
 */
  static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Xj, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(Xj), &thisId, y);
  emlrtDestroyArray(&Xj);
}

/*
 * Arguments    : const real_T u
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m0;
  y = NULL;
  m0 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m0);
  return y;
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((void *)(*pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[5]
 */
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[5]
{
  real_T (*y)[5];
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
  static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv0[2] = { false, true };

  int32_T iv3[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv0[0],
    iv3);
  ret->size[0] = iv3[0];
  ret->size[1] = iv3[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[5]
 */
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[5]
{
  real_T (*ret)[5];
  static const int32_T dims[2] = { 1, 5 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[5])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const mxArray * const prhs[2]
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
  void CalcShewhart_api(const mxArray * const prhs[2], const mxArray *plhs[2])
{
  emxArray_real_T *Xj;
  real_T Xcp;
  real_T ucl;
  real_T lcl;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &Xj, 2, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias((const mxArray *)prhs[0]), "Xj", Xj);
  Xcp = c_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[1]), "Xcp");

  /* Invoke the target function */
  CalcShewhart(Xj, Xcp, &ucl, &lcl);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(ucl);
  plhs[1] = emlrt_marshallOut(lcl);
  Xj->canFreeData = false;
  emxFree_real_T(&Xj);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void CalcShewhart_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  CalcShewhart_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void CalcShewhart_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void CalcShewhart_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * Arguments    : const mxArray * const prhs[2]
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void EppsPallyCriterion_api(const mxArray * const prhs[2], const mxArray *plhs[1])
{
  emxArray_real_T *Xj;
  real_T alpha;
  boolean_T IsNormal;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &Xj, 2, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias((const mxArray *)prhs[0]), "Xj", Xj);
  alpha = c_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[1]), "alpha");

  /* Invoke the target function */
  IsNormal = EppsPallyCriterion(Xj, alpha);

  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(IsNormal);
  Xj->canFreeData = false;
  emxFree_real_T(&Xj);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const mxArray * const prhs[3]
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void GetSample_api(const mxArray * const prhs[3], const mxArray *plhs[1])
{
  emxArray_real_T *vector_source;
  emxArray_real_T *sample;
  real_T offset;
  real_T count;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &vector_source, 2, true);
  emxInit_real_T(&st, &sample, 2, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias((const mxArray *)prhs[0]), "vector_source",
                   vector_source);
  offset = c_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[1]),
    "offset");
  count = c_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[2]), "count");

  /* Invoke the target function */
  GetSample(vector_source, offset, count, sample);

  /* Marshall function outputs */
  plhs[0] = c_emlrt_marshallOut(sample);
  sample->canFreeData = false;
  emxFree_real_T(&sample);
  vector_source->canFreeData = false;
  emxFree_real_T(&vector_source);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const mxArray * const prhs[2]
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void GiriCriterion_api(const mxArray * const prhs[2], const mxArray *plhs[1])
{
  emxArray_real_T *Xj;
  real_T alpha;
  boolean_T IsNormal;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &Xj, 2, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias((const mxArray *)prhs[0]), "Xj", Xj);
  alpha = c_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[1]), "alpha");

  /* Invoke the target function */
  IsNormal = GiriCriterion(Xj, alpha);

  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(IsNormal);
  Xj->canFreeData = false;
  emxFree_real_T(&Xj);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const mxArray * const prhs[2]
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void HegazyGreenCriterion_api(const mxArray * const prhs[2], const mxArray *
  plhs[1])
{
  emxArray_real_T *Xj;
  real_T alpha;
  boolean_T IsNormal;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &Xj, 2, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias((const mxArray *)prhs[0]), "Xj", Xj);
  alpha = c_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[1]), "alpha");

  /* Invoke the target function */
  IsNormal = HegazyGreenCriterion(Xj, alpha);

  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(IsNormal);
  Xj->canFreeData = false;
  emxFree_real_T(&Xj);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const mxArray * const prhs[2]
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void MakeMultipleNNPredicions_api(const mxArray * const prhs[2], const mxArray
  *plhs[1])
{
  emxArray_real_T *input;
  emxArray_real_T *prediction;
  real_T predictions_count;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &input, 2, true);
  emxInit_real_T(&st, &prediction, 2, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias((const mxArray *)prhs[0]), "input", input);
  predictions_count = c_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs
    [1]), "predictions_count");

  /* Invoke the target function */
  MakeMultipleNNPredicions(input, predictions_count, prediction);

  /* Marshall function outputs */
  plhs[0] = c_emlrt_marshallOut(prediction);
  prediction->canFreeData = false;
  emxFree_real_T(&prediction);
  input->canFreeData = false;
  emxFree_real_T(&input);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const mxArray * const prhs[1]
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void ShapiroWeakCriterion_api(const mxArray * const prhs[1], const mxArray *
  plhs[1])
{
  emxArray_real_T *Xj;
  boolean_T IsNormal;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &Xj, 2, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias((const mxArray *)prhs[0]), "Xj", Xj);

  /* Invoke the target function */
  IsNormal = ShapiroWeakCriterion(Xj);

  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(IsNormal);
  Xj->canFreeData = false;
  emxFree_real_T(&Xj);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const mxArray * const prhs[4]
 *                const mxArray *plhs[3]
 * Return Type  : void
 */
void SimulateNarxNetwork_api(const mxArray * const prhs[4], const mxArray *plhs
  [3])
{
  real_T (*xf1)[5];
  real_T (*xf2)[5];
  real_T x1;
  real_T x2;
  real_T (*xi1)[5];
  real_T (*xi2)[5];
  real_T b_y1;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  xf1 = (real_T (*)[5])mxMalloc(sizeof(real_T [5]));
  xf2 = (real_T (*)[5])mxMalloc(sizeof(real_T [5]));

  /* Marshall function inputs */
  x1 = c_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[0]), "x1");
  x2 = c_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[1]), "x2");
  xi1 = e_emlrt_marshallIn(&st, emlrtAlias((const mxArray *)prhs[2]), "xi1");
  xi2 = e_emlrt_marshallIn(&st, emlrtAlias((const mxArray *)prhs[3]), "xi2");

  /* Invoke the target function */
  SimulateNarxNetwork(x1, x2, *xi1, *xi2, &b_y1, *xf1, *xf2);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(b_y1);
  plhs[1] = d_emlrt_marshallOut(*xf1);
  plhs[2] = d_emlrt_marshallOut(*xf2);
}

/*
 * File trailer for _coder_CalcShewhart_api.c
 *
 * [EOF]
 */
