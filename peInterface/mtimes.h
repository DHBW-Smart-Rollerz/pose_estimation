//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// mtimes.h
//
// Code generation for function 'mtimes'
//

#ifndef MTIMES_H
#define MTIMES_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace blas {
void b_mtimes(const double A[9], const double B[6], double C[6]);

void mtimes(const double A[9], const double B[9], double C[9]);

} // namespace blas
} // namespace internal
} // namespace coder

#endif
// End of code generation (mtimes.h)
