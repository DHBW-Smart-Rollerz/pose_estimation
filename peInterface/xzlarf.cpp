//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xzlarf.cpp
//
// Code generation for function 'xzlarf'
//

// Include files
#include "xzlarf.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "xgerc.h"

// Function Declarations
namespace coder {
namespace internal {
namespace reflapack {
static int b_ilazlc(int m, int n, const double A[15], int ia0);

static int ilazlc(int m, int n, const double A[18], int ia0);

static int ilazlc(int m, const double A[10], int ia0);

} // namespace reflapack
} // namespace internal
} // namespace coder

// Function Definitions
namespace coder {
namespace internal {
namespace reflapack {
static int b_ilazlc(int m, int n, const double A[15], int ia0)
{
  int j;
  boolean_T exitg2;
  j = n;
  exitg2 = false;
  while ((!exitg2) && (j > 0)) {
    int coltop;
    int exitg1;
    int ia;
    coltop = ia0 + (j - 1) * 5;
    ia = coltop;
    do {
      exitg1 = 0;
      if (ia <= (coltop + m) - 1) {
        if (A[ia - 1] != 0.0) {
          exitg1 = 1;
        } else {
          ia++;
        }
      } else {
        j--;
        exitg1 = 2;
      }
    } while (exitg1 == 0);
    if (exitg1 == 1) {
      exitg2 = true;
    }
  }
  return j;
}

static int ilazlc(int m, int n, const double A[18], int ia0)
{
  int j;
  boolean_T exitg2;
  j = n;
  exitg2 = false;
  while ((!exitg2) && (j > 0)) {
    int coltop;
    int exitg1;
    int ia;
    coltop = ia0 + (j - 1) * 6;
    ia = coltop;
    do {
      exitg1 = 0;
      if (ia <= (coltop + m) - 1) {
        if (A[ia - 1] != 0.0) {
          exitg1 = 1;
        } else {
          ia++;
        }
      } else {
        j--;
        exitg1 = 2;
      }
    } while (exitg1 == 0);
    if (exitg1 == 1) {
      exitg2 = true;
    }
  }
  return j;
}

static int ilazlc(int m, const double A[10], int ia0)
{
  int ia;
  int j;
  j = 1;
  ia = ia0;
  int exitg1;
  do {
    exitg1 = 0;
    if (ia <= (ia0 + m) - 1) {
      if (A[ia - 1] != 0.0) {
        exitg1 = 1;
      } else {
        ia++;
      }
    } else {
      j = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return j;
}

void b_xzlarf(int m, int n, int iv0, double tau, double C[15], int ic0,
              double work[3])
{
  int lastc;
  int lastv;
  if (tau != 0.0) {
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && (C[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }
    lastc = b_ilazlc(lastv, n, C, ic0);
  } else {
    lastv = 0;
    lastc = 0;
  }
  if (lastv > 0) {
    blas::c_xgemv(lastv, lastc, C, ic0, C, iv0, work);
    blas::c_xgerc(lastv, lastc, -tau, iv0, work, C, ic0);
  }
}

void xzlarf(int m, int n, int iv0, double tau, double C[18], int ic0,
            double work[3])
{
  int lastc;
  int lastv;
  if (tau != 0.0) {
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && (C[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }
    lastc = ilazlc(lastv, n, C, ic0);
  } else {
    lastv = 0;
    lastc = 0;
  }
  if (lastv > 0) {
    blas::xgemv(lastv, lastc, C, ic0, C, iv0, work);
    blas::xgerc(lastv, lastc, -tau, iv0, work, C, ic0);
  }
}

void xzlarf(double tau, double C[10], double work[2])
{
  int lastc;
  int lastv;
  if (tau != 0.0) {
    lastv = 5;
    lastc = 6;
    while ((lastv > 0) && (C[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }
    lastc = ilazlc(lastv, C, 6);
  } else {
    lastv = 0;
    lastc = 0;
  }
  if (lastv > 0) {
    blas::b_xgemv(lastv, lastc, C, 6, C, 1, work);
    blas::b_xgerc(lastv, lastc, -tau, 1, work, C, 6);
  }
}

void xzlarf(int iv0, double tau, double C[10], int ic0, double work[2])
{
  int lastc;
  int lastv;
  if (tau != 0.0) {
    lastv = 5;
    lastc = iv0 + 3;
    while ((lastv > 0) && (C[lastc] == 0.0)) {
      lastv--;
      lastc--;
    }
    lastc = ilazlc(lastv, C, ic0);
  } else {
    lastv = 0;
    lastc = 0;
  }
  if (lastv > 0) {
    blas::b_xgemv(lastv, lastc, C, ic0, C, iv0, work);
    blas::b_xgerc(lastv, lastc, -tau, iv0, work, C, ic0);
  }
}

} // namespace reflapack
} // namespace internal
} // namespace coder

// End of code generation (xzlarf.cpp)
