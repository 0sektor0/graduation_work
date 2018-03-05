//
// File: GetSample.cpp
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
#include "libNarxStatSys_emxutil.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *vector_source
//                int offset
//                int count
//                emxArray_real_T *sample
// Return Type  : void
//
void GetSample(const emxArray_real_T *vector_source, int offset, int count,
               emxArray_real_T *sample)
{
  int sample_end;
  int i2;
  int i3;
  if ((offset < 0) && (count < MIN_int32_T - offset)) {
    sample_end = MIN_int32_T;
  } else if ((offset > 0) && (count > MAX_int32_T - offset)) {
    sample_end = MAX_int32_T;
  } else {
    sample_end = offset + count;
  }

  if (sample_end < -2147483647) {
    sample_end = MIN_int32_T;
  } else {
    sample_end--;
  }

  if (offset > sample_end) {
    i2 = 0;
    sample_end = 0;
  } else {
    i2 = offset - 1;
  }

  i3 = sample->size[0] * sample->size[1];
  sample->size[0] = 1;
  sample->size[1] = sample_end - i2;
  emxEnsureCapacity_real_T(sample, i3);
  sample_end -= i2;
  for (i3 = 0; i3 < sample_end; i3++) {
    sample->data[sample->size[0] * i3] = vector_source->data[i2 + i3];
  }
}

//
// File trailer for GetSample.cpp
//
// [EOF]
//
