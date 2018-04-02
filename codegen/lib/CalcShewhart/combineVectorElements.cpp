//
// File: combineVectorElements.cpp
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
#include "combineVectorElements.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *x
// Return Type  : double
//
double combineVectorElements(const emxArray_real_T *x)
{
  double y;
  int k;
  if (x->size[1] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    for (k = 2; k <= x->size[1]; k++) {
      y += x->data[k - 1];
    }
  }

  return y;
}

//
// File trailer for combineVectorElements.cpp
//
// [EOF]
//
