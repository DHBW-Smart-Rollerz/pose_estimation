//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// PoseEstimator.h
//
// Code generation for function 'PoseEstimator'
//

#ifndef POSEESTIMATOR_H
#define POSEESTIMATOR_H

// Include files
#include "extendedKalmanFilter.h"
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
class PoseEstimator {
public:
  PoseEstimator *init(const double b_parameters[6], double b_dt,
                      const double processNoise[9],
                      const double measurementNoise[4]);
  void predict(const double u[2]);
  static void PoseEstimator_anonFcn2(const double x[3], const double u[2],
                                     const double b_parameters[6], double b_dt,
                                     double varargout_1[9]);
  void correct(const double z[2]);
  void getState(double x[3]) const;
  void getPose(double p[3]) const;

private:
  coder::extendedKalmanFilter ekf;
  double parameters[6];
  double dt;
  double pose[3];
};

#endif
// End of code generation (PoseEstimator.h)
