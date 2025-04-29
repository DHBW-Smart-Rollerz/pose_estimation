//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// peInterface.cpp
//
// Code generation for function 'peInterface'
//

// Include files
#include "peInterface.h"
#include "PoseEstimator.h"
#include "rt_nonfinite.h"

// Function Definitions
void peInterface(const double parameters[6], double dt,
                 const double processNoise[9], const double measurementNoise[4],
                 const double u[2], const double z[2], double outputArg1[3],
                 double outputArg2[3])
{
  PoseEstimator poseEstimator;
  poseEstimator.init(parameters, dt, processNoise, measurementNoise);
  poseEstimator.predict(u);
  poseEstimator.correct(z);
  poseEstimator.getState(outputArg1);
  poseEstimator.getPose(outputArg2);
}

// End of code generation (peInterface.cpp)
