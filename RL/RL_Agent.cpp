//
// Created by daddabarba on 25/02/19.
//

#include "RL_Agent.hpp"
#include "Defs.hpp"

RLIB_INTERFACES::RL_Agent::RL_Agent(int state_space_size) :
    P(1, (const arma::uword) state_space_size)
{}

auto RLIB_INTERFACES::RL_Agent::policy(State state) -> Action {
    return (Action)(this->P).index_max();
}