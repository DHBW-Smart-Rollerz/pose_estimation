//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// trisolve.cpp
//
// Code generation for function 'trisolve'
//

// Include files
#include "trisolve.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder {
namespace internal {
void b_trisolve(const double A[4], double B[6])
{
  for (int j{0}; j < 3; j++) {
    int jBcol;
    jBcol = j << 1;
    for (int k{1}; k >= 0; k--) {
      double d;
      int i;
      int kAcol;
      kAcol = k << 1;
      i = k + jBcol;
      d = B[i];
      if (d != 0.0) {
        B[i] = d / A[k + kAcol];
        for (int b_i{0}; b_i < k; b_i++) {
          B[jBcol] -= B[i] * A[kAcol];
        }
      }
    }
  }
}

void trisolve(const double A[4], double B[6])
{
  for (int j{0}; j < 3; j++) {
    int jBcol;
    jBcol = (j << 1) - 1;
    for (int k{0}; k < 2; k++) {
      double d;
      int i;
      int kAcol;
      kAcol = k << 1;
      i = (k + jBcol) + 1;
      d = B[i];
      if (d != 0.0) {
        int i1;
        B[i] = d / A[k + kAcol];
        i1 = k + 2;
        for (int b_i{i1}; b_i < 3; b_i++) {
          B[jBcol + 2] -= B[i] * A[kAcol + 1];
        }
      }
    }
  }
}

} // namespace internal
} // namespace coder

// End of code generation (trisolve.cpp)
