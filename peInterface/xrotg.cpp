//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xrotg.cpp
//
// Code generation for function 'xrotg'
//

// Include files
#include "xrotg.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
double xrotg(double &a, double &b, double &s)
{
  double absa;
  double absb;
  double c;
  double scale;
  c = b;
  absa = std::abs(a);
  absb = std::abs(b);
  if (absa > absb) {
    c = a;
  }
  scale = absa + absb;
  if (scale == 0.0) {
    s = 0.0;
    c = 1.0;
    a = 0.0;
    b = 0.0;
  } else {
    double ads;
    double bds;
    ads = absa / scale;
    bds = absb / scale;
    scale *= std::sqrt(ads * ads + bds * bds);
    if (c < 0.0) {
      scale = -scale;
    }
    c = a / scale;
    s = b / scale;
    if (absa > absb) {
      b = s;
    } else if (c != 0.0) {
      b = 1.0 / c;
    } else {
      b = 1.0;
    }
    a = scale;
  }
  return c;
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xrotg.cpp)
