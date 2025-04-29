//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// svdPSD.cpp
//
// Code generation for function 'svdPSD'
//

// Include files
#include "svdPSD.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include <cmath>

// Function Definitions
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
void b_svdPSD(const double A[4], double R[4])
{
  double S[4];
  double V[4];
  double a__1[4];
  double d;
  double d1;
  double d2;
  double d3;
  b_svd(A, a__1, S, V);
  S[0] = std::sqrt(S[0]);
  S[1] = std::sqrt(S[1]);
  S[2] = std::sqrt(S[2]);
  S[3] = std::sqrt(S[3]);
  d = S[0];
  d1 = S[1];
  d2 = S[2];
  d3 = S[3];
  for (int i{0}; i < 2; i++) {
    double d4;
    double d5;
    d4 = V[i + 2];
    d5 = V[i];
    R[i] = d5 * d + d4 * d1;
    R[i + 2] = d5 * d2 + d4 * d3;
  }
}

void svdPSD(const double A[9], double R[9])
{
  double S[9];
  double V[9];
  double a__1[9];
  svd(A, a__1, S, V);
  for (int k{0}; k < 9; k++) {
    S[k] = std::sqrt(S[k]);
  }
  for (int k{0}; k < 3; k++) {
    double d;
    double d1;
    double d2;
    d = V[k];
    d1 = V[k + 3];
    d2 = V[k + 6];
    for (int i{0}; i < 3; i++) {
      R[k + 3 * i] = (d * S[3 * i] + d1 * S[3 * i + 1]) + d2 * S[3 * i + 2];
    }
  }
}

} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

// End of code generation (svdPSD.cpp)
