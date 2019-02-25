//
// Created by daddabarba on 25/02/19.
//

#include "RL_Agent.hpp"
#include "Defs.hpp"

RLIB_ABSTRACT::RL_Agent::RL_Agent(Space_Size state_space_size, Space_Size action_space_size) :
    state_space_size(state_space_size),
    action_space_size(action_space_size),
    P(REACT_CONC::make_variable<arma::Mat<double>>(arma::Mat<double>(action_space_size, 1))),
    generator((unsigned long)time(nullptr))
{}

auto RLIB_ABSTRACT::RL_Agent::get_S_size() -> Space_Size{
    return this->state_space_size;
}

auto RLIB_ABSTRACT::RL_Agent::get_A_size() -> Space_Size{
    return this->action_space_size;
}

auto RLIB_ABSTRACT::RL_Agent::getP() -> REACT_CONC::Variable<arma::Mat<double>>*{
    return this->P;
}

auto RLIB_ABSTRACT::RL_Agent::get_current_state() -> REACT_CONC::Variable<State>* {
    return this->current_state;
}

auto RLIB_ABSTRACT::RL_Agent::set_current_state(State state) -> void {
    this->current_state->set(state);
}

auto RLIB_ABSTRACT::RL_Agent::get_generator() -> std::mt19937&{
    return std::forward<std::mt19937&>(this->generator);
}