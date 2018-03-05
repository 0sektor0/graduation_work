//
// File: bsxfun.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 05-Mar-2018 18:06:23
//

// Include Files
#include "rt_nonfinite.h"
#include "EppsPallyCriterion.h"
#include "GetSample.h"
#include "GiriCriterion.h"
#include "HegazyGreenCriterion.h"
#include "ShapiroWeakCriterion.h"
#include "ShowPlot.h"
#include "SimulateNarx.h"
#include "bsxfun.h"
#include "libNarxStatSys_emxutil.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *a
//                emxArray_real_T *c
// Return Type  : void
//
void b_bsxfun(const emxArray_real_T *a, emxArray_real_T *c)
{
  int csz_idx_1;
  int acoef;
  int k;
  csz_idx_1 = a->size[1];
  acoef = c->size[0] * c->size[1];
  c->size[0] = 1;
  c->size[1] = csz_idx_1;
  emxEnsureCapacity_real_T(c, acoef);
  if (c->size[1] != 0) {
    csz_idx_1 = c->size[1];
    acoef = (a->size[1] != 1);
    for (k = 0; k < csz_idx_1; k++) {
      c->data[c->size[0] * k] = a->data[a->size[0] * (acoef * k)] + -1.0;
    }
  }
}

//
// Arguments    : const emxArray_real_T *a
//                emxArray_real_T *c
// Return Type  : void
//
void bsxfun(const emxArray_real_T *a, emxArray_real_T *c)
{
  int csz_idx_1;
  int acoef;
  int k;
  csz_idx_1 = a->size[1];
  acoef = c->size[0] * c->size[1];
  c->size[0] = 1;
  c->size[1] = csz_idx_1;
  emxEnsureCapacity_real_T(c, acoef);
  if (c->size[1] != 0) {
    csz_idx_1 = c->size[1];
    acoef = (a->size[1] != 1);
    for (k = 0; k < csz_idx_1; k++) {
      c->data[c->size[0] * k] = a->data[a->size[0] * (acoef * k)] *
        0.002002002002002;
    }
  }
}

//
// File trailer for bsxfun.cpp
//
// [EOF]
//
