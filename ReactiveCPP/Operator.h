//
// Created by daddabarba on 2/1/19.
//

#ifndef HSRRL_VARNODE_H
#define HSRRL_VARNODE_H

#include "Defs.h"

#include <utility>
#include <functional>
#include <tuple>

#include "Notification.h"
#include "utils.h"

REACT_CONC_START

enum Dependency{
    ALL = 0, ANY = 1
};

template<
    typename TFun,
    typename TOut,
    typename ... TIn
>
class Operator : public Observer{

public:

    using RetType = typename std::result_of<TFun(TIn...)>::type;

    Operator(TFun&& fun, Dependency dependency, Variable<TOut>&& output, Variable<TIn>&& ... args) :
        output(output),
        expression(fun),
        arguments(std::forward<TIn*>((TIn*)args)...),
        dependency(dependency)
    {
        this->evaluate();
        link_predecessors(std::forward<Variable<TIn>>(args)...);
    };

    template<typename T>
    auto link_predecessors(Variable<T>&& pred) -> void{
        pred.link_successor(this);
    }

    template<typename T, typename ...Ts>
    auto link_predecessors(Variable<T>&& pred, Variable<Ts>&& ...others ) -> void {
        link_predecessors(std::forward<Variable<T>>(pred));
        link_predecessors(std::forward<Variable<Ts>>(others)...);
    }

protected:

    Variable<TOut>& output;
    std::function<RetType(TIn...)> expression;
    std::tuple<TIn*...> arguments;
    Dependency dependency;

    auto has_changed() -> void override {
        if( (this->dependency) == ANY )
            this->evaluate();
    }

    auto evaluate() -> void {
        this->evaluate(SEQ::gen_seq<std::tuple_size<decltype(this->arguments)>::value>());
    };

    template<int ...Is>
    auto evaluate(SEQ::seq<Is...>) -> void {
        this->output.set(this->expression((*std::get<Is>(this->arguments))...));
    }

};


template<
        typename TFun,
        typename TOut,
        typename ... TIn
>
auto make_operator(TFun &&fun, Dependency dependency, Variable <TOut> *output, Variable <TIn> *... args) -> Operator<TFun, TOut, TIn...>*{
    return new Operator<TFun, TOut, TIn...>(
            std::forward<TFun>(fun),
            dependency,
            std::forward<Variable<TOut>>(std::move(*output)),
            std::forward<Variable<TIn>>(std::move(*args))...
    );
}

REACT_CONC_END

#endif //HSRRL_VALUENODE_H
