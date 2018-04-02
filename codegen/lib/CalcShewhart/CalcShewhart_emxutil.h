//
// File: CalcShewhart_emxutil.h
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 20-Mar-2018 12:35:48
//
#ifndef CALCSHEWHART_EMXUTIL_H
#define CALCSHEWHART_EMXUTIL_H

// Include Files
#include <cmath>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "CalcShewhart_types.h"

// Function Declarations
extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#endif

//
// File trailer for CalcShewhart_emxutil.h
//
// [EOF]
//
