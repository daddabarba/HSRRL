//
// Created by daddabarba on 2/3/19.
//

#ifndef REACT_PARAMETERNODE_H
#define REACT_PARAMETERNODE_H

#include "Defs.hpp"

#include "Variable.hpp"

REACT_CONC_START

template<typename S>
class ParameterNode : public Variable<S>{

public:

    explicit ParameterNode(Variable<S>* val) :
            _var(val)
    {};

    auto notify_change() -> void override {}

    auto set(S value) -> void override {};

    virtual auto get() -> S override {
        return _var->get();
    }

    operator S() override {
        return (S)(*_var);
    }

    operator S*() override {
        return (S*)(*_var);
    }

protected:
    Variable<S>* _var;
};



template<typename S>
auto make_parameter(Variable<S>* other) -> ParameterNode<S>*{
    return new ParameterNode<S>(other);
}

REACT_CONC_END

#endif //REACT_PARAMETERNODE_H
