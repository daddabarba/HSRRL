//
// Created by daddabarba on 2/3/19.
//

#ifndef REACT_PARAMETERNODE_H
#define REACT_PARAMETERNODE_H

#include "Defs.h"

#include "Variable.h"

REACT_CONC_START

template<typename S>
class ParameterNode : public Variable<S>{

public:

    explicit ParameterNode(S* val) :
            Variable<S>(val)
    {};

    ParameterNode() = default;

    auto notify_change() -> void override {}

};


template<typename S>
auto make_parameter(Variable<S>& other) -> ParameterNode<S>*{
    return new ParameterNode<S>((S*)other);
}

template<typename S>
auto make_parameter(S* val) -> ParameterNode<S>*{
    return new ParameterNode<S>(val);
}

template<typename S, typename ...TArgs>
auto make_parameter(TArgs ... args) -> ParameterNode<S>*{
    return make_parameter(new S(args...));
}

REACT_CONC_END

#endif //REACT_PARAMETERNODE_H
