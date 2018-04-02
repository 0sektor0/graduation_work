//
// File: SimulateNarxNetwork.h
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 20-Mar-2018 12:35:48
//
#ifndef SIMULATENARXNETWORK_H
#define SIMULATENARXNETWORK_H

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
extern void SimulateNarxNetwork(double x1, double x2, const double xi1[5], const
  double xi2[5], double *b_y1, double xf1[5], double xf2[5]);
extern void mapminmax_apply(const double x[5], double y[5]);

#endif

//
// File trailer for SimulateNarxNetwork.h
//
// [EOF]
//
