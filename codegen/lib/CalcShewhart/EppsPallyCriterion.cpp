//
// File: EppsPallyCriterion.cpp
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
#include "triu.h"
#include "power.h"
#include "combineVectorElements.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *Xj
//                double alpha
// Return Type  : boolean_T
//
boolean_T EppsPallyCriterion(const emxArray_real_T *Xj, double alpha)
{
  boolean_T IsNormal;
  int ia;
  int nx;
  double quantile[9];
  static const double dv4[9] = { 0.271, 0.275, 0.279, 0.284, 0.287, 0.289, 0.29,
    0.291, 0.29 };

  static const double dv5[9] = { 0.347, 0.35, 0.357, 0.366, 0.368, 0.371, 0.374,
    0.376, 0.379 };

  static const double dv6[9] = { 0.426, 0.428, 0.437, 0.447, 0.45, 0.459, 0.46,
    0.464, 0.467 };

  static const double dv7[9] = { 0.526, 0.537, 0.545, 0.56, 0.564, 0.569, 0.574,
    0.583, 0.59 };

  double qval;
  boolean_T exitg1;
  static const unsigned char uv0[9] = { 8U, 9U, 10U, 15U, 20U, 30U, 50U, 100U,
    200U };

  emxArray_real_T *b_Xj;
  double Xcp;
  int i1;
  emxArray_real_T *Sj;
  double Sk;
  double m2;
  int k;
  emxArray_real_T *M1;
  int i2;
  emxArray_real_T *M2;
  int Xj_idx_1;
  int iv0[2];
  int m;
  int c;
  int cr;
  int br;
  int ic;
  int ib;
  emxArray_real_T *Bm;

  //  n >= 8
  ia = Xj->size[1];

  // проверка на возможность применения критерия 
  if (Xj->size[1] < 8) {
    IsNormal = false;
  } else {
    // определяем какой вектор квантилей использовать согласно госту 5479-2002 
    if (0.1 == alpha) {
      nx = 0;
    } else if (0.05 == alpha) {
      nx = 1;
    } else if (0.025 == alpha) {
      nx = 2;
    } else if (0.01 == alpha) {
      nx = 3;
    } else {
      nx = -1;
    }

    switch (nx) {
     case 0:
      memcpy(&quantile[0], &dv4[0], 9U * sizeof(double));
      break;

     case 1:
      memcpy(&quantile[0], &dv5[0], 9U * sizeof(double));
      break;

     case 2:
      memcpy(&quantile[0], &dv6[0], 9U * sizeof(double));
      break;

     case 3:
      memcpy(&quantile[0], &dv7[0], 9U * sizeof(double));
      break;
    }

    // определяем значение квантиля в зависимости от длины вектора     
    qval = -1.0;
    nx = 0;
    exitg1 = false;
    while ((!exitg1) && (nx < 8)) {
      if (ia == uv0[nx]) {
        qval = quantile[nx];
        exitg1 = true;
      } else if ((ia > uv0[nx]) && (ia < uv0[nx + 1])) {
        qval = (quantile[nx] + quantile[nx + 1]) / 2.0;
        exitg1 = true;
      } else {
        nx++;
      }
    }

    if (qval < 0.0) {
      qval = quantile[8];
    }

    emxInit_real_T(&b_Xj, 2);

    // расчет параметра А
    Xcp = combineVectorElements(Xj) / (double)Xj->size[1];
    i1 = b_Xj->size[0] * b_Xj->size[1];
    b_Xj->size[0] = 1;
    b_Xj->size[1] = Xj->size[1];
    emxEnsureCapacity_real_T(b_Xj, i1);
    nx = Xj->size[0] * Xj->size[1];
    for (i1 = 0; i1 < nx; i1++) {
      b_Xj->data[i1] = Xj->data[i1] - Xcp;
    }

    emxInit_real_T(&Sj, 2);
    power(b_Xj, Sj);
    Sk = sum(Sj);
    m2 = Sk / (double)Xj->size[1];
    i1 = b_Xj->size[0] * b_Xj->size[1];
    b_Xj->size[0] = 1;
    b_Xj->size[1] = Xj->size[1];
    emxEnsureCapacity_real_T(b_Xj, i1);
    nx = Xj->size[0] * Xj->size[1];
    for (i1 = 0; i1 < nx; i1++) {
      b_Xj->data[i1] = Xj->data[i1] - Xcp;
    }

    power(b_Xj, Sj);
    i1 = Sj->size[0] * Sj->size[1];
    Sj->size[0] = 1;
    emxEnsureCapacity_real_T(Sj, i1);
    nx = Sj->size[0];
    ia = Sj->size[1];
    nx *= ia;
    emxFree_real_T(&b_Xj);
    for (i1 = 0; i1 < nx; i1++) {
      Sj->data[i1] = -Sj->data[i1];
    }

    Sk = 4.0 * m2;
    i1 = Sj->size[0] * Sj->size[1];
    Sj->size[0] = 1;
    emxEnsureCapacity_real_T(Sj, i1);
    nx = Sj->size[0];
    ia = Sj->size[1];
    nx *= ia;
    for (i1 = 0; i1 < nx; i1++) {
      Sj->data[i1] /= Sk;
    }

    nx = Sj->size[1];
    for (k = 0; k + 1 <= nx; k++) {
      Sj->data[k] = std::exp(Sj->data[k]);
    }

    emxInit_real_T(&M1, 2);
    Xcp = 1.4142135623730951 * sum(Sj);

    // расчет параметра В
    i1 = Xj->size[1];
    i2 = Xj->size[1];
    nx = Xj->size[1];
    ia = M1->size[0] * M1->size[1];
    M1->size[0] = i2 - 1;
    M1->size[1] = nx - 1;
    emxEnsureCapacity_real_T(M1, ia);
    nx = (i2 - 1) * (nx - 1);
    for (i2 = 0; i2 < nx; i2++) {
      M1->data[i2] = 0.0;
    }

    for (ia = 0; ia + 1 < i1; ia++) {
      M1->data[ia + M1->size[0] * ia] = Xj->data[ia];
    }

    emxInit_real_T(&M2, 2);
    i1 = M2->size[0] * M2->size[1];
    M2->size[0] = M1->size[0];
    M2->size[1] = M1->size[1];
    emxEnsureCapacity_real_T(M2, i1);
    nx = M1->size[0] * M1->size[1];
    for (i1 = 0; i1 < nx; i1++) {
      M2->data[i1] = M1->data[i1];
    }

    k = M1->size[1];
    Xj_idx_1 = Xj->size[1] - 1;
    iv0[0] = M1->size[0];
    i1 = M1->size[0] * M1->size[1];
    M1->size[0] = iv0[0];
    M1->size[1] = Xj_idx_1;
    emxEnsureCapacity_real_T(M1, i1);
    m = M2->size[0];
    i1 = M1->size[0] * M1->size[1];
    emxEnsureCapacity_real_T(M1, i1);
    nx = M1->size[1];
    for (i1 = 0; i1 < nx; i1++) {
      ia = M1->size[0];
      for (i2 = 0; i2 < ia; i2++) {
        M1->data[i2 + M1->size[0] * i1] = 0.0;
      }
    }

    Xj_idx_1 = Xj->size[1] - 1;
    c = M2->size[0] * (Xj_idx_1 - 1);
    for (cr = 0; cr <= c; cr += m) {
      i1 = cr + m;
      for (ic = cr; ic + 1 <= i1; ic++) {
        M1->data[ic] = 0.0;
      }
    }

    br = 0;
    for (cr = 0; cr <= c; cr += m) {
      nx = 0;
      i1 = br + k;
      for (ib = br + 1; ib <= i1; ib++) {
        ia = nx;
        i2 = cr + m;
        for (ic = cr; ic + 1 <= i2; ic++) {
          ia++;
          M1->data[ic] += M2->data[ia - 1];
        }

        nx += m;
      }

      br += k;
    }

    triu(M1);
    i1 = Xj->size[1];
    i2 = Xj->size[1] - 1;
    nx = Xj->size[1] - 1;
    ia = M2->size[0] * M2->size[1];
    M2->size[0] = i2;
    M2->size[1] = nx;
    emxEnsureCapacity_real_T(M2, ia);
    nx *= i2;
    for (i2 = 0; i2 < nx; i2++) {
      M2->data[i2] = 0.0;
    }

    for (ia = 0; ia + 1 < i1; ia++) {
      M2->data[ia + M2->size[0] * ia] = Xj->data[ia + 1];
    }

    emxInit_real_T(&Bm, 2);
    i1 = Bm->size[0] * Bm->size[1];
    Bm->size[0] = M2->size[0];
    Bm->size[1] = M2->size[1];
    emxEnsureCapacity_real_T(Bm, i1);
    nx = M2->size[0] * M2->size[1];
    for (i1 = 0; i1 < nx; i1++) {
      Bm->data[i1] = M2->data[i1];
    }

    Xj_idx_1 = Xj->size[1] - 1;
    m = Xj->size[1] - 1;
    iv0[1] = M2->size[1];
    i1 = M2->size[0] * M2->size[1];
    M2->size[0] = m;
    M2->size[1] = iv0[1];
    emxEnsureCapacity_real_T(M2, i1);
    m = Xj->size[1] - 1;
    i1 = M2->size[0] * M2->size[1];
    emxEnsureCapacity_real_T(M2, i1);
    nx = M2->size[1];
    for (i1 = 0; i1 < nx; i1++) {
      ia = M2->size[0];
      for (i2 = 0; i2 < ia; i2++) {
        M2->data[i2 + M2->size[0] * i1] = 0.0;
      }
    }

    nx = Xj->size[1] - 1;
    c = nx * (Bm->size[1] - 1);
    for (cr = 0; cr <= c; cr += m) {
      i1 = cr + m;
      for (ic = cr; ic + 1 <= i1; ic++) {
        M2->data[ic] = 0.0;
      }
    }

    br = 0;
    for (cr = 0; cr <= c; cr += m) {
      i1 = br + Xj_idx_1;
      for (ib = br; ib + 1 <= i1; ib++) {
        if (Bm->data[ib] != 0.0) {
          i2 = cr + m;
          for (ic = cr; ic + 1 <= i2; ic++) {
            M2->data[ic] += Bm->data[ib];
          }
        }
      }

      br += Xj_idx_1;
    }

    triu(M2);
    i1 = M1->size[0] * M1->size[1];
    emxEnsureCapacity_real_T(M1, i1);
    ia = M1->size[0];
    nx = M1->size[1];
    nx *= ia;
    for (i1 = 0; i1 < nx; i1++) {
      M1->data[i1] -= M2->data[i1];
    }

    for (i1 = 0; i1 < 2; i1++) {
      iv0[i1] = M1->size[i1];
    }

    i1 = M2->size[0] * M2->size[1];
    M2->size[0] = iv0[0];
    M2->size[1] = iv0[1];
    emxEnsureCapacity_real_T(M2, i1);
    i1 = Bm->size[0] * Bm->size[1];
    Bm->size[0] = iv0[0];
    Bm->size[1] = iv0[1];
    emxEnsureCapacity_real_T(Bm, i1);
    nx = M2->size[0] * M2->size[1];
    k = 0;
    emxFree_real_T(&M2);
    while (k + 1 <= nx) {
      Bm->data[k] = M1->data[k] * M1->data[k];
      k++;
    }

    emxFree_real_T(&M1);
    Sk = 2.0 * m2;
    i1 = Bm->size[0] * Bm->size[1];
    emxEnsureCapacity_real_T(Bm, i1);
    ia = Bm->size[0];
    nx = Bm->size[1];
    nx *= ia;
    for (i1 = 0; i1 < nx; i1++) {
      Bm->data[i1] = -Bm->data[i1] / Sk;
    }

    nx = Bm->size[0] * Bm->size[1];
    for (k = 0; k + 1 <= nx; k++) {
      Bm->data[k] = std::exp(Bm->data[k]);
    }

    triu(Bm);
    b_sum(Bm, Sj);
    Sk = sum(Sj);

    // расчет статистики критерия
    // определения нормальности распределения 
    emxFree_real_T(&Sj);
    emxFree_real_T(&Bm);
    IsNormal = !(((1.0 + (double)Xj->size[1] / 1.7320508075688772) + 2.0 /
                  (double)Xj->size[1] * Sk) - Xcp > qval);
  }

  return IsNormal;
}

//
// File trailer for EppsPallyCriterion.cpp
//
// [EOF]
//
