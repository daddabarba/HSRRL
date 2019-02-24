//
// Created by daddabarba on 2/1/19.
//

#ifndef REACT_OPERATOR_H
#define REACT_OPERATOR_H

#include "Defs.h"

#include <utility>
#include <functional>
#include <tuple>

#include "Notification.h"
#include "utils.h"

REACT_CONC_START

enum Update_Type{
    SET = 0, UPDATE = 1
};

template<
    typename TFun,
    typename TOut,
    typename ... TIn
>
class Operator : public Observer{

public:

    using RetType = typename std::result_of<TFun(TIn...)>::type;

    Operator(TFun&& fun, Variable<TOut>&& output, Variable<TIn>&& ... args) :
        Operator(std::forward<TFun>(fun), SET, std::forward<Variable<TOut>>(output), std::forward<Variable<TIn>>(args)...)
    {};

    Operator(TFun&& fun, Update_Type update_type, Variable<TOut>&& output, Variable<TIn>&& ... args) :
        output(output),
        expression(fun),
        arguments(std::forward<TIn*>((TIn*)args)...),
        update_type(update_type)
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
    Update_Type update_type;

    auto has_changed() -> void override {
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
auto make_operator(TFun &&fun, Update_Type update_type, Variable <TOut> *output, Variable <TIn> *... args) -> Operator<TFun, TOut, TIn...>*{
    return new Operator<TFun, TOut, TIn...>(
            std::forward<TFun>(fun),
            update_type,
            std::forward<Variable<TOut>>(std::move(*output)),
            std::forward<Variable<TIn>>(std::move(*args))...
    );
}

template<
        typename TFun,
        typename TOut,
        typename ... TIn
>
auto make_operator(TFun &&fun, Variable <TOut> *output, Variable <TIn> *... args) -> Operator<TFun, TOut, TIn...>*{
    return new Operator<TFun, TOut, TIn...>(
            std::forward<TFun>(fun),
            std::forward<Variable<TOut>>(std::move(*output)),
            std::forward<Variable<TIn>>(std::move(*args))...
    );
}

REACT_CONC_END

#endif //REACT_OPERATOR_H
