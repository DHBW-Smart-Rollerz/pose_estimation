//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// svd.cpp
//
// Code generation for function 'svd'
//

// Include files
#include "svd.h"
#include "anyNonFinite.h"
#include "rt_nonfinite.h"
#include "svd1.h"
#include <cstring>

// Function Definitions
namespace coder {
void b_svd(const double A[4], double U[4], double S[4], double V[4])
{
  double s[2];
  if (!internal::b_anyNonFinite(A)) {
    internal::d_svd(A, U, s, V);
  } else {
    U[0] = rtNaN;
    U[1] = rtNaN;
    U[2] = rtNaN;
    U[3] = rtNaN;
    s[0] = rtNaN;
    s[1] = rtNaN;
    V[0] = rtNaN;
    V[1] = rtNaN;
    V[2] = rtNaN;
    V[3] = rtNaN;
  }
  S[1] = 0.0;
  S[2] = 0.0;
  S[0] = s[0];
  S[3] = s[1];
}

void svd(const double A[9], double U[9], double S[9], double V[9])
{
  double s[3];
  if (!internal::anyNonFinite(A)) {
    internal::c_svd(A, U, s, V);
  } else {
    s[0] = rtNaN;
    s[1] = rtNaN;
    s[2] = rtNaN;
    for (int i{0}; i < 9; i++) {
      U[i] = rtNaN;
      V[i] = rtNaN;
    }
  }
  std::memset(&S[0], 0, 9U * sizeof(double));
  S[0] = s[0];
  S[4] = s[1];
  S[8] = s[2];
}

} // namespace coder

// End of code generation (svd.cpp)
