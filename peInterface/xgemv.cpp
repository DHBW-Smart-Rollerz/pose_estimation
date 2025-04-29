//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xgemv.cpp
//
// Code generation for function 'xgemv'
//

// Include files
#include "xgemv.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Declarations
static int div_nde_s32_floor(int numerator, int denominator);

// Function Definitions
static int div_nde_s32_floor(int numerator, int denominator)
{
  int quotient;
  if (((numerator < 0) != (denominator < 0)) &&
      (numerator % denominator != 0)) {
    quotient = -1;
  } else {
    quotient = 0;
  }
  quotient += numerator / denominator;
  return quotient;
}

namespace coder {
namespace internal {
namespace blas {
void b_xgemv(int m, int n, const double A[10], int ia0, const double x[10],
             int ix0, double y[2])
{
  if (n != 0) {
    y[0] = 0.0;
    for (int iac{ia0}; iac <= ia0; iac += 5) {
      double c;
      int i;
      c = 0.0;
      i = iac + m;
      for (int ia{iac}; ia < i; ia++) {
        c += A[ia - 1] * x[((ix0 + ia) - iac) - 1];
      }
      i = div_nde_s32_floor(iac - ia0, 5);
      y[i] += c;
    }
  }
}

void c_xgemv(int m, int n, const double A[15], int ia0, const double x[15],
             int ix0, double y[3])
{
  if (n != 0) {
    int i;
    i = static_cast<unsigned char>(n);
    std::memset(&y[0], 0, static_cast<unsigned int>(i) * sizeof(double));
    i = ia0 + 5 * (n - 1);
    for (int iac{ia0}; iac <= i; iac += 5) {
      double c;
      int i1;
      c = 0.0;
      i1 = iac + m;
      for (int ia{iac}; ia < i1; ia++) {
        c += A[ia - 1] * x[((ix0 + ia) - iac) - 1];
      }
      i1 = div_nde_s32_floor(iac - ia0, 5);
      y[i1] += c;
    }
  }
}

void xgemv(int m, int n, int ia0, int ix0, double y[9], int iy0)
{
  if (m != 0) {
    int i;
    i = ia0 + 3 * (n - 1);
    for (int iac{ia0}; iac <= i; iac += 3) {
      double c;
      int i1;
      c = 0.0;
      i1 = iac + m;
      for (int ia{iac}; ia < i1; ia++) {
        c += y[ia - 1] * y[((ix0 + ia) - iac) - 1];
      }
      i1 = (iy0 + div_nde_s32_floor(iac - ia0, 3) * 3) - 1;
      y[i1] -= c;
    }
  }
}

void xgemv(int m, int n, const double A[18], int ia0, const double x[18],
           int ix0, double y[3])
{
  if (n != 0) {
    int i;
    i = static_cast<unsigned char>(n);
    std::memset(&y[0], 0, static_cast<unsigned int>(i) * sizeof(double));
    i = ia0 + 6 * (n - 1);
    for (int iac{ia0}; iac <= i; iac += 6) {
      double c;
      int i1;
      c = 0.0;
      i1 = iac + m;
      for (int ia{iac}; ia < i1; ia++) {
        c += A[ia - 1] * x[((ix0 + ia) - iac) - 1];
      }
      i1 = div_nde_s32_floor(iac - ia0, 6);
      y[i1] += c;
    }
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xgemv.cpp)
