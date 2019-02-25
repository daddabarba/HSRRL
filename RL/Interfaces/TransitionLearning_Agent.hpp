//
// Created by daddabarba on 25/02/19.
//

#ifndef RLIB_TRANSITIONLEARNING_AGENT_H
#define RLIB_TRANSITIONLEARNING_AGENT_H

#include "../Defs.hpp"

#include "RL_Agent.hpp"

#include "TransitionLearning_Agent_Interface.hpp"

#include "../../ReactiveCPP/Defs.hpp"
#include "../../ReactiveCPP/Variable.hpp"

RLIB_ABSTRACT_START

class TransitionLearning_Agent : public RL_Agent, RLIB_INTERFACES::TransitionLearning_Agent_Interface{

public:

    TransitionLearning_Agent(Space_Size state_space_size, Space_Size action_space_size);

    // Getters and Setters

    REACT_CONC::Variable<RLIB_INTERFACES::Transition> getTransition() override;

    // Inherited getters
    using RL_Agent::getP;
    using RL_Agent::get_current_state;
    using RL_Agent::set_current_state;
    using RL_Agent::get_S_size;
    using RL_Agent::get_A_size;

protected:

    REACT_CONC::Variable<RLIB_INTERFACES::Transition> t;
};

RLIB_ABSTRACT_END

#endif //RLIB_TRANSITIONLEARNING_AGENT_H
