//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// EKFCorrectorAdditive.cpp
//
// Code generation for function 'EKFCorrectorAdditive'
//

// Include files
#include "EKFCorrectorAdditive.h"
#include "linsolve.h"
#include "mtimes.h"
#include "qr.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
void EKFCorrectorAdditive::correctStateAndSqrtCovariance(
    double x[3], double S[9], const double residue[2], const double Pxy[6],
    const double Sy[4], const double H[6], const double Rsqrt[4])
{
  double dv1[15];
  double A[9];
  double dv[9];
  double K[6];
  double b_Pxy[6];
  double d;
  double d1;
  int Pxy_tmp;
  int i1;
  for (int i{0}; i < 3; i++) {
    Pxy_tmp = i << 1;
    b_Pxy[Pxy_tmp] = Pxy[i];
    b_Pxy[Pxy_tmp + 1] = Pxy[i + 3];
  }
  double b_Sy[4];
  b_Sy[0] = Sy[0];
  b_Sy[1] = Sy[2];
  b_Sy[2] = Sy[1];
  b_Sy[3] = Sy[3];
  linsolve(Sy, b_Pxy, K);
  b_linsolve(b_Sy, K, b_Pxy);
  for (int i{0}; i < 2; i++) {
    K[3 * i] = b_Pxy[i];
    K[3 * i + 1] = b_Pxy[i + 2];
    K[3 * i + 2] = b_Pxy[i + 4];
  }
  d = residue[0];
  d1 = residue[1];
  for (int i{0}; i < 3; i++) {
    x[i] += K[i] * d + K[i + 3] * d1;
  }
  for (int i{0}; i < 6; i++) {
    b_Pxy[i] = -K[i];
  }
  for (int i{0}; i < 3; i++) {
    d = b_Pxy[i];
    d1 = b_Pxy[i + 3];
    for (Pxy_tmp = 0; Pxy_tmp < 3; Pxy_tmp++) {
      i1 = Pxy_tmp << 1;
      A[i + 3 * Pxy_tmp] = d * H[i1] + d1 * H[i1 + 1];
    }
  }
  A[0]++;
  A[4]++;
  A[8]++;
  ::coder::internal::blas::mtimes(S, A, dv);
  for (int i{0}; i < 2; i++) {
    Pxy_tmp = i << 1;
    for (i1 = 0; i1 < 3; i1++) {
      b_Pxy[i + (i1 << 1)] =
          K[i1] * Rsqrt[Pxy_tmp] + K[i1 + 3] * Rsqrt[Pxy_tmp + 1];
    }
  }
  for (int i{0}; i < 3; i++) {
    dv1[5 * i] = dv[3 * i];
    dv1[5 * i + 1] = dv[3 * i + 1];
    dv1[5 * i + 2] = dv[3 * i + 2];
    Pxy_tmp = i << 1;
    dv1[5 * i + 3] = b_Pxy[Pxy_tmp];
    dv1[5 * i + 4] = b_Pxy[Pxy_tmp + 1];
  }
  double a__1[15];
  c_qr(dv1, a__1, A);
  for (int i{0}; i < 3; i++) {
    S[3 * i] = A[i];
    S[3 * i + 1] = A[i + 3];
    S[3 * i + 2] = A[i + 6];
  }
}

void EKFCorrectorAdditive::correct(const double z[2], const double Rs[4],
                                   double x[3], double S[9])
{
  static const double b[6]{0.0, 1.0, 0.0, 0.0, 1.0, 0.0};
  static const signed char b_iv[6]{0, 0, 1, 1, 0, 0};
  double dv1[10];
  double b_S[9];
  double dv[6];
  double R[4];
  double b_x[2];
  ::coder::internal::blas::b_mtimes(S, b, dv);
  for (int i{0}; i < 2; i++) {
    dv1[5 * i] = dv[3 * i];
    dv1[5 * i + 1] = dv[3 * i + 1];
    dv1[5 * i + 2] = dv[3 * i + 2];
    dv1[5 * i + 3] = Rs[i];
    dv1[5 * i + 4] = Rs[i + 2];
  }
  double a__1[10];
  b_qr(dv1, a__1, R);
  b_x[0] = x[2];
  b_x[1] = x[0];
  b_x[0] = z[0] - b_x[0];
  b_x[1] = z[1] - b_x[1];
  for (int i{0}; i < 3; i++) {
    double d;
    double d1;
    double d2;
    for (int i1{0}; i1 < 3; i1++) {
      b_S[i + 3 * i1] =
          (S[i] * S[i1] + S[i + 3] * S[i1 + 3]) + S[i + 6] * S[i1 + 6];
    }
    d = b_S[i];
    d1 = b_S[i + 3];
    d2 = b_S[i + 6];
    for (int i1{0}; i1 < 2; i1++) {
      dv[i + 3 * i1] = (d * static_cast<double>(b_iv[3 * i1]) +
                        d1 * static_cast<double>(b_iv[3 * i1 + 1])) +
                       d2 * static_cast<double>(b_iv[3 * i1 + 2]);
    }
  }
  double b_R[4];
  b_R[0] = R[0];
  b_R[1] = R[2];
  b_R[2] = R[1];
  b_R[3] = R[3];
  EKFCorrectorAdditive::correctStateAndSqrtCovariance(x, S, b_x, dv, b_R, b,
                                                      Rs);
}

} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

// End of code generation (EKFCorrectorAdditive.cpp)
