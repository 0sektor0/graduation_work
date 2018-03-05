//
// File: main.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 05-Mar-2018 18:06:23
//

//***********************************************************************
// This automatically generated example C main file shows how to call
// entry-point functions that MATLAB Coder generated. You must customize
// this file for your application. Do not modify this file directly.
// Instead, make a copy of this file, modify it, and integrate it into
// your development environment.
//
// This file initializes entry-point function arguments to a default
// size and value before calling the entry-point functions. It does
// not store or use any values returned from the entry-point functions.
// If necessary, it does pre-allocate memory for returned values.
// You can use this file as a starting point for a main function that
// you can deploy in your application.
//
// After you copy the file, and before you deploy it, you must make the
// following changes:
// * For variable-size function arguments, change the example sizes to
// the sizes that your application requires.
// * Change the example values of function arguments to the values that
// your application requires.
// * If the entry-point functions return values, store these values or
// otherwise use them as required by your application.
//
//***********************************************************************
// Include Files
#include "rt_nonfinite.h"
#include "EppsPallyCriterion.h"
#include "GetSample.h"
#include "GiriCriterion.h"
#include "HegazyGreenCriterion.h"
#include "ShapiroWeakCriterion.h"
#include "ShowPlot.h"
#include "SimulateNarx.h"
#include "main.h"
#include "libNarxStatSys_terminate.h"
#include "libNarxStatSys_emxAPI.h"
#include "libNarxStatSys_initialize.h"

// Function Declarations
static emxArray_real_T *argInit_1xUnbounded_real_T();
static int argInit_int32_T();
static double argInit_real_T();
static void main_EppsPallyCriterion();
static void main_GetSample();
static void main_GiriCriterion();
static void main_HegazyGreenCriterion();
static void main_ShapiroWeakCriterion();
static void main_ShowPlot();
static void main_SimulateNarx();

// Function Definitions

//
// Arguments    : void
// Return Type  : emxArray_real_T *
//
static emxArray_real_T *argInit_1xUnbounded_real_T()
{
  emxArray_real_T *result;
  static int iv1[2] = { 1, 2 };

  int idx1;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result = emxCreateND_real_T(2, *(int (*)[2])&iv1[0]);

  // Loop over the array to initialize each element.
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result->data[result->size[0] * idx1] = argInit_real_T();
  }

  return result;
}

//
// Arguments    : void
// Return Type  : int
//
static int argInit_int32_T()
{
  return 0;
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_EppsPallyCriterion()
{
  emxArray_real_T *Xj;
  boolean_T IsNormal;

  // Initialize function 'EppsPallyCriterion' input arguments.
  // Initialize function input argument 'Xj'.
  Xj = argInit_1xUnbounded_real_T();

  // Call the entry-point 'EppsPallyCriterion'.
  IsNormal = EppsPallyCriterion(Xj, argInit_real_T());
  emxDestroyArray_real_T(Xj);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_GetSample()
{
  emxArray_real_T *sample;
  emxArray_real_T *vector_source;
  emxInitArray_real_T(&sample, 2);

  // Initialize function 'GetSample' input arguments.
  // Initialize function input argument 'vector_source'.
  vector_source = argInit_1xUnbounded_real_T();

  // Call the entry-point 'GetSample'.
  GetSample(vector_source, argInit_int32_T(), argInit_int32_T(), sample);
  emxDestroyArray_real_T(sample);
  emxDestroyArray_real_T(vector_source);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_GiriCriterion()
{
  emxArray_real_T *Xj;
  boolean_T IsNormal;

  // Initialize function 'GiriCriterion' input arguments.
  // Initialize function input argument 'Xj'.
  Xj = argInit_1xUnbounded_real_T();

  // Call the entry-point 'GiriCriterion'.
  IsNormal = GiriCriterion(Xj, argInit_real_T());
  emxDestroyArray_real_T(Xj);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_HegazyGreenCriterion()
{
  emxArray_real_T *Xj;
  boolean_T IsNormal;

  // Initialize function 'HegazyGreenCriterion' input arguments.
  // Initialize function input argument 'Xj'.
  Xj = argInit_1xUnbounded_real_T();

  // Call the entry-point 'HegazyGreenCriterion'.
  IsNormal = HegazyGreenCriterion(Xj, argInit_real_T());
  emxDestroyArray_real_T(Xj);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_ShapiroWeakCriterion()
{
  emxArray_real_T *Xj;
  boolean_T IsNormal;

  // Initialize function 'ShapiroWeakCriterion' input arguments.
  // Initialize function input argument 'Xj'.
  Xj = argInit_1xUnbounded_real_T();

  // Call the entry-point 'ShapiroWeakCriterion'.
  IsNormal = ShapiroWeakCriterion(Xj);
  emxDestroyArray_real_T(Xj);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_ShowPlot()
{
  emxArray_real_T *Xj;

  // Initialize function 'ShowPlot' input arguments.
  // Initialize function input argument 'Xj'.
  Xj = argInit_1xUnbounded_real_T();

  // Call the entry-point 'ShowPlot'.
  ShowPlot(Xj);
  emxDestroyArray_real_T(Xj);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_SimulateNarx()
{
  emxArray_real_T *b_y1;
  emxArray_real_T *x1;
  emxArray_real_T *x2;
  emxArray_real_T *xi1;
  emxArray_real_T *xi2;
  double xf1_data[10];
  int xf1_size[2];
  double xf2_data[10];
  int xf2_size[2];
  emxInitArray_real_T(&b_y1, 2);

  // Initialize function 'SimulateNarx' input arguments.
  // Initialize function input argument 'x1'.
  x1 = argInit_1xUnbounded_real_T();

  // Initialize function input argument 'x2'.
  x2 = argInit_1xUnbounded_real_T();

  // Initialize function input argument 'xi1'.
  xi1 = argInit_1xUnbounded_real_T();

  // Initialize function input argument 'xi2'.
  xi2 = argInit_1xUnbounded_real_T();

  // Call the entry-point 'SimulateNarx'.
  SimulateNarx(x1, x2, xi1, xi2, b_y1, xf1_data, xf1_size, xf2_data, xf2_size);
  emxDestroyArray_real_T(b_y1);
  emxDestroyArray_real_T(xi2);
  emxDestroyArray_real_T(xi1);
  emxDestroyArray_real_T(x2);
  emxDestroyArray_real_T(x1);
}

//
// Arguments    : int argc
//                const char * const argv[]
// Return Type  : int
//
int main(int, const char * const [])
{
  // Initialize the application.
  // You do not need to do this more than one time.
  libNarxStatSys_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_EppsPallyCriterion();
  main_GetSample();
  main_GiriCriterion();
  main_HegazyGreenCriterion();
  main_ShapiroWeakCriterion();
  main_ShowPlot();
  main_SimulateNarx();

  // Terminate the application.
  // You do not need to do this more than one time.
  libNarxStatSys_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
