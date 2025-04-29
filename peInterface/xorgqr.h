//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xorgqr.h
//
// Code generation for function 'xorgqr'
//

#ifndef XORGQR_H
#define XORGQR_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace lapack {
void b_xorgqr(double A[10], const double tau[2]);

void c_xorgqr(double A[15], const double tau[3]);

void xorgqr(double A[18], const double tau[3]);

} // namespace lapack
} // namespace internal
} // namespace coder

#endif
// End of code generation (xorgqr.h)
