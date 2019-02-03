//
// Created by daddabarba on 2/3/19.
//

#ifndef HSRRL_PARAMETERNODE_H
#define HSRRL_PARAMETERNODE_H

#include "Defs.h"

#include "Node.h"

REACT_CONC_START

template<typename S>
class ParameterNode : public Node<S>{

public:

    explicit ParameterNode(S* val) :
            Node<S>(val)
    {};

    ParameterNode() = default;

    auto notify_change() -> void override {}

};


template<typename S>
auto make_parameter(Node<S>& other) -> ParameterNode<S>*{
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

#endif //HSRRL_PARAMETERNODE_H
