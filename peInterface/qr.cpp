//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// qr.cpp
//
// Code generation for function 'qr'
//

// Include files
#include "qr.h"
#include "rt_nonfinite.h"
#include "xgeqrf.h"
#include "xorgqr.h"
#include <algorithm>
#include <cstring>

// Function Definitions
namespace coder {
void b_qr(const double A[10], double Q[10], double R[4])
{
  double tau[2];
  std::copy(&A[0], &A[10], &Q[0]);
  internal::lapack::b_xgeqrf(Q, tau);
  for (int j{0}; j < 2; j++) {
    for (int i{0}; i <= j; i++) {
      R[i + (j << 1)] = Q[i + 5 * j];
    }
    if (j + 2 <= 2) {
      R[(j << 1) + 1] = 0.0;
    }
  }
  internal::lapack::b_xorgqr(Q, tau);
}

void c_qr(const double A[15], double Q[15], double R[9])
{
  double tau[3];
  std::copy(&A[0], &A[15], &Q[0]);
  internal::lapack::c_xgeqrf(Q, tau);
  for (int j{0}; j < 3; j++) {
    int i;
    for (i = 0; i <= j; i++) {
      R[i + 3 * j] = Q[i + 5 * j];
    }
    i = j + 2;
    if (i <= 3) {
      std::memset(&R[(j * 3 + i) + -1], 0,
                  static_cast<unsigned int>(-i + 4) * sizeof(double));
    }
  }
  internal::lapack::c_xorgqr(Q, tau);
}

void qr(const double A[18], double Q[18], double R[9])
{
  double tau[3];
  std::copy(&A[0], &A[18], &Q[0]);
  internal::lapack::xgeqrf(Q, tau);
  for (int j{0}; j < 3; j++) {
    int i;
    for (i = 0; i <= j; i++) {
      R[i + 3 * j] = Q[i + 6 * j];
    }
    i = j + 2;
    if (i <= 3) {
      std::memset(&R[(j * 3 + i) + -1], 0,
                  static_cast<unsigned int>(-i + 4) * sizeof(double));
    }
  }
  internal::lapack::xorgqr(Q, tau);
}

} // namespace coder

// End of code generation (qr.cpp)
