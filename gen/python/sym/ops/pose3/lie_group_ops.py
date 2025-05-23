# -----------------------------------------------------------------------------
# This file was autogenerated by symforce from template:
#     ops/CLASS/lie_group_ops.py.jinja
# Do NOT modify by hand.
# -----------------------------------------------------------------------------

# ruff: noqa: PLR0915, F401, PLW0211, PLR0914

import math
import typing as T

import numpy

import sym


class LieGroupOps(object):
    """
    Python LieGroupOps implementation for :py:class:`symforce.geo.pose3.Pose3`.
    """

    @staticmethod
    def from_tangent(vec, epsilon):
        # type: (numpy.ndarray, float) -> sym.Pose3

        # Total ops: 15

        # Input arrays
        if vec.shape == (6,):
            vec = vec.reshape((6, 1))
        elif vec.shape != (6, 1):
            raise IndexError(
                "vec is expected to have shape (6, 1) or (6,); instead had shape {}".format(
                    vec.shape
                )
            )

        # Intermediate terms (3)
        _tmp0 = math.sqrt(epsilon**2 + vec[0, 0] ** 2 + vec[1, 0] ** 2 + vec[2, 0] ** 2)
        _tmp1 = (1.0 / 2.0) * _tmp0
        _tmp2 = math.sin(_tmp1) / _tmp0

        # Output terms
        _res = [0.0] * 7
        _res[0] = _tmp2 * vec[0, 0]
        _res[1] = _tmp2 * vec[1, 0]
        _res[2] = _tmp2 * vec[2, 0]
        _res[3] = math.cos(_tmp1)
        _res[4] = vec[3, 0]
        _res[5] = vec[4, 0]
        _res[6] = vec[5, 0]
        return sym.Pose3.from_storage(_res)

    @staticmethod
    def to_tangent(a, epsilon):
        # type: (sym.Pose3, float) -> numpy.ndarray

        # Total ops: 14

        # Input arrays
        _a = a.data

        # Intermediate terms (2)
        _tmp0 = min(abs(_a[3]), 1 - epsilon)
        _tmp1 = 2 * math.copysign(1, _a[3]) * math.acos(_tmp0) / math.sqrt(1 - _tmp0**2)

        # Output terms
        _res = numpy.zeros(6)
        _res[0] = _a[0] * _tmp1
        _res[1] = _a[1] * _tmp1
        _res[2] = _a[2] * _tmp1
        _res[3] = _a[4]
        _res[4] = _a[5]
        _res[5] = _a[6]
        return _res

    @staticmethod
    def retract(a, vec, epsilon):
        # type: (sym.Pose3, numpy.ndarray, float) -> sym.Pose3

        # Total ops: 48

        # Input arrays
        _a = a.data
        if vec.shape == (6,):
            vec = vec.reshape((6, 1))
        elif vec.shape != (6, 1):
            raise IndexError(
                "vec is expected to have shape (6, 1) or (6,); instead had shape {}".format(
                    vec.shape
                )
            )

        # Intermediate terms (9)
        _tmp0 = math.sqrt(epsilon**2 + vec[0, 0] ** 2 + vec[1, 0] ** 2 + vec[2, 0] ** 2)
        _tmp1 = (1.0 / 2.0) * _tmp0
        _tmp2 = math.cos(_tmp1)
        _tmp3 = math.sin(_tmp1) / _tmp0
        _tmp4 = _a[3] * _tmp3
        _tmp5 = _a[2] * _tmp3
        _tmp6 = _tmp3 * vec[2, 0]
        _tmp7 = _a[0] * _tmp3
        _tmp8 = _a[1] * _tmp3

        # Output terms
        _res = [0.0] * 7
        _res[0] = _a[0] * _tmp2 + _a[1] * _tmp6 + _tmp4 * vec[0, 0] - _tmp5 * vec[1, 0]
        _res[1] = _a[1] * _tmp2 + _tmp4 * vec[1, 0] + _tmp5 * vec[0, 0] - _tmp7 * vec[2, 0]
        _res[2] = _a[2] * _tmp2 + _a[3] * _tmp6 + _tmp7 * vec[1, 0] - _tmp8 * vec[0, 0]
        _res[3] = -_a[2] * _tmp6 + _a[3] * _tmp2 - _tmp7 * vec[0, 0] - _tmp8 * vec[1, 0]
        _res[4] = _a[4] + vec[3, 0]
        _res[5] = _a[5] + vec[4, 0]
        _res[6] = _a[6] + vec[5, 0]
        return sym.Pose3.from_storage(_res)

    @staticmethod
    def local_coordinates(a, b, epsilon):
        # type: (sym.Pose3, sym.Pose3, float) -> numpy.ndarray

        # Total ops: 47

        # Input arrays
        _a = a.data
        _b = b.data

        # Intermediate terms (4)
        _tmp0 = -_a[0] * _b[0] - _a[1] * _b[1] - _a[2] * _b[2]
        _tmp1 = _a[3] * _b[3]
        _tmp2 = min(1 - epsilon, abs(_tmp0 - _tmp1))
        _tmp3 = 2 * math.copysign(1, -_tmp0 + _tmp1) * math.acos(_tmp2) / math.sqrt(1 - _tmp2**2)

        # Output terms
        _res = numpy.zeros(6)
        _res[0] = _tmp3 * (-_a[0] * _b[3] - _a[1] * _b[2] + _a[2] * _b[1] + _a[3] * _b[0])
        _res[1] = _tmp3 * (_a[0] * _b[2] - _a[1] * _b[3] - _a[2] * _b[0] + _a[3] * _b[1])
        _res[2] = _tmp3 * (-_a[0] * _b[1] + _a[1] * _b[0] - _a[2] * _b[3] + _a[3] * _b[2])
        _res[3] = -_a[4] + _b[4]
        _res[4] = -_a[5] + _b[5]
        _res[5] = -_a[6] + _b[6]
        return _res

    @staticmethod
    def interpolate(a, b, alpha, epsilon):
        # type: (sym.Pose3, sym.Pose3, float, float) -> sym.Pose3

        # Total ops: 106

        # Input arrays
        _a = a.data
        _b = b.data

        # Intermediate terms (18)
        _tmp0 = _a[0] * _b[2] - _a[1] * _b[3] - _a[2] * _b[0] + _a[3] * _b[1]
        _tmp1 = -_a[0] * _b[0] - _a[1] * _b[1] - _a[2] * _b[2]
        _tmp2 = _a[3] * _b[3]
        _tmp3 = math.copysign(1, -_tmp1 + _tmp2)
        _tmp4 = min(1 - epsilon, abs(_tmp1 - _tmp2))
        _tmp5 = math.acos(_tmp4)
        _tmp6 = -_a[0] * _b[3] - _a[1] * _b[2] + _a[2] * _b[1] + _a[3] * _b[0]
        _tmp7 = 1 - _tmp4**2
        _tmp8 = 4 * _tmp3**2 * _tmp5**2 * alpha**2 / _tmp7
        _tmp9 = -_a[0] * _b[1] + _a[1] * _b[0] - _a[2] * _b[3] + _a[3] * _b[2]
        _tmp10 = math.sqrt(_tmp0**2 * _tmp8 + _tmp6**2 * _tmp8 + _tmp8 * _tmp9**2 + epsilon**2)
        _tmp11 = (1.0 / 2.0) * _tmp10
        _tmp12 = 2 * _tmp3 * _tmp5 * alpha * math.sin(_tmp11) / (_tmp10 * math.sqrt(_tmp7))
        _tmp13 = _a[2] * _tmp12
        _tmp14 = math.cos(_tmp11)
        _tmp15 = _a[1] * _tmp12
        _tmp16 = _a[3] * _tmp12
        _tmp17 = _a[0] * _tmp12

        # Output terms
        _res = [0.0] * 7
        _res[0] = _a[0] * _tmp14 - _tmp0 * _tmp13 + _tmp15 * _tmp9 + _tmp16 * _tmp6
        _res[1] = _a[1] * _tmp14 + _tmp0 * _tmp16 + _tmp13 * _tmp6 - _tmp17 * _tmp9
        _res[2] = _a[2] * _tmp14 + _tmp0 * _tmp17 - _tmp15 * _tmp6 + _tmp16 * _tmp9
        _res[3] = _a[3] * _tmp14 - _tmp0 * _tmp15 - _tmp13 * _tmp9 - _tmp17 * _tmp6
        _res[4] = _a[4] + alpha * (-_a[4] + _b[4])
        _res[5] = _a[5] + alpha * (-_a[5] + _b[5])
        _res[6] = _a[6] + alpha * (-_a[6] + _b[6])
        return sym.Pose3.from_storage(_res)
