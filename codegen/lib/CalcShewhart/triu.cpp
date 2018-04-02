//
// File: triu.cpp
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
#include "triu.h"

// Function Definitions

//
// Arguments    : emxArray_real_T *x
// Return Type  : void
//
void triu(emxArray_real_T *x)
{
  int m;
  int istart;
  int jend;
  int j;
  int i;
  m = x->size[0];
  istart = 2;
  if (x->size[0] - 2 < x->size[1] - 1) {
    jend = x->size[0] - 1;
  } else {
    jend = x->size[1];
  }

  for (j = 1; j <= jend; j++) {
    for (i = istart; i <= m; i++) {
      x->data[(i + x->size[0] * (j - 1)) - 1] = 0.0;
    }

    if (j >= 1) {
      istart++;
    }
  }
}

//
// File trailer for triu.cpp
//
// [EOF]
//
