//
// File: CalcShewhart.cpp
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
#include "combineVectorElements.h"
#include "abs.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *Xj
//                double Xcp
//                double *ucl
//                double *lcl
// Return Type  : void
//
void CalcShewhart(const emxArray_real_T *Xj, double Xcp, double *ucl, double
                  *lcl)
{
  int loop_ub;
  int Xcp_size[2];
  int i0;
  emxArray_real_T *x;
  double Xcp_data[1];
  emxArray_real_T b_Xcp_data;

  // ккш индивидуальных значений
  // расчет среднего скользящего размаха
  loop_ub = !(1 > Xj->size[1] - 1);
  Xcp_size[0] = 1;
  Xcp_size[1] = loop_ub;
  for (i0 = 0; i0 < loop_ub; i0++) {
    Xcp_data[i0] = Xcp - Xcp;
  }

  emxInit_real_T(&x, 2);
  b_Xcp_data.data = (double *)&Xcp_data;
  b_Xcp_data.size = (int *)&Xcp_size;
  b_Xcp_data.allocatedSize = 1;
  b_Xcp_data.numDimensions = 2;
  b_Xcp_data.canFreeData = false;
  b_abs(&b_Xcp_data, x);

  //
  *ucl = combineVectorElements(x) / (double)x->size[1];
  *lcl = -1.0;
  emxFree_real_T(&x);
}

//
// File trailer for CalcShewhart.cpp
//
// [EOF]
//
