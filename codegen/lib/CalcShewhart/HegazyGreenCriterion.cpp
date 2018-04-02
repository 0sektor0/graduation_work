//
// File: HegazyGreenCriterion.cpp
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
#include "sum.h"
#include "abs.h"
#include "combineVectorElements.h"
#include "CalcShewhart_rtwutil.h"

// Function Definitions

//
// проверка на наличие известной апроксимации критических величин
// Arguments    : const emxArray_real_T *Xj
//                double alpha
// Return Type  : boolean_T
//
boolean_T HegazyGreenCriterion(const emxArray_real_T *Xj, double alpha)
{
  boolean_T IsNormal;
  emxArray_real_T *s;
  double Xcp;
  int n;
  int i;
  int loop_ub;
  emxArray_real_T *b_s;
  double x;
  double c_s;
  double b_x;
  emxInit_real_T(&s, 2);

  // расчет параметров для вычисления статистик T1 и T2  
  Xcp = combineVectorElements(Xj) / (double)Xj->size[1];
  n = Xj->size[1];
  i = s->size[0] * s->size[1];
  s->size[0] = 1;
  s->size[1] = Xj->size[1];
  emxEnsureCapacity_real_T(s, i);
  loop_ub = Xj->size[0] * Xj->size[1];
  for (i = 0; i < loop_ub; i++) {
    s->data[i] = Xj->data[i] - Xcp;
  }

  emxInit_real_T(&b_s, 2);
  i = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = s->size[1];
  emxEnsureCapacity_real_T(b_s, i);
  loop_ub = s->size[0] * s->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_s->data[i] = s->data[i] * s->data[i];
  }

  x = sum(b_s);
  c_s = x / ((double)Xj->size[1] - 1.0);
  c_s = std::sqrt(c_s);

  // вектор мат ожидания порядковой статистики  
  // надо заменить на более изящную конструкцию 
  i = s->size[0] * s->size[1];
  s->size[0] = 1;
  s->size[1] = Xj->size[1];
  emxEnsureCapacity_real_T(s, i);
  for (i = 0; i < n; i++) {
    s->data[i] = 4.91 * (rt_powd_snf((1.0 + (double)i) / ((double)n + 1.0), 0.14)
                         - rt_powd_snf((((double)n + 1.0) - (1.0 + (double)i)) /
      ((double)n + 1.0), 0.14));
  }

  // расчет статистик
  i = s->size[0] * s->size[1];
  s->size[0] = 1;
  s->size[1] = Xj->size[1];
  emxEnsureCapacity_real_T(s, i);
  loop_ub = Xj->size[0] * Xj->size[1];
  for (i = 0; i < loop_ub; i++) {
    s->data[i] = (Xj->data[i] - Xcp) / c_s - s->data[i];
  }

  b_abs(s, b_s);
  x = sum(b_s);
  i = b_s->size[0] * b_s->size[1];
  b_s->size[0] = 1;
  b_s->size[1] = s->size[1];
  emxEnsureCapacity_real_T(b_s, i);
  loop_ub = s->size[0] * s->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_s->data[i] = s->data[i] * s->data[i];
  }

  emxFree_real_T(&s);
  b_x = sum(b_s);

  // расчет критических значений в соответствие с известными апроксимациями 
  c_s = 0.0;
  Xcp = 0.0;
  emxFree_real_T(&b_s);
  if (alpha == 0.01) {
    c_s = std::log((double)Xj->size[1]);
    c_s = (0.7195 - 0.1751 * std::log((double)Xj->size[1])) + 0.0108 * (c_s *
      c_s);
    Xcp = (0.0178 + 2.8736 / (double)Xj->size[1]) - 8.2894 / ((double)Xj->size[1]
      * (double)Xj->size[1]);
  }

  if (alpha == 0.05) {
    c_s = std::log((double)Xj->size[1]);
    c_s = (0.6027 - 0.1481 * std::log((double)Xj->size[1])) + 0.009 * (c_s * c_s);
    Xcp = (0.0126 + 1.9227 / (double)Xj->size[1]) - 5.00677 / ((double)Xj->size
      [1] * (double)Xj->size[1]);
  }

  // определение нормальности выборки
  if ((x / (double)Xj->size[1] < c_s) && (b_x / (double)Xj->size[1] < Xcp)) {
    IsNormal = true;
  } else {
    IsNormal = false;
  }

  return IsNormal;
}

//
// File trailer for HegazyGreenCriterion.cpp
//
// [EOF]
//
