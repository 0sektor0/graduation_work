//
// File: sum.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 20-Mar-2018 12:35:48
//

// Include Files
#include "rt_nonfinite.h"
#include "CalcShewhart.h"
#include "EppsPallyCriterion.h"
#include "GetSample.h"
#include "GiriCriterion.h"
#include "HegazyGreenCriterion.h"
#include "MakeMultipleNNPredicions.h"
#include "ShapiroWeakCriterion.h"
#include "SimulateNarxNetwork.h"
#include "sum.h"
#include "combineVectorElements.h"
#include "CalcShewhart_emxutil.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *x
//                emxArray_real_T *y
// Return Type  : void
//
void b_sum(const emxArray_real_T *x, emxArray_real_T *y)
{
  int i;
  int xpageoffset;
  int k;
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity_real_T(y, i);
  for (i = 0; i + 1 <= x->size[1]; i++) {
    xpageoffset = i * x->size[0];
    y->data[i] = x->data[xpageoffset];
    for (k = 2; k <= x->size[0]; k++) {
      y->data[i] += x->data[(xpageoffset + k) - 1];
    }
  }
}

//
// Arguments    : const emxArray_real_T *x
// Return Type  : double
//
double sum(const emxArray_real_T *x)
{
  return combineVectorElements(x);
}

//
// File trailer for sum.cpp
//
// [EOF]
//
