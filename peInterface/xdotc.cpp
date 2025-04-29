//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xdotc.cpp
//
// Code generation for function 'xdotc'
//

// Include files
#include "xdotc.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
double b_xdotc(int n, const double x[4], int ix0, const double y[4], int iy0)
{
  double d;
  d = 0.0;
  if (n >= 1) {
    d = x[ix0 - 1] * y[iy0 - 1];
  }
  return d;
}

double xdotc(int n, const double x[9], int ix0, const double y[9], int iy0)
{
  double d;
  d = 0.0;
  if (n >= 1) {
    int i;
    i = static_cast<unsigned char>(n);
    for (int k{0}; k < i; k++) {
      d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
    }
  }
  return d;
}

double xdotc(const double x[4], const double y[4])
{
  return x[0] * y[2] + x[1] * y[3];
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xdotc.cpp)
