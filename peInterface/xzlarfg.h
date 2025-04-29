//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xzlarfg.h
//
// Code generation for function 'xzlarfg'
//

#ifndef XZLARFG_H
#define XZLARFG_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace reflapack {
double b_xzlarfg(int n, double &alpha1, double x[10], int ix0);

double c_xzlarfg(int n, double &alpha1, double x[15], int ix0);

double xzlarfg(int n, double &alpha1, double x[18], int ix0);

} // namespace reflapack
} // namespace internal
} // namespace coder

#endif
// End of code generation (xzlarfg.h)
