//
// Created by daddabarba on 2/3/19.
//

#ifndef REACT_PARAMETERNODE_H
#define REACT_PARAMETERNODE_H

#include "Defs.hpp"

#include "Variable.hpp"

REACT_CONC_START

template <typename S>
using Nested_Var = Variable<Variable<S>>;

template<typename S>
class ParameterNode : public Nested_Var<S>{

public:

    explicit ParameterNode(Variable<S> val) :
            Nested_Var<S>(val)
    {};

    auto notify_change() -> void override {}

    auto set(Variable<S> value) -> void override {};
};


template<typename S>
auto make_parameter(Variable<S>& other) -> ParameterNode<S>*{
    return new ParameterNode<S>(std::forward<Variable<S>>(other));
}

template<typename S>
auto make_parameter(Variable<S>* other) -> ParameterNode<S>*{
    return new ParameterNode<S>(std::forward<Variable<S>>(*other));
}

REACT_CONC_END

#endif //REACT_PARAMETERNODE_H
