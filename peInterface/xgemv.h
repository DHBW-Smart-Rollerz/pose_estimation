//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xgemv.h
//
// Code generation for function 'xgemv'
//

#ifndef XGEMV_H
#define XGEMV_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace blas {
void b_xgemv(int m, int n, const double A[10], int ia0, const double x[10],
             int ix0, double y[2]);

void c_xgemv(int m, int n, const double A[15], int ia0, const double x[15],
             int ix0, double y[3]);

void xgemv(int m, int n, int ia0, int ix0, double y[9], int iy0);

void xgemv(int m, int n, const double A[18], int ia0, const double x[18],
           int ix0, double y[3]);

} // namespace blas
} // namespace internal
} // namespace coder

#endif
// End of code generation (xgemv.h)
