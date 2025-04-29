//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xorgqr.cpp
//
// Code generation for function 'xorgqr'
//

// Include files
#include "xorgqr.h"
#include "rt_nonfinite.h"
#include "xzlarf.h"

// Function Definitions
namespace coder {
namespace internal {
namespace lapack {
void b_xorgqr(double A[10], const double tau[2])
{
  double work[2];
  int itau;
  itau = 1;
  work[0] = 0.0;
  work[1] = 0.0;
  for (int i{1}; i >= 0; i--) {
    int b_i;
    int iaii;
    int ix0;
    iaii = i + i * 5;
    if (i + 1 < 2) {
      A[iaii] = 1.0;
      reflapack::xzlarf(iaii + 1, tau[itau], A, iaii + 6, work);
    }
    ix0 = iaii + 2;
    b_i = (iaii - i) + 5;
    for (int k{ix0}; k <= b_i; k++) {
      A[k - 1] *= -tau[itau];
    }
    A[iaii] = 1.0 - tau[itau];
    for (itau = 0; itau < i; itau++) {
      A[iaii - 1] = 0.0;
    }
    itau = i - 1;
  }
}

void c_xorgqr(double A[15], const double tau[3])
{
  double work[3];
  int itau;
  itau = 2;
  work[0] = 0.0;
  work[1] = 0.0;
  work[2] = 0.0;
  for (int i{2}; i >= 0; i--) {
    int b_i;
    int iaii;
    int ix0;
    iaii = i + i * 5;
    if (i + 1 < 3) {
      A[iaii] = 1.0;
      reflapack::b_xzlarf(5 - i, 2 - i, iaii + 1, tau[itau], A, iaii + 6, work);
    }
    ix0 = iaii + 2;
    b_i = (iaii - i) + 5;
    for (int k{ix0}; k <= b_i; k++) {
      A[k - 1] *= -tau[itau];
    }
    A[iaii] = 1.0 - tau[itau];
    for (itau = 0; itau < i; itau++) {
      A[(iaii - itau) - 1] = 0.0;
    }
    itau = i - 1;
  }
}

void xorgqr(double A[18], const double tau[3])
{
  double work[3];
  int itau;
  itau = 2;
  work[0] = 0.0;
  work[1] = 0.0;
  work[2] = 0.0;
  for (int i{2}; i >= 0; i--) {
    int b_i;
    int iaii;
    int ix0;
    iaii = i + i * 6;
    if (i + 1 < 3) {
      A[iaii] = 1.0;
      reflapack::xzlarf(6 - i, 2 - i, iaii + 1, tau[itau], A, iaii + 7, work);
    }
    ix0 = iaii + 2;
    b_i = (iaii - i) + 6;
    for (int k{ix0}; k <= b_i; k++) {
      A[k - 1] *= -tau[itau];
    }
    A[iaii] = 1.0 - tau[itau];
    for (itau = 0; itau < i; itau++) {
      A[(iaii - itau) - 1] = 0.0;
    }
    itau = i - 1;
  }
}

} // namespace lapack
} // namespace internal
} // namespace coder

// End of code generation (xorgqr.cpp)
