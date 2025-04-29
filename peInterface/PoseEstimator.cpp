//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// PoseEstimator.cpp
//
// Code generation for function 'PoseEstimator'
//

// Include files
#include "PoseEstimator.h"
#include "cholPSD.h"
#include "extendedKalmanFilter.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
void PoseEstimator::PoseEstimator_anonFcn2(const double x[3], const double u[2],
                                           const double b_parameters[6],
                                           double b_dt, double varargout_1[9])
{
  double b_varargout_1_tmp;
  double c_varargout_1_tmp;
  double denom_b1;
  double denom_b1_tmp;
  double denom_b2;
  double denom_b2_tmp;
  double varargout_1_tmp;
  denom_b1_tmp = x[0] * b_parameters[5];
  denom_b1 = denom_b1_tmp - b_dt * (b_parameters[0] + b_parameters[1]);
  denom_b2_tmp = x[0] * b_parameters[4];
  denom_b2 = denom_b2_tmp -
             b_dt * (b_parameters[2] * b_parameters[2] * b_parameters[0] +
                     b_parameters[3] * b_parameters[3] * b_parameters[1]);
  varargout_1[0] = 1.0;
  varargout_1[3] = 0.0;
  varargout_1[6] = 0.0;
  varargout_1_tmp = b_dt * b_parameters[0] * u[0];
  b_varargout_1_tmp = b_dt * (b_parameters[0] * b_parameters[2] -
                              b_parameters[1] * b_parameters[3]);
  c_varargout_1_tmp = b_dt * b_parameters[5] * (x[0] * x[0]);
  varargout_1[1] =
      (((x[1] * b_parameters[5] - varargout_1_tmp) -
        2.0 * b_dt * b_parameters[5] * x[0] * x[2]) *
           denom_b1 -
       b_parameters[5] * (((denom_b1_tmp * x[1] + b_varargout_1_tmp * x[2]) -
                           varargout_1_tmp * x[0]) -
                          c_varargout_1_tmp * x[2])) /
      (denom_b1 * denom_b1);
  varargout_1[4] = denom_b1_tmp / denom_b1;
  varargout_1[7] = (b_varargout_1_tmp - c_varargout_1_tmp) / denom_b1;
  varargout_1_tmp = b_dt * b_parameters[2] * b_parameters[0] * u[0];
  varargout_1[2] =
      ((x[2] * b_parameters[4] - varargout_1_tmp) * denom_b2 -
       b_parameters[4] * ((denom_b2_tmp * x[2] + b_varargout_1_tmp * x[1]) -
                          varargout_1_tmp * x[0])) /
      (denom_b2 * denom_b2);
  varargout_1[5] = b_varargout_1_tmp / denom_b2;
  varargout_1[8] = denom_b2_tmp / denom_b2;
}

void PoseEstimator::correct(const double z[2])
{
  double X_tmp;
  double b_X_tmp;
  double psi;
  ekf.correct(z);
  psi = pose[2];
  X_tmp = std::sin(psi);
  b_X_tmp = std::cos(psi);
  psi += dt * ekf.pState[2];
  pose[0] += dt * (ekf.pState[0] * b_X_tmp - ekf.pState[1] * X_tmp);
  pose[1] += dt * (ekf.pState[0] * X_tmp + ekf.pState[1] * b_X_tmp);
  pose[2] = psi;
}

void PoseEstimator::getPose(double p[3]) const
{
  p[0] = pose[0];
  p[1] = pose[1];
  p[2] = pose[2];
}

void PoseEstimator::getState(double x[3]) const
{
  x[0] = ekf.pState[0];
  x[1] = ekf.pState[1];
  x[2] = ekf.pState[2];
}

PoseEstimator *PoseEstimator::init(const double b_parameters[6], double b_dt,
                                   const double processNoise[9],
                                   const double measurementNoise[4])
{
  PoseEstimator *obj;
  obj = this;
  for (int i{0}; i < 6; i++) {
    obj->parameters[i] = b_parameters[i];
  }
  double dv[9];
  double b_measurementNoise[4];
  obj->dt = b_dt;
  //  Initialzustand
  //  vx, vy, psidot
  obj->pose[0] = 0.0;
  obj->pose[1] = 0.0;
  obj->pose[2] = 0.0;
  //  X, Y, psi
  //  EKF Setup
  obj->ekf.init();
  coder::matlabshared::tracking::internal::cholPSD(processNoise, dv);
  obj->ekf.set_pSqrtProcessNoise(dv);
  b_measurementNoise[0] = measurementNoise[0];
  b_measurementNoise[1] = measurementNoise[1];
  b_measurementNoise[2] = measurementNoise[2];
  b_measurementNoise[3] = measurementNoise[3];
  obj->ekf.set_MeasurementNoise(b_measurementNoise);
  return obj;
}

void PoseEstimator::predict(const double u[2])
{
  ekf.predict(u, parameters, dt);
}

// End of code generation (PoseEstimator.cpp)
