//
// Created by daddabarba on 25/02/19.
//

#include "RL_Agent.hpp"
#include "Defs.hpp"

RLIB_ABSTRACT::RL_Agent::RL_Agent(Space_Size state_space_size, Space_Size action_space_size) :
    state_space_size(state_space_size),
    action_space_size(action_space_size),
    P(new arma::Mat<double>(1, (const arma::uword) action_space_size)),
    generator((unsigned long)time(nullptr))
{}

auto RLIB_ABSTRACT::RL_Agent::policy(State state) -> Action {
    this->current_state.set(state);
    return this->policy();
}

auto RLIB_ABSTRACT::RL_Agent::policy() -> Action {
    auto M = (arma::Mat<double>)P;
    return ((Action)std::discrete_distribution<int>(
                M.size(),
                0.0,
                1.0,
                [M](double i) -> double{
                    return M[(unsigned int)ceil(i*M.size()-0.5)];
                }
            )(this->generator));
}

auto RLIB_ABSTRACT::RL_Agent::get_S_size() -> Space_Size{
    return this->state_space_size;
}

auto RLIB_ABSTRACT::RL_Agent::get_A_size() -> Space_Size{
    return this->action_space_size;
}

auto RLIB_ABSTRACT::RL_Agent::getP() -> arma::Mat<double>{
    return (arma::Mat<double >)(this->P);
}

auto RLIB_ABSTRACT::RL_Agent::get_current_state() -> State {
    return (State)(this->current_state);
}

auto RLIB_ABSTRACT::RL_Agent::set_current_state(State state) -> void {
    this->current_state.set(state);
}