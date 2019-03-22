//
// Created by daddabarba on 3/21/19.
//

#include "RL_Actor.hpp"

ACTOR::RL_Actor::RL_Actor(RLIB_BASES::RL_Agent *pi) :
        pi(pi)

{};

auto ACTOR::RL_Actor::act(State s) -> Action {
    return this->getPi()->policy(s);
}

auto ACTOR::RL_Actor::getPi() -> RLIB_BASES::RL_Agent* {
    return this->pi;
}