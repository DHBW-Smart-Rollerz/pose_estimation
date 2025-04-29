//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// EKFPredictorAdditive.h
//
// Code generation for function 'EKFPredictorAdditive'
//

#ifndef EKFPREDICTORADDITIVE_H
#define EKFPREDICTORADDITIVE_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
class EKFPredictorAdditive {
public:
  static void predict(const double Qs[9], double x[3], double S[9],
                      const double varargin_1[2], const double varargin_2[6],
                      double varargin_3, double dFdx[9]);
};

} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

#endif
// End of code generation (EKFPredictorAdditive.h)
