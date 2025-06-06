//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// chol.h
//
// Code generation for function 'chol'
//

#ifndef CHOL_H
#define CHOL_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
int b_chol(double A[4], int &jmax);

void b_chol(double A[4]);

int chol(double A[9], int &jmax);

void chol(double A[9]);

} // namespace internal
} // namespace coder

#endif
// End of code generation (chol.h)
