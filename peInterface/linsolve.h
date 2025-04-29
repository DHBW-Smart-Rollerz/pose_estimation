//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// linsolve.h
//
// Code generation for function 'linsolve'
//

#ifndef LINSOLVE_H
#define LINSOLVE_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void b_linsolve(const double A[4], const double B[6], double C[6]);

void linsolve(const double A[4], const double B[6], double C[6]);

} // namespace coder

#endif
// End of code generation (linsolve.h)
