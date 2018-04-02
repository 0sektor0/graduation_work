//
// File: GetSample.cpp
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
#include "CalcShewhart_emxutil.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *vector_source
//                double offset
//                double count
//                emxArray_real_T *sample
// Return Type  : void
//
void GetSample(const emxArray_real_T *vector_source, double offset, double count,
               emxArray_real_T *sample)
{
  double sample_end;
  int i3;
  int i4;
  int loop_ub;
  sample_end = (offset + count) - 1.0;
  if (offset > sample_end) {
    i3 = 0;
    i4 = 0;
  } else {
    i3 = (int)offset - 1;
    i4 = (int)sample_end;
  }

  loop_ub = sample->size[0] * sample->size[1];
  sample->size[0] = 1;
  sample->size[1] = i4 - i3;
  emxEnsureCapacity_real_T(sample, loop_ub);
  loop_ub = i4 - i3;
  for (i4 = 0; i4 < loop_ub; i4++) {
    sample->data[sample->size[0] * i4] = vector_source->data[i3 + i4];
  }
}

//
// File trailer for GetSample.cpp
//
// [EOF]
//
