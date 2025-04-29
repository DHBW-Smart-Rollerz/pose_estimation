//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// svdPSD.h
//
// Code generation for function 'svdPSD'
//

#ifndef SVDPSD_H
#define SVDPSD_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
void b_svdPSD(const double A[4], double R[4]);

void svdPSD(const double A[9], double R[9]);

} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

#endif
// End of code generation (svdPSD.h)
