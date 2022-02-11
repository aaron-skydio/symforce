from symforce import ops
from symforce import geo
from symforce import sympy as sm
from symforce import typing as T
from symforce.codegen import Codegen
from symforce.codegen import CodegenConfig


def make_group_ops_funcs(cls: T.Type, config: CodegenConfig) -> T.List[Codegen]:
    """
    Create func spec arguments for group ops on the given class.
    """
    identity = Codegen.function(
        name="identity", func=(lambda: ops.GroupOps.identity(cls)), input_types=[], config=config
    )

    inverse = Codegen.function(
        func=ops.GroupOps.inverse,
        input_types=[cls],
        config=config,
        docstring=ops.GroupOps.inverse.__doc__,
    )

    compose = Codegen.function(
        func=ops.GroupOps.compose,
        input_types=[cls, cls],
        config=config,
        docstring=ops.GroupOps.compose.__doc__,
    )

    between = Codegen.function(func=ops.GroupOps.between, input_types=[cls, cls], config=config)

    return [
        identity,
        inverse,
        compose,
        between,
        inverse.with_jacobians(),
        compose.with_jacobians(),
        between.with_jacobians(),
    ]


def make_lie_group_ops_funcs(cls: T.Type, config: CodegenConfig) -> T.List[Codegen]:
    """
    Create func spec arguments for lie group ops on the given class.
    """
    tangent_vec = geo.M(list(range(ops.LieGroupOps.tangent_dim(cls))))
    return [
        Codegen.function(
            name="from_tangent",
            func=(lambda vec, epsilon: ops.LieGroupOps.from_tangent(cls, vec, epsilon)),
            input_types=[tangent_vec, sm.Symbol],
            config=config,
            docstring=ops.LieGroupOps.from_tangent.__doc__,
        ),
        Codegen.function(
            func=ops.LieGroupOps.to_tangent,
            input_types=[cls, sm.Symbol],
            config=config,
            docstring=ops.LieGroupOps.to_tangent.__doc__,
        ),
        Codegen.function(
            func=ops.LieGroupOps.retract,
            input_types=[cls, tangent_vec, sm.Symbol],
            config=config,
            docstring=ops.LieGroupOps.retract.__doc__,
        ),
        Codegen.function(
            func=ops.LieGroupOps.local_coordinates,
            input_types=[cls, cls, sm.Symbol],
            config=config,
            docstring=ops.LieGroupOps.local_coordinates.__doc__,
        ),
    ]