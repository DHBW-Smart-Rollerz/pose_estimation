//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xaxpy.cpp
//
// Code generation for function 'xaxpy'
//

// Include files
#include "xaxpy.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
void xaxpy(double a, const double x[9], int ix0, double y[3])
{
  if (!(a == 0.0)) {
    for (int k{0}; k < 2; k++) {
      y[k + 1] += a * x[(ix0 + k) - 1];
    }
  }
}

void xaxpy(double a, const double x[3], double y[9], int iy0)
{
  if (!(a == 0.0)) {
    for (int k{0}; k < 2; k++) {
      int i;
      i = (iy0 + k) - 1;
      y[i] += a * x[k + 1];
    }
  }
}

void xaxpy(int n, double a, int ix0, double y[9], int iy0)
{
  if (!(a == 0.0)) {
    for (int k{0}; k < n; k++) {
      int i;
      i = (iy0 + k) - 1;
      y[i] += a * y[(ix0 + k) - 1];
    }
  }
}

void xaxpy(double a, double y[4])
{
  if (!(a == 0.0)) {
    y[2] += a * y[0];
    y[3] += a * y[1];
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xaxpy.cpp)
