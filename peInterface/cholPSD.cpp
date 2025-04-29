//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// cholPSD.cpp
//
// Code generation for function 'cholPSD'
//

// Include files
#include "cholPSD.h"
#include "chol.h"
#include "rt_nonfinite.h"
#include "svdPSD.h"
#include <algorithm>

// Function Definitions
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
void b_cholPSD(const double A[4], double b_value[4])
{
  double b_A[4];
  int info;
  int n;
  b_A[0] = A[0];
  b_A[1] = A[1];
  b_A[2] = A[2];
  b_A[3] = A[3];
  info = ::coder::internal::b_chol(b_A, n);
  if (info == 0) {
    b_A[0] = A[0];
    b_A[1] = A[1];
    b_A[2] = A[2];
    b_A[3] = A[3];
    ::coder::internal::b_chol(b_A);
    b_value[0] = b_A[0];
    b_value[1] = b_A[2];
    b_value[2] = b_A[1];
    b_value[3] = b_A[3];
  } else {
    b_svdPSD(A, b_value);
  }
}

void cholPSD(const double A[9], double b_value[9])
{
  double b_A[9];
  int info;
  int n;
  std::copy(&A[0], &A[9], &b_A[0]);
  info = ::coder::internal::chol(b_A, n);
  if (info == 0) {
    std::copy(&A[0], &A[9], &b_A[0]);
    ::coder::internal::chol(b_A);
    for (info = 0; info < 3; info++) {
      b_value[3 * info] = b_A[info];
      b_value[3 * info + 1] = b_A[info + 3];
      b_value[3 * info + 2] = b_A[info + 6];
    }
  } else {
    svdPSD(A, b_value);
  }
}

} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

// End of code generation (cholPSD.cpp)
