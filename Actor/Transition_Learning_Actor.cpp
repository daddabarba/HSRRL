//
// Created by daddabarba on 3/22/19.
//

#include "Transition_Learning_Actor.hpp"

ACTOR::Transition_Learning_Actor::Transition_Learning_Actor(RLIB_BASES::Transition_Learning_Agent *pi) :
        ACTOR::RL_Actor(pi)
{};

auto ACTOR::Transition_Learning_Actor::act(State s) -> Action {
    return this->a = ACTOR::RL_Actor::act(this->s = s);
}

auto ACTOR::Transition_Learning_Actor::learn(Reward r, State s) -> void {
    getPi()->learn({getState(), s, getAction(), r});
}

auto ACTOR::Transition_Learning_Actor::getPi() -> RLIB_BASES::Transition_Learning_Agent* {
    return this->pi;
}

auto ACTOR::Transition_Learning_Actor::getState() -> State {
    return this->s;
}

auto ACTOR::Transition_Learning_Actor::getAction() -> Action {
    return this->a;
}