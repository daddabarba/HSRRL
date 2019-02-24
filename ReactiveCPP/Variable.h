//
// Created by daddabarba on 2/2/19.
//

#ifndef REACT_VARIABLE_H
#define REACT_VARIABLE_H

#include "Defs.h"

#include "Notification.h"

REACT_CONC_START

template<typename S>
class Variable : public Observable{

public:

    explicit Variable(S* val):
        _value(val)
    {};

    Variable() :
        _value((S*)malloc(sizeof(S)))
    {};

    ~Variable(){
        free((S*)this);
    }

    auto get() -> S{
        return *(this->_value);
    }

    auto set(S value) -> void {
        *(this->_value) = value;
        this->notify_change();
    };


    operator S() {
        return this->get_value();
    }

    operator S&() {
        return std::ref(*_value);
    }

    operator S*() {
        return this->_value;
    }

protected:

    S* _value;
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


#endif //REACT_VARIABLE_H
