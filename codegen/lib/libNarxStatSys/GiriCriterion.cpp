//
// File: GiriCriterion.cpp
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
#include "sum.h"
#include "abs.h"
#include "combineVectorElements.h"
#include "libNarxStatSys_rtwutil.h"

// Function Definitions

//
// проверка на наличие известной апроксимации критических величин
// Arguments    : const emxArray_real_T *Xj
//                double alpha
// Return Type  : boolean_T
//
boolean_T GiriCriterion(const emxArray_real_T *Xj, double)
{
  boolean_T IsNormal;
  emxArray_real_T *dsa;
  double Xcp;
  int i4;
  int loop_ub;
  emxArray_real_T *b_dsa;
  double b_exp;
  double disp;
  emxInit_real_T(&dsa, 2);

  // расчет параметров, необходимых для дальнейших вычмслений 
  Xcp = combineVectorElements(Xj) / (double)Xj->size[1];
  i4 = dsa->size[0] * dsa->size[1];
  dsa->size[0] = 1;
  dsa->size[1] = Xj->size[1];
  emxEnsureCapacity_real_T(dsa, i4);
  loop_ub = Xj->size[0] * Xj->size[1];
  for (i4 = 0; i4 < loop_ub; i4++) {
    dsa->data[i4] = Xj->data[i4] - Xcp;
  }

  emxInit_real_T(&b_dsa, 2);

  // the Difference of the Sample and its Average. DSA
  // расчет статистики
  i4 = b_dsa->size[0] * b_dsa->size[1];
  b_dsa->size[0] = 1;
  b_dsa->size[1] = dsa->size[1];
  emxEnsureCapacity_real_T(b_dsa, i4);
  loop_ub = dsa->size[0] * dsa->size[1];
  for (i4 = 0; i4 < loop_ub; i4++) {
    b_dsa->data[i4] = dsa->data[i4] * dsa->data[i4];
  }

  Xcp = sum(b_dsa);
  Xcp = std::sqrt(Xcp);
  b_abs(dsa, b_dsa);
  b_exp = sum(b_dsa);
  Xcp = b_exp / ((double)Xj->size[1] * (Xcp / ((double)Xj->size[1] - 1.0)));

  // расчет мат ожид и дисперсии в соответсвие с их апроксимациями 
  b_exp = (((0.797885 + 0.199471 / (double)Xj->size[1]) + 0.024934 / ((double)
             Xj->size[1] * (double)Xj->size[1])) - 0.031168 / rt_powd_snf
           ((double)Xj->size[1], 3.0)) - 0.008182 / rt_powd_snf((double)Xj->
    size[1], 4.0);
  disp = ((0.04507 / (double)Xj->size[1] - 0.124648 / ((double)Xj->size[1] *
            (double)Xj->size[1])) + 0.084859 / rt_powd_snf((double)Xj->size[1],
           3.0)) + 0.006323 / rt_powd_snf((double)Xj->size[1], 4.0);

  // определене квантиля норм распределения заданного уровня 
  // альфа квантиль стд нормального распределения уровня значимости 0.05  
  // определение нормальности распределения
  emxFree_real_T(&b_dsa);
  emxFree_real_T(&dsa);
  if ((Xcp > b_exp + std::sqrt(disp) * -1.645) && (Xcp < b_exp + std::sqrt(disp)
       * 1.645)) {
    IsNormal = true;
  } else {
    IsNormal = false;
  }

  return IsNormal;
}

//
// File trailer for GiriCriterion.cpp
//
// [EOF]
//
