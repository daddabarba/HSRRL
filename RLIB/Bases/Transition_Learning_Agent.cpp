//
// Created by daddabarba on 26/02/19.
//

#include "Transition_Learning_Agent.hpp"
#include "../Defs.hpp"

RLIB_BASES::Transition::Transition(State s_start, State s_end, Action a, double r) :
    s_start(s_start),
    s_end(s_end),
    a(a),
    r(r)
{};

RLIB_BASES::Transition_Learning_Agent::Transition_Learning_Agent(Space_Size state_space_size, Space_Size action_space_size, double alpha, double gamma) :
        RL_Agent(state_space_size, action_space_size, alpha, gamma)
{};

auto RLIB_BASES::Transition_Learning_Agent::learn(RLIB_BASES::Transition transition) -> void{
    get_transition()->set(transition);
}

auto RLIB_BASES::Transition_Learning_Agent::get_transition() -> REACT_CONC::Variable<RLIB_BASES::Transition>* {
    return this->t;
}