//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// peInterface.h
//
// Code generation for function 'peInterface'
//

#ifndef PEINTERFACE_H
#define PEINTERFACE_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void peInterface(const double parameters[6], double dt,
                        const double processNoise[9],
                        const double measurementNoise[4], const double u[2],
                        const double z[2], double outputArg1[3],
                        double outputArg2[3]);

#endif
// End of code generation (peInterface.h)
