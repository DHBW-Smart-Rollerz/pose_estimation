//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// extendedKalmanFilter.h
//
// Code generation for function 'extendedKalmanFilter'
//

#ifndef EXTENDEDKALMANFILTER_H
#define EXTENDEDKALMANFILTER_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
class extendedKalmanFilter {
public:
  extendedKalmanFilter *init();
  void set_StateCovariance();
  void set_ProcessNoise();
  void set_pSqrtProcessNoise(const double b_value[9]);
  void set_MeasurementNoise(double b_value[4]);
  void ensureMeasurementNoiseIsDefined();
  void predict(const double varargin_1[2], const double varargin_2[6],
               double varargin_3);
  void correct(const double z[2]);

protected:
  void set_pSqrtStateCovariance(const double b_value[9]);
  void ensureFilterPredictionReadiness();
  void ensureStateAndStateCovarianceIsDefined();
  void ensureProcessNoiseIsDefined();
  void validateMeasurementAndRelatedProperties();
  void validateMeasurementFcn();

public:
  double pState[3];

protected:
  double pSqrtStateCovariance[9];
  double pSqrtStateCovarianceScalar;
  boolean_T pIsSetStateCovariance;
  double pSqrtProcessNoise[9];
  double pSqrtProcessNoiseScalar;
  boolean_T pIsSetProcessNoise;
  double pSqrtMeasurementNoise[4];
  double pSqrtMeasurementNoiseScalar;
  boolean_T pIsValidStateTransitionFcn;
  boolean_T pIsValidMeasurementFcn;
  boolean_T pIsFirstCallPredict;
  boolean_T pIsFirstCallCorrect;
};

} // namespace coder

#endif
// End of code generation (extendedKalmanFilter.h)
