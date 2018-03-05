//
// File: SimulateNarx.h
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 05-Mar-2018 18:06:23
//
#ifndef SIMULATENARX_H
#define SIMULATENARX_H

// Include Files
#include <cmath>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "libNarxStatSys_types.h"

// Function Declarations
extern void SimulateNarx(const emxArray_real_T *x1, const emxArray_real_T *x2,
  const emxArray_real_T *xi1, const emxArray_real_T *xi2, emxArray_real_T *b_y1,
  double xf1_data[], int xf1_size[2], double xf2_data[], int xf2_size[2]);

#endif

//
// File trailer for SimulateNarx.h
//
// [EOF]
//
