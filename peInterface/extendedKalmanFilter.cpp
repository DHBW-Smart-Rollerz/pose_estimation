//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// extendedKalmanFilter.cpp
//
// Code generation for function 'extendedKalmanFilter'
//

// Include files
#include "extendedKalmanFilter.h"
#include "EKFCorrectorAdditive.h"
#include "EKFPredictorAdditive.h"
#include "cholPSD.h"
#include "rt_nonfinite.h"
#include <algorithm>

// Variable Definitions
static const signed char iv[9]{1, 0, 0, 0, 1, 0, 0, 0, 1};

// Function Definitions
namespace coder {
void extendedKalmanFilter::ensureFilterPredictionReadiness()
{
  ensureStateAndStateCovarianceIsDefined();
  ensureProcessNoiseIsDefined();
  if (pIsFirstCallPredict) {
    if (!pIsValidStateTransitionFcn) {
      pIsValidStateTransitionFcn = true;
    }
    pIsFirstCallPredict = false;
  }
}

void extendedKalmanFilter::ensureMeasurementNoiseIsDefined()
{
  if (pSqrtMeasurementNoiseScalar > 0.0) {
    double a;
    a = pSqrtMeasurementNoiseScalar;
    pSqrtMeasurementNoise[0] = a;
    pSqrtMeasurementNoise[1] = a * 0.0;
    pSqrtMeasurementNoise[2] = a * 0.0;
    pSqrtMeasurementNoise[3] = a;
    pSqrtMeasurementNoiseScalar = -1.0;
  }
}

void extendedKalmanFilter::ensureProcessNoiseIsDefined()
{
  if ((!pIsSetProcessNoise) || (pSqrtProcessNoiseScalar != -1.0)) {
    double b_a[9];
    double a;
    a = pSqrtProcessNoiseScalar;
    for (int i{0}; i < 9; i++) {
      b_a[i] = a * static_cast<double>(iv[i]);
    }
    set_pSqrtProcessNoise(b_a);
  }
}

void extendedKalmanFilter::ensureStateAndStateCovarianceIsDefined()
{
  if ((!pIsSetStateCovariance) || (pSqrtStateCovarianceScalar != -1.0)) {
    double b_a[9];
    double a;
    a = pSqrtStateCovarianceScalar;
    for (int i{0}; i < 9; i++) {
      b_a[i] = a * static_cast<double>(iv[i]);
    }
    set_pSqrtStateCovariance(b_a);
  }
}

void extendedKalmanFilter::set_ProcessNoise()
{
  for (int i{0}; i < 9; i++) {
    pSqrtProcessNoise[i] = iv[i];
  }
  pIsSetProcessNoise = true;
  pSqrtProcessNoiseScalar = -1.0;
}

void extendedKalmanFilter::set_StateCovariance()
{
  for (int i{0}; i < 9; i++) {
    pSqrtStateCovariance[i] = iv[i];
  }
  pIsSetStateCovariance = true;
  pSqrtStateCovarianceScalar = -1.0;
}

void extendedKalmanFilter::set_pSqrtStateCovariance(const double b_value[9])
{
  std::copy(&b_value[0], &b_value[9], &pSqrtStateCovariance[0]);
  pIsSetStateCovariance = true;
  pSqrtStateCovarianceScalar = -1.0;
}

void extendedKalmanFilter::validateMeasurementAndRelatedProperties()
{
  ensureStateAndStateCovarianceIsDefined();
  if (pIsFirstCallCorrect) {
    validateMeasurementFcn();
    pIsFirstCallCorrect = false;
  }
  ensureMeasurementNoiseIsDefined();
}

void extendedKalmanFilter::validateMeasurementFcn()
{
  if (!pIsValidMeasurementFcn) {
    pIsValidMeasurementFcn = true;
  }
}

void extendedKalmanFilter::correct(const double z[2])
{
  double dv[9];
  validateMeasurementAndRelatedProperties();
  std::copy(&pSqrtStateCovariance[0], &pSqrtStateCovariance[9], &dv[0]);
  matlabshared::tracking::internal::EKFCorrectorAdditive::correct(
      z, pSqrtMeasurementNoise, pState, dv);
  set_pSqrtStateCovariance(dv);
}

extendedKalmanFilter *extendedKalmanFilter::init()
{
  extendedKalmanFilter *EKF;
  EKF = this;
  EKF->pIsFirstCallPredict = true;
  EKF->pIsFirstCallCorrect = true;
  EKF->pState[0] = 0.0;
  EKF->pState[1] = 0.0;
  EKF->pState[2] = 0.0;
  EKF->pSqrtStateCovarianceScalar = 1.0;
  EKF->set_StateCovariance();
  EKF->pIsValidStateTransitionFcn = false;
  EKF->pIsValidMeasurementFcn = false;
  EKF->pIsValidMeasurementFcn = false;
  EKF->pIsValidStateTransitionFcn = false;
  EKF->pSqrtProcessNoiseScalar = 1.0;
  EKF->set_ProcessNoise();
  EKF->pSqrtMeasurementNoiseScalar = 1.0;
  return EKF;
}

void extendedKalmanFilter::predict(const double varargin_1[2],
                                   const double varargin_2[6],
                                   double varargin_3)
{
  double dv[9];
  double unusedExpr[9];
  ensureFilterPredictionReadiness();
  std::copy(&pSqrtStateCovariance[0], &pSqrtStateCovariance[9], &dv[0]);
  matlabshared::tracking::internal::EKFPredictorAdditive::predict(
      pSqrtProcessNoise, pState, dv, varargin_1, varargin_2, varargin_3,
      unusedExpr);
  set_pSqrtStateCovariance(dv);
}

void extendedKalmanFilter::set_MeasurementNoise(double b_value[4])
{
  double c_value[4];
  for (int i{0}; i < 4; i++) {
    c_value[i] = b_value[i];
  }
  matlabshared::tracking::internal::b_cholPSD(c_value, b_value);
  pSqrtMeasurementNoiseScalar = -1.0;
  ensureMeasurementNoiseIsDefined();
  pSqrtMeasurementNoise[0] = b_value[0];
  pSqrtMeasurementNoise[1] = b_value[1];
  pSqrtMeasurementNoise[2] = b_value[2];
  pSqrtMeasurementNoise[3] = b_value[3];
}

void extendedKalmanFilter::set_pSqrtProcessNoise(const double b_value[9])
{
  std::copy(&b_value[0], &b_value[9], &pSqrtProcessNoise[0]);
  pIsSetProcessNoise = true;
  pSqrtProcessNoiseScalar = -1.0;
}

} // namespace coder

// End of code generation (extendedKalmanFilter.cpp)
