//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// linsolve.cpp
//
// Code generation for function 'linsolve'
//

// Include files
#include "linsolve.h"
#include "rt_nonfinite.h"
#include "trisolve.h"

// Function Definitions
namespace coder {
void b_linsolve(const double A[4], const double B[6], double C[6])
{
  for (int j{0}; j < 3; j++) {
    int C_tmp;
    C_tmp = j << 1;
    C[C_tmp] = B[C_tmp];
    C[C_tmp + 1] = B[C_tmp + 1];
  }
  internal::b_trisolve(A, C);
}

void linsolve(const double A[4], const double B[6], double C[6])
{
  for (int j{0}; j < 3; j++) {
    int C_tmp;
    C_tmp = j << 1;
    C[C_tmp] = B[C_tmp];
    C[C_tmp + 1] = B[C_tmp + 1];
  }
  internal::trisolve(A, C);
}

} // namespace coder

// End of code generation (linsolve.cpp)
