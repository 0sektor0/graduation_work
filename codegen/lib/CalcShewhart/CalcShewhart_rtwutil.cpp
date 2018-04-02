//
// File: CalcShewhart_rtwutil.cpp
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
#include "CalcShewhart_rtwutil.h"

// Function Definitions

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
double rt_powd_snf(double u0, double u1)
{
  double y;
  double d4;
  double d5;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    d4 = std::abs(u0);
    d5 = std::abs(u1);
    if (rtIsInf(u1)) {
      if (d4 == 1.0) {
        y = 1.0;
      } else if (d4 > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d5 == 0.0) {
      y = 1.0;
    } else if (d5 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = rtNaN;
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

//
// File trailer for CalcShewhart_rtwutil.cpp
//
// [EOF]
//
