//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// EKFCorrectorAdditive.h
//
// Code generation for function 'EKFCorrectorAdditive'
//

#ifndef EKFCORRECTORADDITIVE_H
#define EKFCORRECTORADDITIVE_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
class EKFCorrectorAdditive {
public:
  static void correct(const double z[2], const double Rs[4], double x[3],
                      double S[9]);
  static void correctStateAndSqrtCovariance(
      double x[3], double S[9], const double residue[2], const double Pxy[6],
      const double Sy[4], const double H[6], const double Rsqrt[4]);
};

} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

#endif
// End of code generation (EKFCorrectorAdditive.h)
