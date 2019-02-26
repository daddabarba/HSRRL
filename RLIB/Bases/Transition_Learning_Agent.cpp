//
// Created by daddabarba on 26/02/19.
//

#include "Transition_Learning_Agent.hpp"
#include "../Defs.hpp"

RLIB_BASES::Transition_Learning_Agent::Transition_Learning_Agent(Space_Size state_space_size, Space_Size action_space_size) :
        RL_Agent(state_space_size, action_space_size)
{};

auto RLIB_BASES::Transition_Learning_Agent::learn(RLIB_BASES::Transition transition) -> void{
    get_transition().set(transition);
}

auto RLIB_BASES::Transition_Learning_Agent::get_transition() -> REACT_CONC::Variable<RLIB_BASES::Transition> {
    return this->t;
}