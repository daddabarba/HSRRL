//
// Created by daddabarba on 25/02/19.
//

#include "TransitionLearning_Agent.hpp"
#include "../Defs.hpp"

RLIB_ABSTRACT::TransitionLearning_Agent::TransitionLearning_Agent(Space_Size state_space_size, Space_Size action_space_size) :
        RL_Agent(state_space_size, action_space_size)
{};

auto RLIB_ABSTRACT::TransitionLearning_Agent::getTransition() -> REACT_CONC::Variable<RLIB_INTERFACES::Transition> {
        return this->t;
}