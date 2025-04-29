//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// mtimes.cpp
//
// Code generation for function 'mtimes'
//

// Include files
#include "mtimes.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
void b_mtimes(const double A[9], const double B[6], double C[6])
{
  for (int j{0}; j < 2; j++) {
    double d;
    double d1;
    double d2;
    int coffset;
    coffset = j * 3;
    d = B[j];
    d1 = B[j + 2];
    d2 = B[j + 4];
    for (int i{0}; i < 3; i++) {
      int aoffset;
      aoffset = i * 3;
      C[coffset + i] =
          (A[aoffset] * d + A[aoffset + 1] * d1) + A[aoffset + 2] * d2;
    }
  }
}

void mtimes(const double A[9], const double B[9], double C[9])
{
  for (int j{0}; j < 3; j++) {
    double d;
    double d1;
    double d2;
    int coffset;
    coffset = j * 3;
    d = B[j];
    d1 = B[j + 3];
    d2 = B[j + 6];
    for (int i{0}; i < 3; i++) {
      int aoffset;
      aoffset = i * 3;
      C[coffset + i] =
          (A[aoffset] * d + A[aoffset + 1] * d1) + A[aoffset + 2] * d2;
    }
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (mtimes.cpp)
