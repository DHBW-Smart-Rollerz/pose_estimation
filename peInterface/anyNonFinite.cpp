//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// anyNonFinite.cpp
//
// Code generation for function 'anyNonFinite'
//

// Include files
#include "anyNonFinite.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace coder {
namespace internal {
boolean_T anyNonFinite(const double x[9])
{
  boolean_T p;
  p = true;
  for (int k{0}; k < 9; k++) {
    if (p) {
      double d;
      d = x[k];
      if (std::isinf(d) || std::isnan(d)) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  return !p;
}

boolean_T b_anyNonFinite(const double x[4])
{
  boolean_T p;
  p = true;
  for (int k{0}; k < 4; k++) {
    if (p) {
      double d;
      d = x[k];
      if (std::isinf(d) || std::isnan(d)) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  return !p;
}

} // namespace internal
} // namespace coder

// End of code generation (anyNonFinite.cpp)
