//
// Created by daddabarba on 2/1/19.
//

#ifndef HSRRL_NODE_H
#define HSRRL_NODE_H

#include "Defs.h"

#include <stdarg.h>
#include <vector>
#include <functional>

REACT_START

template<typename S>
class Node {

public:
    explicit Node(S val):
            _value(val)
    {};

    Node() = default;

    auto get_value() -> S{
        return this->_value;
    }

    operator S() {
        return this->_value;
    }

    operator S&() {
        return std::ref(_value);
    }

    operator S*() {
        return &(this->_value);
    }

    auto link_successor(Node* successor) -> void{
        _successors.push_back(successor);
    }

protected:

    S _value;
    std::vector<Node*> _successors;

    virtual auto has_changed() -> void {
        return;
    };

    auto notify_change() -> void {
        for(Node* successor : _successors)
            successor->has_changed();
    }

    auto set_value(S value) -> void {
        if(value != this->_value) {
            this->_value = value;
            this->notify_change();
        }
    };
};


REACT_END

#endif //HSRRL_NODE_H
