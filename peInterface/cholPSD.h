//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// cholPSD.h
//
// Code generation for function 'cholPSD'
//

#ifndef CHOLPSD_H
#define CHOLPSD_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
void b_cholPSD(const double A[4], double b_value[4]);

void cholPSD(const double A[9], double b_value[9]);

} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

#endif
// End of code generation (cholPSD.h)
