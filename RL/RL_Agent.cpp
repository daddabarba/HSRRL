//
// Created by daddabarba on 25/02/19.
//

#include "RL_Agent.hpp"
#include "Defs.hpp"

RLIB_INTERFACES::RL_Agent::RL_Agent(int state_space_size) :
    P(new arma::Mat<double>(1, (const arma::uword) state_space_size)),
    generator((unsigned long)time(0))
{}

auto RLIB_INTERFACES::RL_Agent::policy(State state) -> Action {
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

auto RLIB_INTERFACES::RL_Agent::getP() -> arma::Mat<double>{
    return (arma::Mat<double >)(this->P);
}

auto RLIB_INTERFACES::RL_Agent::get_current_state() -> State {
    return (State)(this->current_state);
}

auto RLIB_INTERFACES::RL_Agent::set_current_state(State state) -> void {
    this->current_state.set(state);
}