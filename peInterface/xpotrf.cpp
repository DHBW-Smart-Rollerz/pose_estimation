//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xpotrf.cpp
//
// Code generation for function 'xpotrf'
//

// Include files
#include "xpotrf.h"
#include "rt_nonfinite.h"
#include "xdotc.h"
#include "xgemv.h"
#include <cmath>

// Function Definitions
namespace coder {
namespace internal {
namespace lapack {
int b_xpotrf(double A[4])
{
  int info;
  int j;
  boolean_T exitg1;
  info = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 2)) {
    double ajj;
    int idxA1j;
    int idxAjj;
    idxA1j = (j << 1) + 1;
    idxAjj = (idxA1j + j) - 1;
    ajj = A[idxAjj] - blas::b_xdotc(j, A, idxA1j, A, idxA1j);
    if (ajj > 0.0) {
      ajj = std::sqrt(ajj);
      A[idxAjj] = ajj;
      if (j + 1 < 2) {
        idxA1j = idxAjj + 3;
        ajj = 1.0 / ajj;
        for (idxAjj = idxA1j; idxAjj <= idxA1j; idxAjj += 2) {
          A[idxAjj - 1] *= ajj;
        }
      }
      j++;
    } else {
      A[idxAjj] = ajj;
      info = j + 1;
      exitg1 = true;
    }
  }
  return info;
}

int xpotrf(double A[9])
{
  int info;
  int j;
  boolean_T exitg1;
  info = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 3)) {
    double ajj;
    int idxA1j;
    int idxAjj;
    idxA1j = j * 3 + 1;
    idxAjj = (idxA1j + j) - 1;
    ajj = A[idxAjj] - blas::xdotc(j, A, idxA1j, A, idxA1j);
    if (ajj > 0.0) {
      ajj = std::sqrt(ajj);
      A[idxAjj] = ajj;
      if (j + 1 < 3) {
        int idxAjjp1;
        idxAjjp1 = idxAjj + 4;
        blas::xgemv(j, 2 - j, idxA1j + 3, idxA1j, A, idxAjj + 4);
        ajj = 1.0 / ajj;
        idxA1j = (idxAjj + 3 * (1 - j)) + 4;
        for (idxAjj = idxAjjp1; idxAjj <= idxA1j; idxAjj += 3) {
          A[idxAjj - 1] *= ajj;
        }
      }
      j++;
    } else {
      A[idxAjj] = ajj;
      info = j + 1;
      exitg1 = true;
    }
  }
  return info;
}

} // namespace lapack
} // namespace internal
} // namespace coder

// End of code generation (xpotrf.cpp)
