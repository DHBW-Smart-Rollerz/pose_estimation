//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_peInterface_api.h
//
// Code generation for function 'peInterface'
//

#ifndef _CODER_PEINTERFACE_API_H
#define _CODER_PEINTERFACE_API_H

// Include files
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void peInterface(real_T parameters[6], real_T dt, real_T processNoise[9],
                 real_T measurementNoise[4], real_T u[2], real_T z[2],
                 real_T outputArg1[3], real_T outputArg2[3]);

void peInterface_api(const mxArray *const prhs[6], int32_T nlhs,
                     const mxArray *plhs[2]);

void peInterface_atexit();

void peInterface_initialize();

void peInterface_terminate();

void peInterface_xil_shutdown();

void peInterface_xil_terminate();

#endif
// End of code generation (_coder_peInterface_api.h)
