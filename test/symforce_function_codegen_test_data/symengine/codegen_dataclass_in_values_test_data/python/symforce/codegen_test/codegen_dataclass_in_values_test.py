# -----------------------------------------------------------------------------
# This file was autogenerated by symforce from template:
#     function/FUNCTION.py.jinja
# Do NOT modify by hand.
# -----------------------------------------------------------------------------

# ruff: noqa: F401, PLR0912, PLR0913, PLR0914, PLR0915, PLR0917, RUF100

import math
import typing as T

import numpy

import sym


def codegen_dataclass_in_values_test(my_dataclass):
    # type: (T.Any) -> sym.Rot3
    """
    This function was autogenerated. Do not modify by hand.

    Args:
        my_dataclass: Values

    Outputs:
        rot: Rot3
    """

    # Total ops: 0

    # Input arrays

    # Intermediate terms (0)

    # Output terms
    _rot = [0.0] * 4
    _rot[0] = my_dataclass.rot.data[0]
    _rot[1] = my_dataclass.rot.data[1]
    _rot[2] = my_dataclass.rot.data[2]
    _rot[3] = my_dataclass.rot.data[3]
    return sym.Rot3.from_storage(_rot)
