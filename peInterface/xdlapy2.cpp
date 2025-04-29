//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xdlapy2.cpp
//
// Code generation for function 'xdlapy2'
//

// Include files
#include "xdlapy2.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace coder {
namespace internal {
double xdlapy2(double x1, double x2)
{
  double b;
  double y;
  y = std::abs(x1);
  b = std::abs(x2);
  if (y < b) {
    y /= b;
    y = b * std::sqrt(y * y + 1.0);
  } else if (y > b) {
    b /= y;
    y *= std::sqrt(b * b + 1.0);
  } else if (std::isnan(b)) {
    y = rtNaN;
  } else {
    y *= 1.4142135623730951;
  }
  return y;
}

} // namespace internal
} // namespace coder

// End of code generation (xdlapy2.cpp)
