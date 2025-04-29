//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// qr.h
//
// Code generation for function 'qr'
//

#ifndef QR_H
#define QR_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void b_qr(const double A[10], double Q[10], double R[4]);

void c_qr(const double A[15], double Q[15], double R[9]);

void qr(const double A[18], double Q[18], double R[9]);

} // namespace coder

#endif
// End of code generation (qr.h)
