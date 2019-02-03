//
// Created by daddabarba on 2/2/19.
//

#ifndef HSRRL_INPUTNODE_H
#define HSRRL_INPUTNODE_H

#include "Defs.h"

#include "Node.h"

REACT_CONC_START

template<typename S>
class InputNode : public Node<S>{

public:

    explicit InputNode(S&& val) :
            Node<S>(val)
    {};

    InputNode() = default;

    auto set(S value) -> void{
        this->set_value(value);
    }

};

template<typename S>
auto make_input(S&& val) -> InputNode<S>*{
    return new InputNode<S>(std::forward<S>(val));
}

template<typename S>
auto make_input(S* val) -> InputNode<S>*{
    return make_input(std::move(*val));
}

template<typename S>
auto make_input() -> InputNode<S>*{
    return new InputNode<S>();
}

REACT_CONC_END


#endif //HSRRL_INPUTNODE_H
