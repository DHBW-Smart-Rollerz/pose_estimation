//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xgeqrf.h
//
// Code generation for function 'xgeqrf'
//

#ifndef XGEQRF_H
#define XGEQRF_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace lapack {
void b_xgeqrf(double A[10], double tau[2]);

void c_xgeqrf(double A[15], double tau[3]);

void xgeqrf(double A[18], double tau[3]);

} // namespace lapack
} // namespace internal
} // namespace coder

#endif
// End of code generation (xgeqrf.h)
