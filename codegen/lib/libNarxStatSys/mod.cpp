//
// File: mod.cpp
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
#include "mod.h"

// Function Definitions

//
// Arguments    : const double x[5]
//                double r[5]
// Return Type  : void
//
void b_mod(const double x[5], double r[5])
{
  int k;
  double b_r;
  for (k = 0; k < 5; k++) {
    if (x[k] == 0.0) {
      b_r = 0.0;
    } else {
      b_r = std::fmod(x[k], 6.0);
      if (b_r == 0.0) {
        b_r = 0.0;
      } else {
        if (x[k] < 0.0) {
          b_r += 6.0;
        }
      }
    }

    r[k] = b_r;
  }
}

//
// File trailer for mod.cpp
//
// [EOF]
//
