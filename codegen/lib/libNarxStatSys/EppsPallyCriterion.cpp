//
// File: EppsPallyCriterion.cpp
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
  static const double dv0[9] = { 0.271, 0.275, 0.279, 0.284, 0.287, 0.289, 0.29,
    0.291, 0.29 };

  static const double dv1[9] = { 0.347, 0.35, 0.357, 0.366, 0.368, 0.371, 0.374,
    0.376, 0.379 };

  static const double dv2[9] = { 0.426, 0.428, 0.437, 0.447, 0.45, 0.459, 0.46,
    0.464, 0.467 };

  static const double dv3[9] = { 0.526, 0.537, 0.545, 0.56, 0.564, 0.569, 0.574,
    0.583, 0.59 };

  double qval;
  boolean_T exitg1;
  static const unsigned char uv0[9] = { 8U, 9U, 10U, 15U, 20U, 30U, 50U, 100U,
    200U };

  emxArray_real_T *b_Xj;
  double Xcp;
  int i0;
  emxArray_real_T *Sj;
  double Sk;
  double m2;
  int k;
  emxArray_real_T *M1;
  int i1;
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
      memcpy(&quantile[0], &dv0[0], 9U * sizeof(double));
      break;

     case 1:
      memcpy(&quantile[0], &dv1[0], 9U * sizeof(double));
      break;

     case 2:
      memcpy(&quantile[0], &dv2[0], 9U * sizeof(double));
      break;

     case 3:
      memcpy(&quantile[0], &dv3[0], 9U * sizeof(double));
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
    i0 = b_Xj->size[0] * b_Xj->size[1];
    b_Xj->size[0] = 1;
    b_Xj->size[1] = Xj->size[1];
    emxEnsureCapacity_real_T(b_Xj, i0);
    nx = Xj->size[0] * Xj->size[1];
    for (i0 = 0; i0 < nx; i0++) {
      b_Xj->data[i0] = Xj->data[i0] - Xcp;
    }

    emxInit_real_T(&Sj, 2);
    power(b_Xj, Sj);
    Sk = sum(Sj);
    m2 = Sk / (double)Xj->size[1];
    i0 = b_Xj->size[0] * b_Xj->size[1];
    b_Xj->size[0] = 1;
    b_Xj->size[1] = Xj->size[1];
    emxEnsureCapacity_real_T(b_Xj, i0);
    nx = Xj->size[0] * Xj->size[1];
    for (i0 = 0; i0 < nx; i0++) {
      b_Xj->data[i0] = Xj->data[i0] - Xcp;
    }

    power(b_Xj, Sj);
    i0 = Sj->size[0] * Sj->size[1];
    Sj->size[0] = 1;
    emxEnsureCapacity_real_T(Sj, i0);
    nx = Sj->size[0];
    ia = Sj->size[1];
    nx *= ia;
    emxFree_real_T(&b_Xj);
    for (i0 = 0; i0 < nx; i0++) {
      Sj->data[i0] = -Sj->data[i0];
    }

    Sk = 4.0 * m2;
    i0 = Sj->size[0] * Sj->size[1];
    Sj->size[0] = 1;
    emxEnsureCapacity_real_T(Sj, i0);
    nx = Sj->size[0];
    ia = Sj->size[1];
    nx *= ia;
    for (i0 = 0; i0 < nx; i0++) {
      Sj->data[i0] /= Sk;
    }

    nx = Sj->size[1];
    for (k = 0; k + 1 <= nx; k++) {
      Sj->data[k] = std::exp(Sj->data[k]);
    }

    emxInit_real_T(&M1, 2);
    Xcp = 1.4142135623730951 * sum(Sj);

    // расчет параметра В
    i0 = Xj->size[1];
    i1 = Xj->size[1];
    nx = Xj->size[1];
    ia = M1->size[0] * M1->size[1];
    M1->size[0] = i1 - 1;
    M1->size[1] = nx - 1;
    emxEnsureCapacity_real_T(M1, ia);
    nx = (i1 - 1) * (nx - 1);
    for (i1 = 0; i1 < nx; i1++) {
      M1->data[i1] = 0.0;
    }

    for (ia = 0; ia + 1 < i0; ia++) {
      M1->data[ia + M1->size[0] * ia] = Xj->data[ia];
    }

    emxInit_real_T(&M2, 2);
    i0 = M2->size[0] * M2->size[1];
    M2->size[0] = M1->size[0];
    M2->size[1] = M1->size[1];
    emxEnsureCapacity_real_T(M2, i0);
    nx = M1->size[0] * M1->size[1];
    for (i0 = 0; i0 < nx; i0++) {
      M2->data[i0] = M1->data[i0];
    }

    k = M1->size[1];
    Xj_idx_1 = Xj->size[1] - 1;
    iv0[0] = M1->size[0];
    i0 = M1->size[0] * M1->size[1];
    M1->size[0] = iv0[0];
    M1->size[1] = Xj_idx_1;
    emxEnsureCapacity_real_T(M1, i0);
    m = M2->size[0];
    i0 = M1->size[0] * M1->size[1];
    emxEnsureCapacity_real_T(M1, i0);
    nx = M1->size[1];
    for (i0 = 0; i0 < nx; i0++) {
      ia = M1->size[0];
      for (i1 = 0; i1 < ia; i1++) {
        M1->data[i1 + M1->size[0] * i0] = 0.0;
      }
    }

    Xj_idx_1 = Xj->size[1] - 1;
    c = M2->size[0] * (Xj_idx_1 - 1);
    for (cr = 0; cr <= c; cr += m) {
      i0 = cr + m;
      for (ic = cr; ic + 1 <= i0; ic++) {
        M1->data[ic] = 0.0;
      }
    }

    br = 0;
    for (cr = 0; cr <= c; cr += m) {
      nx = 0;
      i0 = br + k;
      for (ib = br + 1; ib <= i0; ib++) {
        ia = nx;
        i1 = cr + m;
        for (ic = cr; ic + 1 <= i1; ic++) {
          ia++;
          M1->data[ic] += M2->data[ia - 1];
        }

        nx += m;
      }

      br += k;
    }

    triu(M1);
    i0 = Xj->size[1];
    i1 = Xj->size[1] - 1;
    nx = Xj->size[1] - 1;
    ia = M2->size[0] * M2->size[1];
    M2->size[0] = i1;
    M2->size[1] = nx;
    emxEnsureCapacity_real_T(M2, ia);
    nx *= i1;
    for (i1 = 0; i1 < nx; i1++) {
      M2->data[i1] = 0.0;
    }

    for (ia = 0; ia + 1 < i0; ia++) {
      M2->data[ia + M2->size[0] * ia] = Xj->data[ia + 1];
    }

    emxInit_real_T(&Bm, 2);
    i0 = Bm->size[0] * Bm->size[1];
    Bm->size[0] = M2->size[0];
    Bm->size[1] = M2->size[1];
    emxEnsureCapacity_real_T(Bm, i0);
    nx = M2->size[0] * M2->size[1];
    for (i0 = 0; i0 < nx; i0++) {
      Bm->data[i0] = M2->data[i0];
    }

    Xj_idx_1 = Xj->size[1] - 1;
    m = Xj->size[1] - 1;
    iv0[1] = M2->size[1];
    i0 = M2->size[0] * M2->size[1];
    M2->size[0] = m;
    M2->size[1] = iv0[1];
    emxEnsureCapacity_real_T(M2, i0);
    m = Xj->size[1] - 1;
    i0 = M2->size[0] * M2->size[1];
    emxEnsureCapacity_real_T(M2, i0);
    nx = M2->size[1];
    for (i0 = 0; i0 < nx; i0++) {
      ia = M2->size[0];
      for (i1 = 0; i1 < ia; i1++) {
        M2->data[i1 + M2->size[0] * i0] = 0.0;
      }
    }

    nx = Xj->size[1] - 1;
    c = nx * (Bm->size[1] - 1);
    for (cr = 0; cr <= c; cr += m) {
      i0 = cr + m;
      for (ic = cr; ic + 1 <= i0; ic++) {
        M2->data[ic] = 0.0;
      }
    }

    br = 0;
    for (cr = 0; cr <= c; cr += m) {
      i0 = br + Xj_idx_1;
      for (ib = br; ib + 1 <= i0; ib++) {
        if (Bm->data[ib] != 0.0) {
          i1 = cr + m;
          for (ic = cr; ic + 1 <= i1; ic++) {
            M2->data[ic] += Bm->data[ib];
          }
        }
      }

      br += Xj_idx_1;
    }

    triu(M2);
    i0 = M1->size[0] * M1->size[1];
    emxEnsureCapacity_real_T(M1, i0);
    ia = M1->size[0];
    nx = M1->size[1];
    nx *= ia;
    for (i0 = 0; i0 < nx; i0++) {
      M1->data[i0] -= M2->data[i0];
    }

    for (i0 = 0; i0 < 2; i0++) {
      iv0[i0] = M1->size[i0];
    }

    i0 = M2->size[0] * M2->size[1];
    M2->size[0] = iv0[0];
    M2->size[1] = iv0[1];
    emxEnsureCapacity_real_T(M2, i0);
    i0 = Bm->size[0] * Bm->size[1];
    Bm->size[0] = iv0[0];
    Bm->size[1] = iv0[1];
    emxEnsureCapacity_real_T(Bm, i0);
    nx = M2->size[0] * M2->size[1];
    k = 0;
    emxFree_real_T(&M2);
    while (k + 1 <= nx) {
      Bm->data[k] = M1->data[k] * M1->data[k];
      k++;
    }

    emxFree_real_T(&M1);
    Sk = 2.0 * m2;
    i0 = Bm->size[0] * Bm->size[1];
    emxEnsureCapacity_real_T(Bm, i0);
    ia = Bm->size[0];
    nx = Bm->size[1];
    nx *= ia;
    for (i0 = 0; i0 < nx; i0++) {
      Bm->data[i0] = -Bm->data[i0] / Sk;
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
