# This file automatically generated by skymarshal
# DO NOT MODIFY BY HAND
# fmt: off
# isort: off
# mypy: disallow-untyped-defs

import copy
import typing as T  # pylint: disable=unused-import

from io import BytesIO
import struct
from lcmtypes.eigen_lcm._Vector2d import Vector2d

class d_t(object):
    __slots__: T.List[str] = ["x", "y"]

    def __init__(
        self,
        x: float=0.0,
        y: T.Optional[Vector2d]=None,
        _skip_initialize: bool=False,
    ) -> None:
        """ If _skip_initialize is True, all other constructor arguments are ignored """
        if _skip_initialize:
            return
        self.x: float = x
        self.y: Vector2d = Vector2d._default() if y is None else y

    @staticmethod
    def from_all_fields(
        x: float,
        y: Vector2d,
    ) -> "d_t":
        return d_t(
            x=x,
            y=y,
        )

    @staticmethod
    def _skytype_meta() -> T.Dict[str, str]:
        return dict(
            type="struct",
            package="sym",
            name="d_t",
        )

    @classmethod
    def _default(cls) -> "d_t":
        return cls()

    def __repr__(self) -> str:
        return "d_t({})".format(
            ", ".join("{}={}".format(name, repr(getattr(self, name))) for name in self.__slots__))

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, d_t):
            return NotImplemented
        return (
            (self.x==other.x) and
            (self.y==other.y)
        )
    # Disallow hashing for python struct lcmtypes.
    __hash__ = None  # type: ignore[assignment]

    def encode(self) -> bytes:
        buf = BytesIO()
        buf.write(d_t._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf: T.BinaryIO) -> None:
        buf.write(d_t._CACHED_STRUCT_0.pack(self.x))
        if hasattr(self.y, '_get_packed_fingerprint'):
            assert self.y._get_packed_fingerprint() == Vector2d._get_packed_fingerprint()
        else:
            assert self.y._get_hash_recursive([]) == Vector2d._get_hash_recursive([])
        self.y._encode_one(buf)

    @staticmethod
    def decode(data: T.Union[bytes, T.BinaryIO]) -> "d_t":
        # NOTE(eric): This function can technically accept either a BinaryIO or
        # anything that supports the C++ Buffer Protocol,
        # which is unspecifiable in type hints.

        if hasattr(data, "read"):
            # NOTE(eric): mypy isn't able to figure out the hasattr check
            buf = T.cast(T.BinaryIO, data)
        else:
            buf = BytesIO(T.cast(bytes, data))

        if buf.read(8) != d_t._get_packed_fingerprint():
            raise ValueError("Decode error")
        return d_t._decode_one(buf)

    @staticmethod
    def _decode_one(buf: T.BinaryIO) -> "d_t":
        self = d_t(_skip_initialize=True)
        self.x = d_t._CACHED_STRUCT_0.unpack(buf.read(8))[0]
        self.y = Vector2d._decode_one(buf)
        return self

    @staticmethod
    def _get_hash_recursive(parents: T.List[T.Type]) -> int:
        if d_t in parents: return 0
        newparents = parents + [d_t]
        tmphash = (0x21f0a3980ff1bd27+ Vector2d._get_hash_recursive(newparents)) & 0xffffffffffffffff
        tmphash = (((tmphash<<1)&0xffffffffffffffff)  + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash

    _packed_fingerprint: T.Optional[bytes] = None

    @staticmethod
    def _get_packed_fingerprint() -> bytes:
        if d_t._packed_fingerprint is None:
            d_t._packed_fingerprint = struct.pack(">Q", d_t._get_hash_recursive([]))
        return d_t._packed_fingerprint

    def deepcopy(self, **kwargs: T.Any) -> "d_t":
        """
        Deep copy of this LCM type

        Returns a copy w/ members specified by kwargs replaced with new values specified by kwargs.
        """
        result = copy.deepcopy(self)
        for key in kwargs:
            if not hasattr(result, key):
                raise KeyError("Type d_t does not have attribute: " + str(key))
            setattr(result, key, kwargs[key])
        return result

    _CACHED_STRUCT_0 = struct.Struct(">d")
