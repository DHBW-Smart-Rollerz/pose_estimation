//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// chol.cpp
//
// Code generation for function 'chol'
//

// Include files
#include "chol.h"
#include "rt_nonfinite.h"
#include "xpotrf.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace internal {
int b_chol(double A[4], int &jmax)
{
  int flag;
  flag = lapack::b_xpotrf(A);
  if (flag == 0) {
    jmax = 2;
  } else {
    jmax = flag - 1;
  }
  if (jmax - 2 >= 0) {
    for (int i{2}; i <= jmax; i++) {
      A[1] = 0.0;
    }
  }
  return flag;
}

void b_chol(double A[4])
{
  int jmax;
  jmax = lapack::b_xpotrf(A);
  if (jmax == 0) {
    jmax = 2;
  } else {
    jmax--;
  }
  if (jmax - 2 >= 0) {
    for (int i{2}; i <= jmax; i++) {
      A[1] = 0.0;
    }
  }
}

int chol(double A[9], int &jmax)
{
  int flag;
  flag = lapack::xpotrf(A);
  if (flag == 0) {
    jmax = 3;
  } else {
    jmax = flag - 1;
  }
  for (int j{0}; j <= jmax - 2; j++) {
    int i;
    i = j + 2;
    if (i <= jmax) {
      std::memset(&A[(j * 3 + i) + -1], 0,
                  static_cast<unsigned int>((jmax - i) + 1) * sizeof(double));
    }
  }
  return flag;
}

void chol(double A[9])
{
  int i;
  int jmax;
  jmax = lapack::xpotrf(A);
  if (jmax == 0) {
    jmax = 3;
  } else {
    jmax--;
  }
  i = jmax - 2;
  for (int j{0}; j <= i; j++) {
    int i1;
    i1 = j + 2;
    if (i1 <= jmax) {
      std::memset(&A[(j * 3 + i1) + -1], 0,
                  static_cast<unsigned int>((jmax - i1) + 1) * sizeof(double));
    }
  }
}

} // namespace internal
} // namespace coder

// End of code generation (chol.cpp)
