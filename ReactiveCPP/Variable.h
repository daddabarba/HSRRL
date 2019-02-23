//
// Created by daddabarba on 2/2/19.
//

#ifndef HSRRL_INPUTNODE_H
#define HSRRL_INPUTNODE_H

#include "Defs.h"

#include "Node.h"

REACT_CONC_START

template<typename S>
class Variable : public Node<S>{

public:

    explicit Variable(S* val) :
            Node<S>(val)
    {};

    Variable() = default;

    auto set(S value) -> void{
        this->set_value(value);
    }

};

template<typename S>
auto make_variable(S* val) -> Variable<S>*{
    return new Variable<S>(val);
}

template<typename S, typename ...TArgs>
auto make_variable(TArgs ... args) -> Variable<S>*{
    return make_variable(new S(args...));
}

template<typename S>
auto make_variable() -> Variable<S>*{
    return new Variable<S>();
}

REACT_CONC_END


#endif //HSRRL_INPUTNODE_H
