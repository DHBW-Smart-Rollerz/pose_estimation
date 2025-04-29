//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xgeqrf.cpp
//
// Code generation for function 'xgeqrf'
//

// Include files
#include "xgeqrf.h"
#include "rt_nonfinite.h"
#include "xzlarf.h"
#include "xzlarfg.h"

// Function Definitions
namespace coder {
namespace internal {
namespace lapack {
void b_xgeqrf(double A[10], double tau[2])
{
  double work[2];
  double atmp;
  work[0] = 0.0;
  work[1] = 0.0;
  atmp = A[0];
  tau[0] = reflapack::b_xzlarfg(5, atmp, A, 2);
  A[0] = atmp;
  A[0] = 1.0;
  reflapack::xzlarf(tau[0], A, work);
  A[0] = atmp;
  atmp = A[6];
  tau[1] = reflapack::b_xzlarfg(4, atmp, A, 8);
  A[6] = atmp;
}

void c_xgeqrf(double A[15], double tau[3])
{
  double work[3];
  double atmp;
  double d;
  work[0] = 0.0;
  work[1] = 0.0;
  work[2] = 0.0;
  atmp = A[0];
  d = reflapack::c_xzlarfg(5, atmp, A, 2);
  tau[0] = d;
  A[0] = atmp;
  A[0] = 1.0;
  reflapack::b_xzlarf(5, 2, 1, d, A, 6, work);
  A[0] = atmp;
  atmp = A[6];
  d = reflapack::c_xzlarfg(4, atmp, A, 8);
  tau[1] = d;
  A[6] = atmp;
  A[6] = 1.0;
  reflapack::b_xzlarf(4, 1, 7, d, A, 12, work);
  A[6] = atmp;
  atmp = A[12];
  d = reflapack::c_xzlarfg(3, atmp, A, 14);
  tau[2] = d;
  A[12] = atmp;
}

void xgeqrf(double A[18], double tau[3])
{
  double work[3];
  double atmp;
  double d;
  work[0] = 0.0;
  work[1] = 0.0;
  work[2] = 0.0;
  atmp = A[0];
  d = reflapack::xzlarfg(6, atmp, A, 2);
  tau[0] = d;
  A[0] = atmp;
  A[0] = 1.0;
  reflapack::xzlarf(6, 2, 1, d, A, 7, work);
  A[0] = atmp;
  atmp = A[7];
  d = reflapack::xzlarfg(5, atmp, A, 9);
  tau[1] = d;
  A[7] = atmp;
  A[7] = 1.0;
  reflapack::xzlarf(5, 1, 8, d, A, 14, work);
  A[7] = atmp;
  atmp = A[14];
  d = reflapack::xzlarfg(4, atmp, A, 16);
  tau[2] = d;
  A[14] = atmp;
}

} // namespace lapack
} // namespace internal
} // namespace coder

// End of code generation (xgeqrf.cpp)
