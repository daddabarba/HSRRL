//
// Created by daddabarba on 2/1/19.
//

#ifndef HSRRL_VARNODE_H
#define HSRRL_VARNODE_H

#include "Defs.h"

#include <utility>
#include <functional>
#include <tuple>
//#include <map>

#include "Node.h"
#include "utils.h"

REACT_CONC_START

enum Dependency{
    ALL = 0, ANY = 1
};

template<
    typename TFun,
    typename ... TIn
>
class VarNode : public Node<typename std::result_of<TFun(TIn...)>::type>{

public:

    using RetType = typename std::result_of<TFun(TIn...)>::type;

    VarNode(TFun&& fun, Dependency dependency, Node<TIn>&& ... args) :
        dependency(dependency),
        expression(fun),
        arguments(std::forward<TIn*>((TIn*)args)...)
        /*expression(
                std::bind(
                        std::forward<TFun>(fun),
                        std::forward<TIn>((TIn&)args)...
                )
        )*/
    {
        //static_assert(sizeof...(TIn) == N, "Number of arguments not matching");

        this->evaluate();
        link_predecessors(std::forward<Node<TIn>>(args)...);
    };

    template<typename T>
    auto link_predecessors(Node<T>&& pred) -> void{
        pred.link_successor(this);
    }

    template<typename T, typename ...Ts>
    auto link_predecessors(Node<T>&& pred, Node<Ts>&& ...others ) -> void {
        link_predecessors(std::forward<Node<T>>(pred));
        link_predecessors(std::forward<Node<Ts>>(others)...);
    };

protected:

    std::function<RetType(TIn...)> expression;
    std::tuple<TIn*...> arguments;
    Dependency dependency;

    //std::map<Node, bool> changes;
    //int num_predecessors, num_changes;

    auto has_changed() -> void override {
        if( (this->dependency) == ANY )
            this->evaluate();
    }

    auto evaluate() -> void {
        this->evaluate(SEQ::gen_seq<std::tuple_size<decltype(this->arguments)>::value>());
    };

    template<int ...Is>
    auto evaluate(SEQ::seq<Is...>) -> void {
        this->set_value(this->expression((*std::get<Is>(this->arguments))...));
    }

};

REACT_CONC_END

#endif //HSRRL_VALUENODE_H
