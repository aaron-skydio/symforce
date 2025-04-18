// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     function/FUNCTION.cu.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

namespace sym {

__host__ __device__ void BackendTestFunctionFloat64(
    const double x, const double y, double* const __restrict__ res0,
    double* const __restrict__ res1, double* const __restrict__ res2,
    double* const __restrict__ res3, double* const __restrict__ res4,
    double* const __restrict__ res5, double* const __restrict__ res6,
    double* const __restrict__ res7, double* const __restrict__ res8,
    double* const __restrict__ res9, double* const __restrict__ res10,
    double* const __restrict__ res11, double* const __restrict__ res12,
    double* const __restrict__ res13, double* const __restrict__ res14,
    double* const __restrict__ res15, double* const __restrict__ res16,
    double* const __restrict__ res17, double* const __restrict__ res18,
    double* const __restrict__ res19, double* const __restrict__ res20,
    double* const __restrict__ res21, double* const __restrict__ res22,
    double* const __restrict__ res23, double* const __restrict__ res24,
    double* const __restrict__ res25, double* const __restrict__ res26,
    double* const __restrict__ res27, double* const __restrict__ res28,
    double* const __restrict__ res29, double* const __restrict__ res30,
    double* const __restrict__ res31, double* const __restrict__ res32,
    double* const __restrict__ res33, double* const __restrict__ res34,
    double* const __restrict__ res35, double* const __restrict__ res36,
    double* const __restrict__ res37, double* const __restrict__ res38,
    double* const __restrict__ res39, double* const __restrict__ res40,
    double* const __restrict__ res41, double* const __restrict__ res42,
    double* const __restrict__ res43, double* const __restrict__ res44,
    double* const __restrict__ res45, double* const __restrict__ res46,
    double* const __restrict__ res47, double* const __restrict__ res48,
    double* const __restrict__ res49, double* const __restrict__ res50,
    double* const __restrict__ res51, double* const __restrict__ res52,
    double* const __restrict__ res53, double* const __restrict__ res54,
    double* const __restrict__ res55, double* const __restrict__ res56,
    double* const __restrict__ res57, double* const __restrict__ res58,
    double* const __restrict__ res59) {
  // Total ops: 62

  // Intermediate terms (5)
  const double _tmp0 = M_LN2;
  const double _tmp1 = M_1_PI;
  const double _tmp2 = M_SQRT2;
  const double _tmp3 = sqrt(x);
  const double _tmp4 = x + y;

  // Output terms (60)
  if (res0 != nullptr) {
    *res0 = 0;
  }

  if (res1 != nullptr) {
    *res1 = 1;
  }

  if (res2 != nullptr) {
    *res2 = 1.0 / 2.0;
  }

  if (res3 != nullptr) {
    *res3 = 1.6000000000000001;
  }

  if (res4 != nullptr) {
    *res4 = 11.0 / 52.0;
  }

  if (res5 != nullptr) {
    *res5 = M_E;
  }

  if (res6 != nullptr) {
    *res6 = 1.0 / _tmp0;
  }

  if (res7 != nullptr) {
    *res7 = _tmp0;
  }

  if (res8 != nullptr) {
    *res8 = M_LN10;
  }

  if (res9 != nullptr) {
    *res9 = M_PI;
  }

  if (res10 != nullptr) {
    *res10 = M_PI_2;
  }

  if (res11 != nullptr) {
    *res11 = M_PI_4;
  }

  if (res12 != nullptr) {
    *res12 = _tmp1;
  }

  if (res13 != nullptr) {
    *res13 = 2 * _tmp1;
  }

  if (res14 != nullptr) {
    *res14 = M_2_SQRTPI;
  }

  if (res15 != nullptr) {
    *res15 = _tmp2;
  }

  if (res16 != nullptr) {
    *res16 = (1.0 / 2.0) * _tmp2;
  }

  if (res17 != nullptr) {
    *res17 = fabs(x);
  }

  if (res18 != nullptr) {
    *res18 = sin(x);
  }

  if (res19 != nullptr) {
    *res19 = cos(x);
  }

  if (res20 != nullptr) {
    *res20 = tan(x);
  }

  if (res21 != nullptr) {
    *res21 = asin(x);
  }

  if (res22 != nullptr) {
    *res22 = acos(x);
  }

  if (res23 != nullptr) {
    *res23 = atan(x);
  }

  if (res24 != nullptr) {
    *res24 = exp(x);
  }

  if (res25 != nullptr) {
    *res25 = log(x);
  }

  if (res26 != nullptr) {
    *res26 = sinh(x);
  }

  if (res27 != nullptr) {
    *res27 = cosh(x);
  }

  if (res28 != nullptr) {
    *res28 = tanh(x);
  }

  if (res29 != nullptr) {
    *res29 = floor(x);
  }

  if (res30 != nullptr) {
    *res30 = ceil(x);
  }

  if (res31 != nullptr) {
    *res31 = _tmp3;
  }

  if (res32 != nullptr) {
    *res32 = asinh(x);
  }

  if (res33 != nullptr) {
    *res33 = acosh(x);
  }

  if (res34 != nullptr) {
    *res34 = atanh(x);
  }

  if (res35 != nullptr) {
    *res35 = x - 5.5 * floor(0.18181818181818199 * x);
  }

  if (res36 != nullptr) {
    *res36 = x + 1;
  }

  if (res37 != nullptr) {
    *res37 = 2 * x;
  }

  if (res38 != nullptr) {
    *res38 = pow(x, 2);
  }

  if (res39 != nullptr) {
    *res39 = pow(x, 3);
  }

  if (res40 != nullptr) {
    *res40 = pow(x, 4);
  }

  if (res41 != nullptr) {
    *res41 = pow(x, 5);
  }

  if (res42 != nullptr) {
    *res42 = _tmp3;
  }

  if (res43 != nullptr) {
    *res43 = pow(x, 3.0 / 2.0);
  }

  if (res44 != nullptr) {
    *res44 = (1.0 / 2.0) * (((x) > 0) - ((x) < 0)) + 1.0 / 2.0;
  }

  if (res45 != nullptr) {
    *res45 = copysign(1.0, x);
  }

  if (res46 != nullptr) {
    *res46 = erfc(x);
  }

  if (res47 != nullptr) {
    *res47 = lgamma(x);
  }

  if (res48 != nullptr) {
    *res48 = erf(x);
  }

  if (res49 != nullptr) {
    *res49 = tgamma(x);
  }

  if (res50 != nullptr) {
    *res50 = atan2(x, y);
  }

  if (res51 != nullptr) {
    *res51 = fmax(x, y);
  }

  if (res52 != nullptr) {
    *res52 = fmin(x, y);
  }

  if (res53 != nullptr) {
    *res53 = x - y * floor(x / y);
  }

  if (res54 != nullptr) {
    *res54 = _tmp4;
  }

  if (res55 != nullptr) {
    *res55 = x * y;
  }

  if (res56 != nullptr) {
    *res56 = pow(x, y);
  }

  if (res57 != nullptr) {
    *res57 = pow(_tmp4, 2);
  }

  if (res58 != nullptr) {
    *res58 = pow(_tmp4, 3);
  }

  if (res59 != nullptr) {
    *res59 = copysign(x, y);
  }
}

}  // namespace sym
