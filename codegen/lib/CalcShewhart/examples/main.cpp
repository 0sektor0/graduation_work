//
// File: main.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 20-Mar-2018 12:35:48
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
#include "CalcShewhart.h"
#include "EppsPallyCriterion.h"
#include "GetSample.h"
#include "GiriCriterion.h"
#include "HegazyGreenCriterion.h"
#include "MakeMultipleNNPredicions.h"
#include "ShapiroWeakCriterion.h"
#include "SimulateNarxNetwork.h"
#include "main.h"
#include "CalcShewhart_terminate.h"
#include "CalcShewhart_emxAPI.h"
#include "CalcShewhart_initialize.h"

// Function Declarations
static void argInit_1x5_real_T(double result[5]);
static emxArray_real_T *argInit_1xUnbounded_real_T();
static double argInit_real_T();
static void main_CalcShewhart();
static void main_EppsPallyCriterion();
static void main_GetSample();
static void main_GiriCriterion();
static void main_HegazyGreenCriterion();
static void main_MakeMultipleNNPredicions();
static void main_ShapiroWeakCriterion();
static void main_SimulateNarxNetwork();

// Function Definitions

//
// Arguments    : double result[5]
// Return Type  : void
//
static void argInit_1x5_real_T(double result[5])
{
  int idx1;

  // Loop over the array to initialize each element.
  for (idx1 = 0; idx1 < 5; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

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
static void main_CalcShewhart()
{
  emxArray_real_T *Xj;
  double ucl;
  double lcl;

  // Initialize function 'CalcShewhart' input arguments.
  // Initialize function input argument 'Xj'.
  Xj = argInit_1xUnbounded_real_T();

  // Call the entry-point 'CalcShewhart'.
  CalcShewhart(Xj, argInit_real_T(), &ucl, &lcl);
  emxDestroyArray_real_T(Xj);
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
  GetSample(vector_source, argInit_real_T(), argInit_real_T(), sample);
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
static void main_MakeMultipleNNPredicions()
{
  emxArray_real_T *prediction;
  emxArray_real_T *input;
  emxInitArray_real_T(&prediction, 2);

  // Initialize function 'MakeMultipleNNPredicions' input arguments.
  // Initialize function input argument 'input'.
  input = argInit_1xUnbounded_real_T();

  // Call the entry-point 'MakeMultipleNNPredicions'.
  MakeMultipleNNPredicions(input, argInit_real_T(), prediction);
  emxDestroyArray_real_T(prediction);
  emxDestroyArray_real_T(input);
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
static void main_SimulateNarxNetwork()
{
  double dv9[5];
  double dv10[5];
  double b_y1;
  double xf1[5];
  double xf2[5];

  // Initialize function 'SimulateNarxNetwork' input arguments.
  // Initialize function input argument 'xi1'.
  // Initialize function input argument 'xi2'.
  // Call the entry-point 'SimulateNarxNetwork'.
  argInit_1x5_real_T(dv9);
  argInit_1x5_real_T(dv10);
  SimulateNarxNetwork(argInit_real_T(), argInit_real_T(), dv9, dv10, &b_y1, xf1,
                      xf2);
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
  CalcShewhart_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_CalcShewhart();
  main_EppsPallyCriterion();
  main_GetSample();
  main_GiriCriterion();
  main_HegazyGreenCriterion();
  main_MakeMultipleNNPredicions();
  main_ShapiroWeakCriterion();
  main_SimulateNarxNetwork();

  // Terminate the application.
  // You do not need to do this more than one time.
  CalcShewhart_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
