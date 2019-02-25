//
// Created by daddabarba on 2/2/19.
//

#ifndef REACT_VARIABLE_H
#define REACT_VARIABLE_H

#include "Defs.hpp"
#include "Notification.hpp"

#include <cstdlib>

REACT_CONC_START

template<typename S>
class Variable : public Observable{

public:

    explicit Variable(S val):
        _value(val)
    {};

    Variable() = default;

    virtual auto get() -> S{
        return this->_value;
    }

    virtual auto set(S value) -> void {
        this->_value = value;
        this->notify_change();
    };

    auto reload() -> void {
        this->notify_change();
    }

    operator S() {
        return std::forward<S>(_value);
    }

    operator S*() {
        return &(_value);
    }

protected:

    S _value;
};

template<typename S>
auto make_variable(S val) -> Variable<S>*{
    return new Variable<S>(val);
}

template<typename S>
auto make_variable() -> Variable<S>*{
    return new Variable<S>();
}

REACT_CONC_END


#endif //REACT_VARIABLE_H
