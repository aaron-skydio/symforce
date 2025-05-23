// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Core>

#include <sym/rot3.h>

namespace sym {

/**
 * Residual that penalizes the difference between between(a, b) and a_T_b.
 *
 * In vector space terms that would be:
 *     (b - a) - a_T_b
 *
 * In lie group terms:
 *     local_coordinates(a_T_b, between(a, b))
 *     to_tangent(compose(inverse(a_T_b), compose(inverse(a), b)))
 *
 * Args:
 *     sqrt_info: Square root information matrix to whiten residual. This can be computed from
 *                a covariance matrix as the cholesky decomposition of the inverse. In the case
 *                of a diagonal it will contain 1/sigma values. Must match the tangent dim.
 *     jacobian: (3x6) jacobian of res wrt args a (3), b (3)
 *     hessian: (6x6) Gauss-Newton hessian for args a (3), b (3)
 *     rhs: (6x1) Gauss-Newton rhs for args a (3), b (3)
 */
template <typename Scalar>
void BetweenFactorRot3(const sym::Rot3<Scalar>& a, const sym::Rot3<Scalar>& b,
                       const sym::Rot3<Scalar>& a_T_b, const Eigen::Matrix<Scalar, 3, 3>& sqrt_info,
                       const Scalar epsilon, Eigen::Matrix<Scalar, 3, 1>* const res = nullptr,
                       Eigen::Matrix<Scalar, 3, 6>* const jacobian = nullptr,
                       Eigen::Matrix<Scalar, 6, 6>* const hessian = nullptr,
                       Eigen::Matrix<Scalar, 6, 1>* const rhs = nullptr) {
  // Total ops: 736

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _b = b.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _a_T_b = a_T_b.Data();

  // Intermediate terms (201)
  const Scalar _tmp0 = _a[3] * _b[3];
  const Scalar _tmp1 = _a[2] * _b[2];
  const Scalar _tmp2 = _a[0] * _b[0];
  const Scalar _tmp3 = _a[1] * _b[1];
  const Scalar _tmp4 = _tmp0 + _tmp1 + _tmp2 + _tmp3;
  const Scalar _tmp5 = _a[3] * _b[1];
  const Scalar _tmp6 = _a[2] * _b[0];
  const Scalar _tmp7 = _a[0] * _b[2];
  const Scalar _tmp8 = _a[1] * _b[3];
  const Scalar _tmp9 = _tmp5 - _tmp6 + _tmp7 - _tmp8;
  const Scalar _tmp10 = _a[3] * _b[0];
  const Scalar _tmp11 = _a[2] * _b[1];
  const Scalar _tmp12 = _a[0] * _b[3];
  const Scalar _tmp13 = _a[1] * _b[2];
  const Scalar _tmp14 = _tmp10 + _tmp11 - _tmp12 - _tmp13;
  const Scalar _tmp15 = _a[3] * _b[2];
  const Scalar _tmp16 = _a[2] * _b[3];
  const Scalar _tmp17 = _a[0] * _b[1];
  const Scalar _tmp18 = _a[1] * _b[0];
  const Scalar _tmp19 = _tmp15 - _tmp16 - _tmp17 + _tmp18;
  const Scalar _tmp20 =
      -_a_T_b[0] * _tmp9 + _a_T_b[1] * _tmp14 - _a_T_b[2] * _tmp4 + _a_T_b[3] * _tmp19;
  const Scalar _tmp21 = _a_T_b[3] * _tmp4;
  const Scalar _tmp22 = _a_T_b[1] * _tmp9;
  const Scalar _tmp23 = _a_T_b[0] * _tmp14;
  const Scalar _tmp24 = _a_T_b[2] * _tmp19;
  const Scalar _tmp25 = _tmp21 + _tmp22 + _tmp23 + _tmp24;
  const Scalar _tmp26 = std::copysign(Scalar(1.0), _tmp25);
  const Scalar _tmp27 = 2 * _tmp26;
  const Scalar _tmp28 = 1 - epsilon;
  const Scalar _tmp29 = std::min<Scalar>(_tmp28, std::fabs(_tmp25));
  const Scalar _tmp30 = std::acos(_tmp29) / std::sqrt(Scalar(1 - std::pow(_tmp29, Scalar(2))));
  const Scalar _tmp31 = _tmp27 * _tmp30;
  const Scalar _tmp32 = _tmp20 * _tmp31;
  const Scalar _tmp33 =
      -_a_T_b[0] * _tmp4 - _a_T_b[1] * _tmp19 + _a_T_b[2] * _tmp9 + _a_T_b[3] * _tmp14;
  const Scalar _tmp34 = _tmp31 * _tmp33;
  const Scalar _tmp35 = _tmp27 * sqrt_info(0, 1);
  const Scalar _tmp36 =
      _a_T_b[0] * _tmp19 - _a_T_b[1] * _tmp4 - _a_T_b[2] * _tmp14 + _a_T_b[3] * _tmp9;
  const Scalar _tmp37 = _tmp30 * _tmp36;
  const Scalar _tmp38 = _tmp32 * sqrt_info(0, 2) + _tmp34 * sqrt_info(0, 0) + _tmp35 * _tmp37;
  const Scalar _tmp39 = _tmp27 * sqrt_info(1, 1);
  const Scalar _tmp40 = _tmp32 * sqrt_info(1, 2) + _tmp34 * sqrt_info(1, 0) + _tmp37 * _tmp39;
  const Scalar _tmp41 = _tmp20 * sqrt_info(2, 2);
  const Scalar _tmp42 = _tmp36 * sqrt_info(2, 1);
  const Scalar _tmp43 = _tmp31 * _tmp41 + _tmp31 * _tmp42 + _tmp34 * sqrt_info(2, 0);
  const Scalar _tmp44 = _tmp20 * sqrt_info(0, 2);
  const Scalar _tmp45 = (Scalar(1) / Scalar(2)) * _tmp10;
  const Scalar _tmp46 = (Scalar(1) / Scalar(2)) * _tmp11;
  const Scalar _tmp47 = (Scalar(1) / Scalar(2)) * _tmp12;
  const Scalar _tmp48 = (Scalar(1) / Scalar(2)) * _tmp13;
  const Scalar _tmp49 = _tmp45 + _tmp46 - _tmp47 - _tmp48;
  const Scalar _tmp50 = _a_T_b[3] * _tmp49;
  const Scalar _tmp51 = (Scalar(1) / Scalar(2)) * _tmp0;
  const Scalar _tmp52 = (Scalar(1) / Scalar(2)) * _tmp1;
  const Scalar _tmp53 = (Scalar(1) / Scalar(2)) * _tmp2;
  const Scalar _tmp54 = (Scalar(1) / Scalar(2)) * _tmp3;
  const Scalar _tmp55 = -_tmp51 - _tmp52 - _tmp53 - _tmp54;
  const Scalar _tmp56 = _a_T_b[0] * _tmp55;
  const Scalar _tmp57 = (Scalar(1) / Scalar(2)) * _tmp5;
  const Scalar _tmp58 = (Scalar(1) / Scalar(2)) * _tmp6;
  const Scalar _tmp59 = (Scalar(1) / Scalar(2)) * _tmp7;
  const Scalar _tmp60 = (Scalar(1) / Scalar(2)) * _tmp8;
  const Scalar _tmp61 = -_tmp57 + _tmp58 - _tmp59 + _tmp60;
  const Scalar _tmp62 = _a_T_b[2] * _tmp61;
  const Scalar _tmp63 = (Scalar(1) / Scalar(2)) * _tmp15;
  const Scalar _tmp64 = (Scalar(1) / Scalar(2)) * _tmp16;
  const Scalar _tmp65 = (Scalar(1) / Scalar(2)) * _tmp17;
  const Scalar _tmp66 = (Scalar(1) / Scalar(2)) * _tmp18;
  const Scalar _tmp67 = _tmp63 - _tmp64 - _tmp65 + _tmp66;
  const Scalar _tmp68 = _a_T_b[1] * _tmp67;
  const Scalar _tmp69 = _tmp62 + _tmp68;
  const Scalar _tmp70 = _tmp50 + _tmp56 + _tmp69;
  const Scalar _tmp71 = _tmp21 + _tmp22 + _tmp23 + _tmp24;
  const Scalar _tmp72 = std::fabs(_tmp71);
  const Scalar _tmp73 = std::min<Scalar>(_tmp28, _tmp72);
  const Scalar _tmp74 = std::acos(_tmp73);
  const Scalar _tmp75 = 1 - std::pow(_tmp73, Scalar(2));
  const Scalar _tmp76 = _tmp26 * ((((_tmp28 - _tmp72) > 0) - ((_tmp28 - _tmp72) < 0)) + 1) *
                        (((_tmp71) > 0) - ((_tmp71) < 0));
  const Scalar _tmp77 = _tmp73 * _tmp74 * _tmp76 / (_tmp75 * std::sqrt(_tmp75));
  const Scalar _tmp78 = _tmp70 * _tmp77;
  const Scalar _tmp79 = _a_T_b[3] * _tmp55;
  const Scalar _tmp80 = _a_T_b[0] * _tmp49;
  const Scalar _tmp81 = -_a_T_b[1] * _tmp61;
  const Scalar _tmp82 = _a_T_b[2] * _tmp67;
  const Scalar _tmp83 = _tmp81 + _tmp82;
  const Scalar _tmp84 = _tmp79 - _tmp80 + _tmp83;
  const Scalar _tmp85 = _tmp74 / std::sqrt(_tmp75);
  const Scalar _tmp86 = _tmp27 * _tmp85;
  const Scalar _tmp87 = _tmp84 * _tmp86;
  const Scalar _tmp88 = _tmp76 / _tmp75;
  const Scalar _tmp89 = _tmp70 * _tmp88;
  const Scalar _tmp90 = _tmp36 * _tmp89;
  const Scalar _tmp91 = -_a_T_b[1] * _tmp49;
  const Scalar _tmp92 = _a_T_b[2] * _tmp55;
  const Scalar _tmp93 = _a_T_b[0] * _tmp61;
  const Scalar _tmp94 = _a_T_b[3] * _tmp67;
  const Scalar _tmp95 = _tmp93 + _tmp94;
  const Scalar _tmp96 = _tmp91 - _tmp92 + _tmp95;
  const Scalar _tmp97 = _tmp85 * _tmp96;
  const Scalar _tmp98 = _tmp33 * sqrt_info(0, 0);
  const Scalar _tmp99 = _a_T_b[1] * _tmp55;
  const Scalar _tmp100 = _a_T_b[3] * _tmp61;
  const Scalar _tmp101 = -_a_T_b[0] * _tmp67;
  const Scalar _tmp102 = _a_T_b[2] * _tmp49;
  const Scalar _tmp103 = _tmp100 + _tmp101 - _tmp102 + _tmp99;
  const Scalar _tmp104 = _tmp86 * sqrt_info(0, 2);
  const Scalar _tmp105 = _tmp36 * sqrt_info(0, 1);
  const Scalar _tmp106 = _tmp105 * _tmp77;
  const Scalar _tmp107 = _tmp103 * _tmp104 + _tmp106 * _tmp70 + _tmp35 * _tmp97 + _tmp44 * _tmp78 -
                         _tmp44 * _tmp89 + _tmp78 * _tmp98 + _tmp87 * sqrt_info(0, 0) -
                         _tmp89 * _tmp98 - _tmp90 * sqrt_info(0, 1);
  const Scalar _tmp108 = _tmp86 * sqrt_info(1, 0);
  const Scalar _tmp109 = _tmp33 * sqrt_info(1, 0);
  const Scalar _tmp110 = _tmp20 * sqrt_info(1, 2);
  const Scalar _tmp111 = _tmp36 * sqrt_info(1, 1);
  const Scalar _tmp112 = _tmp103 * _tmp86;
  const Scalar _tmp113 = _tmp108 * _tmp84 + _tmp109 * _tmp78 - _tmp109 * _tmp89 + _tmp110 * _tmp78 -
                         _tmp110 * _tmp89 + _tmp111 * _tmp78 + _tmp112 * sqrt_info(1, 2) +
                         _tmp39 * _tmp97 - _tmp90 * sqrt_info(1, 1);
  const Scalar _tmp114 = _tmp33 * sqrt_info(2, 0);
  const Scalar _tmp115 = _tmp86 * sqrt_info(2, 1);
  const Scalar _tmp116 = _tmp112 * sqrt_info(2, 2) + _tmp114 * _tmp78 - _tmp114 * _tmp89 +
                         _tmp115 * _tmp96 + _tmp41 * _tmp78 - _tmp41 * _tmp89 + _tmp42 * _tmp78 -
                         _tmp42 * _tmp89 + _tmp87 * sqrt_info(2, 0);
  const Scalar _tmp117 = _tmp57 - _tmp58 + _tmp59 - _tmp60;
  const Scalar _tmp118 = _a_T_b[3] * _tmp117;
  const Scalar _tmp119 = -_tmp63 + _tmp64 + _tmp65 - _tmp66;
  const Scalar _tmp120 = _a_T_b[0] * _tmp119;
  const Scalar _tmp121 = _tmp102 + _tmp120;
  const Scalar _tmp122 = _tmp118 + _tmp121 + _tmp99;
  const Scalar _tmp123 = _tmp122 * _tmp77;
  const Scalar _tmp124 = _tmp122 * _tmp88;
  const Scalar _tmp125 = -_a_T_b[2] * _tmp117;
  const Scalar _tmp126 = _a_T_b[1] * _tmp119;
  const Scalar _tmp127 = _tmp126 + _tmp50;
  const Scalar _tmp128 = _tmp86 * (_tmp125 + _tmp127 - _tmp56);
  const Scalar _tmp129 = _a_T_b[0] * _tmp117;
  const Scalar _tmp130 = _a_T_b[3] * _tmp119;
  const Scalar _tmp131 = _tmp86 * (-_tmp129 + _tmp130 + _tmp91 + _tmp92);
  const Scalar _tmp132 = _a_T_b[1] * _tmp117;
  const Scalar _tmp133 = -_a_T_b[2] * _tmp119;
  const Scalar _tmp134 = -_tmp132 + _tmp133 + _tmp79 + _tmp80;
  const Scalar _tmp135 = _tmp134 * _tmp85;
  const Scalar _tmp136 = _tmp105 * _tmp123 - _tmp105 * _tmp124 + _tmp123 * _tmp44 +
                         _tmp123 * _tmp98 - _tmp124 * _tmp44 - _tmp124 * _tmp98 +
                         _tmp128 * sqrt_info(0, 2) + _tmp131 * sqrt_info(0, 0) + _tmp135 * _tmp35;
  const Scalar _tmp137 = _tmp109 * _tmp123 - _tmp109 * _tmp124 + _tmp110 * _tmp123 -
                         _tmp110 * _tmp124 + _tmp111 * _tmp123 - _tmp111 * _tmp124 +
                         _tmp128 * sqrt_info(1, 2) + _tmp131 * sqrt_info(1, 0) + _tmp135 * _tmp39;
  const Scalar _tmp138 = _tmp114 * _tmp123 - _tmp114 * _tmp124 + _tmp115 * _tmp134 +
                         _tmp123 * _tmp41 + _tmp123 * _tmp42 - _tmp124 * _tmp41 - _tmp124 * _tmp42 +
                         _tmp128 * sqrt_info(2, 2) + _tmp131 * sqrt_info(2, 0);
  const Scalar _tmp139 = -_tmp45 - _tmp46 + _tmp47 + _tmp48;
  const Scalar _tmp140 = _a_T_b[1] * _tmp139;
  const Scalar _tmp141 = _tmp129 + _tmp140;
  const Scalar _tmp142 = _tmp141 + _tmp92 + _tmp94;
  const Scalar _tmp143 = _tmp142 * _tmp88;
  const Scalar _tmp144 = -_a_T_b[0] * _tmp139;
  const Scalar _tmp145 = _tmp132 + _tmp144;
  const Scalar _tmp146 = _tmp145 + _tmp79 - _tmp82;
  const Scalar _tmp147 = _a_T_b[3] * _tmp139;
  const Scalar _tmp148 = _tmp125 + _tmp147 + _tmp56 - _tmp68;
  const Scalar _tmp149 = _tmp148 * _tmp85;
  const Scalar _tmp150 = _a_T_b[2] * _tmp139;
  const Scalar _tmp151 = _tmp118 + _tmp150;
  const Scalar _tmp152 = _tmp86 * (_tmp101 + _tmp151 - _tmp99);
  const Scalar _tmp153 = _tmp142 * _tmp77;
  const Scalar _tmp154 = _tmp143 * _tmp33;
  const Scalar _tmp155 = _tmp104 * _tmp146 - _tmp105 * _tmp143 + _tmp106 * _tmp142 -
                         _tmp143 * _tmp44 + _tmp149 * _tmp35 + _tmp152 * sqrt_info(0, 0) +
                         _tmp153 * _tmp44 + _tmp153 * _tmp98 - _tmp154 * sqrt_info(0, 0);
  const Scalar _tmp156 = _tmp86 * sqrt_info(1, 2);
  const Scalar _tmp157 = _tmp109 * _tmp153 - _tmp110 * _tmp143 + _tmp110 * _tmp153 -
                         _tmp111 * _tmp143 + _tmp111 * _tmp153 + _tmp146 * _tmp156 +
                         _tmp149 * _tmp39 + _tmp152 * sqrt_info(1, 0) - _tmp154 * sqrt_info(1, 0);
  const Scalar _tmp158 = _tmp86 * sqrt_info(2, 2);
  const Scalar _tmp159 = _tmp114 * _tmp153 + _tmp115 * _tmp148 - _tmp143 * _tmp41 -
                         _tmp143 * _tmp42 + _tmp146 * _tmp158 + _tmp152 * sqrt_info(2, 0) +
                         _tmp153 * _tmp41 + _tmp153 * _tmp42 - _tmp154 * sqrt_info(2, 0);
  const Scalar _tmp160 = _tmp51 + _tmp52 + _tmp53 + _tmp54;
  const Scalar _tmp161 = _a_T_b[0] * _tmp160;
  const Scalar _tmp162 = _tmp147 + _tmp161;
  const Scalar _tmp163 = _tmp162 + _tmp69;
  const Scalar _tmp164 = _tmp163 * _tmp88;
  const Scalar _tmp165 = _a_T_b[2] * _tmp160;
  const Scalar _tmp166 = -_tmp140 - _tmp165 + _tmp95;
  const Scalar _tmp167 = _tmp166 * _tmp85;
  const Scalar _tmp168 = _a_T_b[1] * _tmp160;
  const Scalar _tmp169 = _tmp100 + _tmp168;
  const Scalar _tmp170 = _tmp86 * (_tmp101 - _tmp150 + _tmp169);
  const Scalar _tmp171 = _tmp163 * _tmp77;
  const Scalar _tmp172 = _a_T_b[3] * _tmp160;
  const Scalar _tmp173 = _tmp144 + _tmp172 + _tmp83;
  const Scalar _tmp174 = _tmp173 * _tmp86;
  const Scalar _tmp175 = -_tmp105 * _tmp164 + _tmp106 * _tmp163 - _tmp164 * _tmp44 -
                         _tmp164 * _tmp98 + _tmp167 * _tmp35 + _tmp170 * sqrt_info(0, 2) +
                         _tmp171 * _tmp44 + _tmp171 * _tmp98 + _tmp174 * sqrt_info(0, 0);
  const Scalar _tmp176 = _tmp108 * _tmp173 - _tmp109 * _tmp164 + _tmp109 * _tmp171 -
                         _tmp110 * _tmp164 + _tmp110 * _tmp171 - _tmp111 * _tmp164 +
                         _tmp111 * _tmp171 + _tmp167 * _tmp39 + _tmp170 * sqrt_info(1, 2);
  const Scalar _tmp177 = -_tmp114 * _tmp164 + _tmp114 * _tmp171 + _tmp115 * _tmp166 -
                         _tmp164 * _tmp41 - _tmp164 * _tmp42 + _tmp170 * sqrt_info(2, 2) +
                         _tmp171 * _tmp41 + _tmp171 * _tmp42 + _tmp174 * sqrt_info(2, 0);
  const Scalar _tmp178 = _tmp121 + _tmp169;
  const Scalar _tmp179 = _tmp178 * _tmp88;
  const Scalar _tmp180 = _tmp133 + _tmp172;
  const Scalar _tmp181 = _tmp180 + _tmp80 + _tmp81;
  const Scalar _tmp182 = _tmp181 * _tmp85;
  const Scalar _tmp183 = _tmp127 - _tmp161 - _tmp62;
  const Scalar _tmp184 = _tmp130 + _tmp165;
  const Scalar _tmp185 = _tmp86 * (_tmp184 + _tmp91 - _tmp93);
  const Scalar _tmp186 = _tmp178 * _tmp77;
  const Scalar _tmp187 = _tmp104 * _tmp183 - _tmp105 * _tmp179 + _tmp106 * _tmp178 -
                         _tmp179 * _tmp44 - _tmp179 * _tmp98 + _tmp182 * _tmp35 +
                         _tmp185 * sqrt_info(0, 0) + _tmp186 * _tmp44 + _tmp186 * _tmp98;
  const Scalar _tmp188 = -_tmp109 * _tmp179 + _tmp109 * _tmp186 - _tmp110 * _tmp179 +
                         _tmp110 * _tmp186 - _tmp111 * _tmp179 + _tmp111 * _tmp186 +
                         _tmp156 * _tmp183 + _tmp182 * _tmp39 + _tmp185 * sqrt_info(1, 0);
  const Scalar _tmp189 = -_tmp114 * _tmp179 + _tmp114 * _tmp186 + _tmp115 * _tmp181 +
                         _tmp158 * _tmp183 - _tmp179 * _tmp41 - _tmp179 * _tmp42 +
                         _tmp185 * sqrt_info(2, 0) + _tmp186 * _tmp41 + _tmp186 * _tmp42;
  const Scalar _tmp190 = _tmp145 + _tmp180;
  const Scalar _tmp191 = _tmp141 + _tmp184;
  const Scalar _tmp192 = _tmp191 * _tmp88;
  const Scalar _tmp193 = _tmp192 * _tmp33;
  const Scalar _tmp194 = _tmp85 * (_tmp125 - _tmp126 + _tmp162);
  const Scalar _tmp195 = _tmp191 * _tmp77;
  const Scalar _tmp196 = _tmp86 * (-_tmp120 + _tmp151 - _tmp168);
  const Scalar _tmp197 = _tmp104 * _tmp190 - _tmp105 * _tmp192 + _tmp105 * _tmp195 -
                         _tmp192 * _tmp44 - _tmp193 * sqrt_info(0, 0) + _tmp194 * _tmp35 +
                         _tmp195 * _tmp44 + _tmp195 * _tmp98 + _tmp196 * sqrt_info(0, 0);
  const Scalar _tmp198 = _tmp190 * _tmp86;
  const Scalar _tmp199 = _tmp109 * _tmp195 - _tmp110 * _tmp192 + _tmp110 * _tmp195 -
                         _tmp111 * _tmp192 + _tmp111 * _tmp195 - _tmp193 * sqrt_info(1, 0) +
                         _tmp194 * _tmp39 + _tmp196 * sqrt_info(1, 0) + _tmp198 * sqrt_info(1, 2);
  const Scalar _tmp200 = _tmp114 * _tmp195 - _tmp192 * _tmp41 - _tmp192 * _tmp42 -
                         _tmp193 * sqrt_info(2, 0) + _tmp194 * _tmp27 * sqrt_info(2, 1) +
                         _tmp195 * _tmp41 + _tmp195 * _tmp42 + _tmp196 * sqrt_info(2, 0) +
                         _tmp198 * sqrt_info(2, 2);

  // Output terms (4)
  if (res != nullptr) {
    Eigen::Matrix<Scalar, 3, 1>& _res = (*res);

    _res(0, 0) = _tmp38;
    _res(1, 0) = _tmp40;
    _res(2, 0) = _tmp43;
  }

  if (jacobian != nullptr) {
    Eigen::Matrix<Scalar, 3, 6>& _jacobian = (*jacobian);

    _jacobian(0, 0) = _tmp107;
    _jacobian(1, 0) = _tmp113;
    _jacobian(2, 0) = _tmp116;
    _jacobian(0, 1) = _tmp136;
    _jacobian(1, 1) = _tmp137;
    _jacobian(2, 1) = _tmp138;
    _jacobian(0, 2) = _tmp155;
    _jacobian(1, 2) = _tmp157;
    _jacobian(2, 2) = _tmp159;
    _jacobian(0, 3) = _tmp175;
    _jacobian(1, 3) = _tmp176;
    _jacobian(2, 3) = _tmp177;
    _jacobian(0, 4) = _tmp187;
    _jacobian(1, 4) = _tmp188;
    _jacobian(2, 4) = _tmp189;
    _jacobian(0, 5) = _tmp197;
    _jacobian(1, 5) = _tmp199;
    _jacobian(2, 5) = _tmp200;
  }

  if (hessian != nullptr) {
    Eigen::Matrix<Scalar, 6, 6>& _hessian = (*hessian);

    _hessian(0, 0) =
        std::pow(_tmp107, Scalar(2)) + std::pow(_tmp113, Scalar(2)) + std::pow(_tmp116, Scalar(2));
    _hessian(1, 0) = _tmp107 * _tmp136 + _tmp113 * _tmp137 + _tmp116 * _tmp138;
    _hessian(2, 0) = _tmp107 * _tmp155 + _tmp113 * _tmp157 + _tmp116 * _tmp159;
    _hessian(3, 0) = _tmp107 * _tmp175 + _tmp113 * _tmp176 + _tmp116 * _tmp177;
    _hessian(4, 0) = _tmp107 * _tmp187 + _tmp113 * _tmp188 + _tmp116 * _tmp189;
    _hessian(5, 0) = _tmp107 * _tmp197 + _tmp113 * _tmp199 + _tmp116 * _tmp200;
    _hessian(0, 1) = 0;
    _hessian(1, 1) =
        std::pow(_tmp136, Scalar(2)) + std::pow(_tmp137, Scalar(2)) + std::pow(_tmp138, Scalar(2));
    _hessian(2, 1) = _tmp136 * _tmp155 + _tmp137 * _tmp157 + _tmp138 * _tmp159;
    _hessian(3, 1) = _tmp136 * _tmp175 + _tmp137 * _tmp176 + _tmp138 * _tmp177;
    _hessian(4, 1) = _tmp136 * _tmp187 + _tmp137 * _tmp188 + _tmp138 * _tmp189;
    _hessian(5, 1) = _tmp136 * _tmp197 + _tmp137 * _tmp199 + _tmp138 * _tmp200;
    _hessian(0, 2) = 0;
    _hessian(1, 2) = 0;
    _hessian(2, 2) =
        std::pow(_tmp155, Scalar(2)) + std::pow(_tmp157, Scalar(2)) + std::pow(_tmp159, Scalar(2));
    _hessian(3, 2) = _tmp155 * _tmp175 + _tmp157 * _tmp176 + _tmp159 * _tmp177;
    _hessian(4, 2) = _tmp155 * _tmp187 + _tmp157 * _tmp188 + _tmp159 * _tmp189;
    _hessian(5, 2) = _tmp155 * _tmp197 + _tmp157 * _tmp199 + _tmp159 * _tmp200;
    _hessian(0, 3) = 0;
    _hessian(1, 3) = 0;
    _hessian(2, 3) = 0;
    _hessian(3, 3) =
        std::pow(_tmp175, Scalar(2)) + std::pow(_tmp176, Scalar(2)) + std::pow(_tmp177, Scalar(2));
    _hessian(4, 3) = _tmp175 * _tmp187 + _tmp176 * _tmp188 + _tmp177 * _tmp189;
    _hessian(5, 3) = _tmp175 * _tmp197 + _tmp176 * _tmp199 + _tmp177 * _tmp200;
    _hessian(0, 4) = 0;
    _hessian(1, 4) = 0;
    _hessian(2, 4) = 0;
    _hessian(3, 4) = 0;
    _hessian(4, 4) =
        std::pow(_tmp187, Scalar(2)) + std::pow(_tmp188, Scalar(2)) + std::pow(_tmp189, Scalar(2));
    _hessian(5, 4) = _tmp187 * _tmp197 + _tmp188 * _tmp199 + _tmp189 * _tmp200;
    _hessian(0, 5) = 0;
    _hessian(1, 5) = 0;
    _hessian(2, 5) = 0;
    _hessian(3, 5) = 0;
    _hessian(4, 5) = 0;
    _hessian(5, 5) =
        std::pow(_tmp197, Scalar(2)) + std::pow(_tmp199, Scalar(2)) + std::pow(_tmp200, Scalar(2));
  }

  if (rhs != nullptr) {
    Eigen::Matrix<Scalar, 6, 1>& _rhs = (*rhs);

    _rhs(0, 0) = _tmp107 * _tmp38 + _tmp113 * _tmp40 + _tmp116 * _tmp43;
    _rhs(1, 0) = _tmp136 * _tmp38 + _tmp137 * _tmp40 + _tmp138 * _tmp43;
    _rhs(2, 0) = _tmp155 * _tmp38 + _tmp157 * _tmp40 + _tmp159 * _tmp43;
    _rhs(3, 0) = _tmp175 * _tmp38 + _tmp176 * _tmp40 + _tmp177 * _tmp43;
    _rhs(4, 0) = _tmp187 * _tmp38 + _tmp188 * _tmp40 + _tmp189 * _tmp43;
    _rhs(5, 0) = _tmp197 * _tmp38 + _tmp199 * _tmp40 + _tmp200 * _tmp43;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
