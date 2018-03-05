//
// File: ShapiroWeakCriterion.cpp
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
#include "power.h"
#include "combineVectorElements.h"
#include "libNarxStatSys_rtwutil.h"

// Function Definitions

//
// для alpha = 0.05
// расчет параметров для вычисления статистики W
// Arguments    : const emxArray_real_T *Xj
// Return Type  : boolean_T
//
boolean_T ShapiroWeakCriterion(const emxArray_real_T *Xj)
{
  emxArray_real_T *x;
  double m;
  double Xcp;
  int b_j1;
  int nd2;
  emxArray_real_T *k;
  int j2;
  double xtmp;
  emxArray_real_T *a;
  emxArray_real_T *y;
  emxArray_real_T *b_y;
  emxInit_real_T(&x, 2);

  //  8<= n <= 50
  m = (double)Xj->size[1] / 2.0;
  Xcp = combineVectorElements(Xj) / (double)Xj->size[1];
  b_j1 = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = Xj->size[1];
  emxEnsureCapacity_real_T(x, b_j1);
  nd2 = Xj->size[0] * Xj->size[1];
  for (b_j1 = 0; b_j1 < nd2; b_j1++) {
    x->data[b_j1] = Xj->data[b_j1];
  }

  nd2 = Xj->size[1] >> 1;
  for (b_j1 = 1; b_j1 <= nd2; b_j1++) {
    j2 = Xj->size[1] - b_j1;
    xtmp = x->data[b_j1 - 1];
    x->data[b_j1 - 1] = x->data[j2];
    x->data[j2] = xtmp;
  }

  emxInit_real_T(&k, 2);
  if (m < 1.0) {
    b_j1 = k->size[0] * k->size[1];
    k->size[0] = 1;
    k->size[1] = 0;
    emxEnsureCapacity_real_T(k, b_j1);
  } else {
    b_j1 = k->size[0] * k->size[1];
    k->size[0] = 1;
    k->size[1] = (int)std::floor(m - 1.0) + 1;
    emxEnsureCapacity_real_T(k, b_j1);
    nd2 = (int)std::floor(m - 1.0);
    for (b_j1 = 0; b_j1 <= nd2; b_j1++) {
      k->data[k->size[0] * b_j1] = 1.0 + (double)b_j1;
    }
  }

  b_j1 = k->size[0] * k->size[1];
  k->size[0] = 1;
  emxEnsureCapacity_real_T(k, b_j1);
  j2 = Xj->size[1];
  b_j1 = k->size[0];
  nd2 = k->size[1];
  m = (double)Xj->size[1] - 0.5;
  nd2 *= b_j1;
  for (b_j1 = 0; b_j1 < nd2; b_j1++) {
    k->data[b_j1] = (((double)j2 - 2.0 * k->data[b_j1]) + 1.0) / m;
  }

  emxInit_real_T(&a, 2);
  m = 0.899 / (rt_powd_snf((double)Xj->size[1] - 2.4, 0.4162) - 0.02);
  b_j1 = a->size[0] * a->size[1];
  a->size[0] = 1;
  a->size[1] = k->size[1];
  emxEnsureCapacity_real_T(a, b_j1);
  nd2 = k->size[0] * k->size[1];
  for (b_j1 = 0; b_j1 < nd2; b_j1++) {
    a->data[b_j1] = 3.0 - k->data[b_j1];
  }

  emxInit_real_T(&y, 2);
  nd2 = a->size[1];
  b_j1 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = a->size[1];
  emxEnsureCapacity_real_T(y, b_j1);
  for (b_j1 = 0; b_j1 + 1 <= nd2; b_j1++) {
    y->data[b_j1] = rt_powd_snf(a->data[b_j1], 10.845);
  }

  b_j1 = a->size[0] * a->size[1];
  a->size[0] = 1;
  a->size[1] = k->size[1];
  emxEnsureCapacity_real_T(a, b_j1);
  nd2 = k->size[0] * k->size[1];
  for (b_j1 = 0; b_j1 < nd2; b_j1++) {
    a->data[b_j1] = 1.1 - k->data[b_j1];
  }

  emxInit_real_T(&b_y, 2);
  nd2 = a->size[1];
  b_j1 = b_y->size[0] * b_y->size[1];
  b_y->size[0] = 1;
  b_y->size[1] = a->size[1];
  emxEnsureCapacity_real_T(b_y, b_j1);
  for (b_j1 = 0; b_j1 + 1 <= nd2; b_j1++) {
    b_y->data[b_j1] = rt_powd_snf(a->data[b_j1], 8.26);
  }

  // расчет статистики
  b_j1 = a->size[0] * a->size[1];
  a->size[0] = 1;
  a->size[1] = k->size[1];
  emxEnsureCapacity_real_T(a, b_j1);
  nd2 = k->size[1];
  for (b_j1 = 0; b_j1 < nd2; b_j1++) {
    a->data[a->size[0] * b_j1] = m * ((k->data[k->size[0] * b_j1] + 1483.0 /
      y->data[y->size[0] * b_j1]) + 7.16E-9 / b_y->data[b_y->size[0] * b_j1]) *
      (x->data[b_j1] - Xj->data[b_j1]);
  }

  emxFree_real_T(&b_y);
  emxFree_real_T(&y);
  emxFree_real_T(&k);
  xtmp = sum(a);
  b_j1 = a->size[0] * a->size[1];
  a->size[0] = 1;
  a->size[1] = Xj->size[1];
  emxEnsureCapacity_real_T(a, b_j1);
  nd2 = Xj->size[0] * Xj->size[1];
  for (b_j1 = 0; b_j1 < nd2; b_j1++) {
    a->data[b_j1] = Xj->data[b_j1] - Xcp;
  }

  power(a, x);
  m = sum(x);
  emxFree_real_T(&a);
  emxFree_real_T(&x);
  return (1.0 - 0.6695 / rt_powd_snf((double)Xj->size[1], 0.6518)) * m / (xtmp *
    xtmp) < 1.0;
}

//
// File trailer for ShapiroWeakCriterion.cpp
//
// [EOF]
//
