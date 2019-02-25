//
// Created by daddabarba on 25/02/19.
//

#include "TransitionLearning_Agent.hpp"
#include "Defs.hpp"

RLIB_INTERFACES::TransitionLearning_Agent::TransitionLearning_Agent(int state_space_size) :
        RL_Agent(state_space_size)
{};

auto RLIB_INTERFACES::TransitionLearning_Agent::learn(RLIB_INTERFACES::Transition transition) -> void{
        this->t.set(transition);
}

auto RLIB_INTERFACES::TransitionLearning_Agent::getTransition() -> RLIB_INTERFACES::Transition {
        return this->t;
}