//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// svd1.cpp
//
// Code generation for function 'svd1'
//

// Include files
#include "svd1.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xrotg.h"
#include "xswap.h"
#include "xzlangeM.h"
#include "xzlascl.h"
#include <cmath>

// Function Definitions
namespace coder {
namespace internal {
void c_svd(const double A[9], double U[9], double s[3], double V[9])
{
  double b_A[9];
  double e[3];
  double work[3];
  double anrm;
  double cscale;
  double nrm;
  double rt;
  double snorm;
  double sqds;
  int ii;
  int kase;
  int m;
  int qjj;
  int qp1;
  int qq;
  int qq_tmp;
  boolean_T doscale;
  s[0] = 0.0;
  e[0] = 0.0;
  work[0] = 0.0;
  s[1] = 0.0;
  e[1] = 0.0;
  work[1] = 0.0;
  s[2] = 0.0;
  e[2] = 0.0;
  work[2] = 0.0;
  for (qjj = 0; qjj < 9; qjj++) {
    b_A[qjj] = A[qjj];
    U[qjj] = 0.0;
    V[qjj] = 0.0;
  }
  doscale = false;
  anrm = reflapack::xzlangeM(A);
  cscale = anrm;
  if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
    doscale = true;
    cscale = 6.7178761075670888E-139;
    reflapack::xzlascl(anrm, cscale, b_A);
  } else if (anrm > 1.4885657073574029E+138) {
    doscale = true;
    cscale = 1.4885657073574029E+138;
    reflapack::xzlascl(anrm, cscale, b_A);
  }
  for (int q{0}; q < 2; q++) {
    boolean_T apply_transform;
    qp1 = q + 2;
    qq_tmp = q + 3 * q;
    qq = qq_tmp + 1;
    apply_transform = false;
    nrm = blas::xnrm2(3 - q, b_A, qq_tmp + 1);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq_tmp] < 0.0) {
        nrm = -nrm;
      }
      s[q] = nrm;
      if (std::abs(nrm) >= 1.0020841800044864E-292) {
        nrm = 1.0 / nrm;
        qjj = (qq_tmp - q) + 3;
        for (int k{qq}; k <= qjj; k++) {
          b_A[k - 1] *= nrm;
        }
      } else {
        qjj = (qq_tmp - q) + 3;
        for (int k{qq}; k <= qjj; k++) {
          b_A[k - 1] /= s[q];
        }
      }
      b_A[qq_tmp]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }
    for (kase = qp1; kase < 4; kase++) {
      qjj = q + 3 * (kase - 1);
      if (apply_transform) {
        blas::xaxpy(
            3 - q,
            -(blas::xdotc(3 - q, b_A, qq_tmp + 1, b_A, qjj + 1) / b_A[qq_tmp]),
            qq_tmp + 1, b_A, qjj + 1);
      }
      e[kase - 1] = b_A[qjj];
    }
    for (ii = q + 1; ii < 4; ii++) {
      kase = (ii + 3 * q) - 1;
      U[kase] = b_A[kase];
    }
    if (q + 1 <= 1) {
      nrm = blas::b_xnrm2(e);
      if (nrm == 0.0) {
        e[0] = 0.0;
      } else {
        if (e[1] < 0.0) {
          e[0] = -nrm;
        } else {
          e[0] = nrm;
        }
        nrm = e[0];
        if (std::abs(e[0]) >= 1.0020841800044864E-292) {
          nrm = 1.0 / e[0];
          for (int k{qp1}; k < 4; k++) {
            e[k - 1] *= nrm;
          }
        } else {
          for (int k{qp1}; k < 4; k++) {
            e[k - 1] /= nrm;
          }
        }
        e[1]++;
        e[0] = -e[0];
        for (ii = qp1; ii < 4; ii++) {
          work[ii - 1] = 0.0;
        }
        for (kase = qp1; kase < 4; kase++) {
          blas::xaxpy(e[kase - 1], b_A, 3 * (kase - 1) + 2, work);
        }
        for (kase = qp1; kase < 4; kase++) {
          blas::xaxpy(-e[kase - 1] / e[1], work, b_A, 3 * (kase - 1) + 2);
        }
      }
      for (ii = qp1; ii < 4; ii++) {
        V[ii - 1] = e[ii - 1];
      }
    }
  }
  m = 1;
  s[2] = b_A[8];
  e[1] = b_A[7];
  e[2] = 0.0;
  U[6] = 0.0;
  U[7] = 0.0;
  U[8] = 1.0;
  for (int q{1}; q >= 0; q--) {
    qp1 = q + 2;
    qq = q + 3 * q;
    if (s[q] != 0.0) {
      for (kase = qp1; kase < 4; kase++) {
        qjj = (q + 3 * (kase - 1)) + 1;
        blas::xaxpy(3 - q, -(blas::xdotc(3 - q, U, qq + 1, U, qjj) / U[qq]),
                    qq + 1, U, qjj);
      }
      for (ii = q + 1; ii < 4; ii++) {
        kase = (ii + 3 * q) - 1;
        U[kase] = -U[kase];
      }
      U[qq]++;
      if (q - 1 >= 0) {
        U[3 * q] = 0.0;
      }
    } else {
      U[3 * q] = 0.0;
      U[3 * q + 1] = 0.0;
      U[3 * q + 2] = 0.0;
      U[qq] = 1.0;
    }
  }
  for (int q{2}; q >= 0; q--) {
    if ((q + 1 <= 1) && (e[0] != 0.0)) {
      blas::xaxpy(2, -(blas::xdotc(2, V, 2, V, 5) / V[1]), 2, V, 5);
      blas::xaxpy(2, -(blas::xdotc(2, V, 2, V, 8) / V[1]), 2, V, 8);
    }
    V[3 * q] = 0.0;
    V[3 * q + 1] = 0.0;
    V[3 * q + 2] = 0.0;
    V[q + 3 * q] = 1.0;
  }
  qq = 0;
  snorm = 0.0;
  for (int q{0}; q < 3; q++) {
    nrm = s[q];
    if (nrm != 0.0) {
      rt = std::abs(nrm);
      nrm /= rt;
      s[q] = rt;
      if (q + 1 < 3) {
        e[q] /= nrm;
      }
      kase = 3 * q;
      qjj = kase + 3;
      for (int k{kase + 1}; k <= qjj; k++) {
        U[k - 1] *= nrm;
      }
    }
    if (q + 1 < 3) {
      nrm = e[q];
      if (nrm != 0.0) {
        rt = std::abs(nrm);
        nrm = rt / nrm;
        e[q] = rt;
        s[q + 1] *= nrm;
        kase = 3 * (q + 1);
        qjj = kase + 3;
        for (int k{kase + 1}; k <= qjj; k++) {
          V[k - 1] *= nrm;
        }
      }
    }
    snorm = std::fmax(snorm, std::fmax(std::abs(s[q]), std::abs(e[q])));
  }
  while ((m + 2 > 0) && (qq < 75)) {
    boolean_T exitg1;
    qq_tmp = m + 1;
    ii = m + 1;
    exitg1 = false;
    while (!(exitg1 || (ii == 0))) {
      nrm = std::abs(e[ii - 1]);
      if ((nrm <=
           2.2204460492503131E-16 * (std::abs(s[ii - 1]) + std::abs(s[ii]))) ||
          (nrm <= 1.0020841800044864E-292) ||
          ((qq > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
        e[ii - 1] = 0.0;
        exitg1 = true;
      } else {
        ii--;
      }
    }
    if (ii == m + 1) {
      kase = 4;
    } else {
      qjj = m + 2;
      kase = m + 2;
      exitg1 = false;
      while ((!exitg1) && (kase >= ii)) {
        qjj = kase;
        if (kase == ii) {
          exitg1 = true;
        } else {
          nrm = 0.0;
          if (kase < m + 2) {
            nrm = std::abs(e[kase - 1]);
          }
          if (kase > ii + 1) {
            nrm += std::abs(e[kase - 2]);
          }
          rt = std::abs(s[kase - 1]);
          if ((rt <= 2.2204460492503131E-16 * nrm) ||
              (rt <= 1.0020841800044864E-292)) {
            s[kase - 1] = 0.0;
            exitg1 = true;
          } else {
            kase--;
          }
        }
      }
      if (qjj == ii) {
        kase = 3;
      } else if (qjj == m + 2) {
        kase = 1;
      } else {
        kase = 2;
        ii = qjj;
      }
    }
    switch (kase) {
    case 1: {
      rt = e[m];
      e[m] = 0.0;
      for (int k{qq_tmp}; k >= ii + 1; k--) {
        double sm;
        sm = blas::xrotg(s[k - 1], rt, sqds);
        if (k > ii + 1) {
          rt = -sqds * e[0];
          e[0] *= sm;
        }
        blas::xrot(V, 3 * (k - 1) + 1, 3 * (m + 1) + 1, sm, sqds);
      }
    } break;
    case 2: {
      rt = e[ii - 1];
      e[ii - 1] = 0.0;
      for (int k{ii + 1}; k <= m + 2; k++) {
        double b;
        double sm;
        sm = blas::xrotg(s[k - 1], rt, sqds);
        b = e[k - 1];
        rt = -sqds * b;
        e[k - 1] = b * sm;
        blas::xrot(U, 3 * (k - 1) + 1, 3 * (ii - 1) + 1, sm, sqds);
      }
    } break;
    case 3: {
      double b;
      double scale;
      double sm;
      nrm = s[m + 1];
      scale = std::fmax(
          std::fmax(std::fmax(std::fmax(std::abs(nrm), std::abs(s[m])),
                              std::abs(e[m])),
                    std::abs(s[ii])),
          std::abs(e[ii]));
      sm = nrm / scale;
      nrm = s[m] / scale;
      rt = e[m] / scale;
      sqds = s[ii] / scale;
      b = ((nrm + sm) * (nrm - sm) + rt * rt) / 2.0;
      nrm = sm * rt;
      nrm *= nrm;
      if ((b != 0.0) || (nrm != 0.0)) {
        rt = std::sqrt(b * b + nrm);
        if (b < 0.0) {
          rt = -rt;
        }
        rt = nrm / (b + rt);
      } else {
        rt = 0.0;
      }
      rt += (sqds + sm) * (sqds - sm);
      nrm = sqds * (e[ii] / scale);
      for (int k{ii + 1}; k <= qq_tmp; k++) {
        sm = blas::xrotg(rt, nrm, sqds);
        if (k > ii + 1) {
          e[0] = rt;
        }
        nrm = e[k - 1];
        b = s[k - 1];
        e[k - 1] = sm * nrm - sqds * b;
        rt = sqds * s[k];
        s[k] *= sm;
        qjj = 3 * (k - 1) + 1;
        kase = 3 * k + 1;
        blas::xrot(V, qjj, kase, sm, sqds);
        s[k - 1] = sm * b + sqds * nrm;
        sm = blas::xrotg(s[k - 1], rt, sqds);
        b = e[k - 1];
        rt = sm * b + sqds * s[k];
        s[k] = -sqds * b + sm * s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        blas::xrot(U, qjj, kase, sm, sqds);
      }
      e[m] = rt;
      qq++;
    } break;
    default:
      if (s[ii] < 0.0) {
        s[ii] = -s[ii];
        kase = 3 * ii;
        qjj = kase + 3;
        for (int k{kase + 1}; k <= qjj; k++) {
          V[k - 1] = -V[k - 1];
        }
      }
      qp1 = ii + 1;
      while ((ii + 1 < 3) && (s[ii] < s[qp1])) {
        rt = s[ii];
        s[ii] = s[qp1];
        s[qp1] = rt;
        qjj = 3 * ii + 1;
        kase = 3 * (ii + 1) + 1;
        blas::xswap(V, qjj, kase);
        blas::xswap(U, qjj, kase);
        ii = qp1;
        qp1++;
      }
      qq = 0;
      m--;
      break;
    }
  }
  if (doscale) {
    reflapack::c_xzlascl(cscale, anrm, s);
  }
}

void d_svd(const double A[4], double U[4], double s[2], double V[4])
{
  double e[2];
  double anrm;
  double b;
  double cscale;
  double f;
  double nrm;
  double rt;
  double sm;
  double snorm;
  int iter;
  int kase;
  int m;
  int q;
  int qs;
  boolean_T doscale;
  U[0] = A[0];
  U[1] = A[1];
  U[2] = A[2];
  U[3] = A[3];
  doscale = false;
  anrm = reflapack::b_xzlangeM(A);
  cscale = anrm;
  if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
    doscale = true;
    cscale = 6.7178761075670888E-139;
    reflapack::b_xzlascl(anrm, cscale, U);
  } else if (anrm > 1.4885657073574029E+138) {
    doscale = true;
    cscale = 1.4885657073574029E+138;
    reflapack::b_xzlascl(anrm, cscale, U);
  }
  nrm = blas::xnrm2(U);
  if (nrm > 0.0) {
    if (U[0] < 0.0) {
      s[0] = -nrm;
    } else {
      s[0] = nrm;
    }
    if (std::abs(s[0]) >= 1.0020841800044864E-292) {
      nrm = 1.0 / s[0];
      U[0] *= nrm;
      U[1] *= nrm;
    } else {
      U[0] /= s[0];
      U[1] /= s[0];
    }
    U[0]++;
    s[0] = -s[0];
    blas::xaxpy(-(blas::xdotc(U, U) / U[0]), U);
  } else {
    s[0] = 0.0;
  }
  m = 2;
  s[1] = U[3];
  e[0] = U[2];
  e[1] = 0.0;
  U[2] = 0.0;
  U[3] = 1.0;
  if (s[0] != 0.0) {
    blas::xaxpy(-(blas::xdotc(U, U) / U[0]), U);
    U[0] = -U[0];
    U[1] = -U[1];
    U[0]++;
  } else {
    U[1] = 0.0;
    U[0] = 1.0;
  }
  V[2] = 0.0;
  V[3] = 1.0;
  V[1] = 0.0;
  V[0] = 1.0;
  for (q = 0; q < 2; q++) {
    b = s[q];
    if (b != 0.0) {
      rt = std::abs(b);
      nrm = b / rt;
      s[q] = rt;
      if (q + 1 < 2) {
        e[0] /= nrm;
      }
      kase = q << 1;
      qs = kase + 2;
      for (int k{kase + 1}; k <= qs; k++) {
        U[k - 1] *= nrm;
      }
    }
    if ((q + 1 < 2) && (e[0] != 0.0)) {
      rt = std::abs(e[0]);
      nrm = rt / e[0];
      e[0] = rt;
      s[1] *= nrm;
      V[2] *= nrm;
      V[3] *= nrm;
    }
  }
  iter = 0;
  snorm = std::fmax(std::fmax(0.0, std::fmax(std::abs(s[0]), std::abs(e[0]))),
                    std::fmax(std::abs(s[1]), 0.0));
  while ((m > 0) && (iter < 75)) {
    int ii_tmp_tmp;
    boolean_T exitg1;
    ii_tmp_tmp = m - 1;
    q = m - 1;
    exitg1 = false;
    while (!(exitg1 || (q == 0))) {
      nrm = std::abs(e[0]);
      if ((nrm <= 2.2204460492503131E-16 * (std::abs(s[0]) + std::abs(s[1]))) ||
          (nrm <= 1.0020841800044864E-292) ||
          ((iter > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
        e[0] = 0.0;
        exitg1 = true;
      } else {
        q = 0;
      }
    }
    if (q == m - 1) {
      kase = 4;
    } else {
      qs = m;
      kase = m;
      exitg1 = false;
      while ((!exitg1) && (kase >= q)) {
        qs = kase;
        if (kase == q) {
          exitg1 = true;
        } else {
          nrm = 0.0;
          if (kase < m) {
            nrm = std::abs(e[0]);
          }
          if (kase > q + 1) {
            nrm += std::abs(e[0]);
          }
          rt = std::abs(s[kase - 1]);
          if ((rt <= 2.2204460492503131E-16 * nrm) ||
              (rt <= 1.0020841800044864E-292)) {
            s[kase - 1] = 0.0;
            exitg1 = true;
          } else {
            kase--;
          }
        }
      }
      if (qs == q) {
        kase = 3;
      } else if (qs == m) {
        kase = 1;
      } else {
        kase = 2;
        q = qs;
      }
    }
    switch (kase) {
    case 1:
      f = e[0];
      e[0] = 0.0;
      for (int k{ii_tmp_tmp}; k >= q + 1; k--) {
        rt = blas::xrotg(s[0], f, sm);
        blas::b_xrot(V, 1, ((m - 1) << 1) + 1, rt, sm);
      }
      break;
    case 2:
      f = e[q - 1];
      e[q - 1] = 0.0;
      for (int k{q + 1}; k <= m; k++) {
        rt = blas::xrotg(s[k - 1], f, sm);
        nrm = e[k - 1];
        f = -sm * nrm;
        e[k - 1] = nrm * rt;
        blas::b_xrot(U, ((k - 1) << 1) + 1, ((q - 1) << 1) + 1, rt, sm);
      }
      break;
    case 3: {
      double scale;
      double sqds;
      nrm = s[m - 1];
      scale = std::fmax(
          std::fmax(std::fmax(std::fmax(std::abs(nrm), std::abs(s[0])),
                              std::abs(e[0])),
                    std::abs(s[q])),
          std::abs(e[q]));
      sm = nrm / scale;
      nrm = s[0] / scale;
      rt = e[0] / scale;
      sqds = s[q] / scale;
      b = ((nrm + sm) * (nrm - sm) + rt * rt) / 2.0;
      nrm = sm * rt;
      nrm *= nrm;
      if ((b != 0.0) || (nrm != 0.0)) {
        rt = std::sqrt(b * b + nrm);
        if (b < 0.0) {
          rt = -rt;
        }
        rt = nrm / (b + rt);
      } else {
        rt = 0.0;
      }
      f = (sqds + sm) * (sqds - sm) + rt;
      nrm = sqds * (e[q] / scale);
      for (int k{q + 1}; k < 2; k++) {
        rt = blas::xrotg(f, nrm, sm);
        f = rt * s[0] + sm * e[0];
        b = rt * e[0] - sm * s[0];
        e[0] = b;
        nrm = sm * s[1];
        s[1] *= rt;
        blas::b_xrot(V, 1, 3, rt, sm);
        s[0] = f;
        rt = blas::xrotg(s[0], nrm, sm);
        f = rt * b + sm * s[1];
        s[1] = -sm * b + rt * s[1];
        nrm = sm * e[1];
        e[1] *= rt;
        blas::b_xrot(U, 1, 3, rt, sm);
      }
      e[0] = f;
      iter++;
    } break;
    default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        kase = q << 1;
        qs = kase + 2;
        for (int k{kase + 1}; k <= qs; k++) {
          V[k - 1] = -V[k - 1];
        }
      }
      while ((q + 1 < 2) && (s[0] < s[1])) {
        rt = s[0];
        s[0] = s[1];
        s[1] = rt;
        blas::xswap(V);
        blas::xswap(U);
        q = 1;
      }
      iter = 0;
      m--;
      break;
    }
  }
  if (doscale) {
    reflapack::d_xzlascl(cscale, anrm, s);
  }
}

} // namespace internal
} // namespace coder

// End of code generation (svd1.cpp)
