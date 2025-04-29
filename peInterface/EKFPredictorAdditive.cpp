//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// EKFPredictorAdditive.cpp
//
// Code generation for function 'EKFPredictorAdditive'
//

// Include files
#include "EKFPredictorAdditive.h"
#include "PoseEstimator.h"
#include "mtimes.h"
#include "qr.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
void EKFPredictorAdditive::predict(const double Qs[9], double x[3], double S[9],
                                   const double varargin_1[2],
                                   const double varargin_2[6],
                                   double varargin_3, double dFdx[9])
{
  double dv[18];
  double R[9];
  double b_x;
  double c_x;
  double d;
  double d1;
  double d_x;
  PoseEstimator::PoseEstimator_anonFcn2(x, varargin_1, varargin_2, varargin_3,
                                        dFdx);
  b_x = x[0];
  c_x = x[0];
  d_x = x[1];
  x[0] += varargin_3 * varargin_1[1];
  b_x *= varargin_2[5];
  d = varargin_2[0] * varargin_2[2];
  d1 = varargin_3 * (d - varargin_2[1] * varargin_2[3]);
  x[1] = (((b_x * x[1] + d1 * x[2]) -
           varargin_3 * varargin_2[0] * varargin_1[0] * c_x) -
          varargin_3 * varargin_2[5] * (c_x * c_x) * x[2]) /
         (b_x - varargin_3 * (varargin_2[0] + varargin_2[1]));
  b_x = c_x * varargin_2[4];
  x[2] = ((b_x * x[2] + d1 * d_x) - varargin_3 * (d * varargin_1[0] * c_x)) /
         (b_x - varargin_3 * (varargin_2[2] * varargin_2[2] * varargin_2[0] +
                              varargin_2[3] * varargin_2[3] * varargin_2[1]));
  ::coder::internal::blas::mtimes(S, dFdx, R);
  for (int i{0}; i < 3; i++) {
    dv[6 * i] = R[3 * i];
    dv[6 * i + 3] = Qs[i];
    dv[6 * i + 1] = R[3 * i + 1];
    dv[6 * i + 4] = Qs[i + 3];
    dv[6 * i + 2] = R[3 * i + 2];
    dv[6 * i + 5] = Qs[i + 6];
  }
  double a__1[18];
  qr(dv, a__1, R);
  for (int i{0}; i < 3; i++) {
    S[3 * i] = R[i];
    S[3 * i + 1] = R[i + 3];
    S[3 * i + 2] = R[i + 6];
  }
}

} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

// End of code generation (EKFPredictorAdditive.cpp)
