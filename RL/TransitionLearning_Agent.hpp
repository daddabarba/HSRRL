//
// Created by daddabarba on 25/02/19.
//

#ifndef RLIB_TRANSITIONLEARNING_AGENT_H
#define RLIB_TRANSITIONLEARNING_AGENT_H

#include "Defs.hpp"

#include "RL_Agent.hpp"

#include "TransitionLearning_Agent_Interface.hpp"

#include "../ReactiveCPP/Defs.hpp"
#include "../ReactiveCPP/Variable.hpp"

RLIB_ABSTRACT_START

class TransitionLearning_Agent : public RL_Agent, RLIB_INTERFACES::TransitionLearning_Agent_Interface{

public:

    TransitionLearning_Agent(Space_Size state_space_size, Space_Size action_space_size);

    // Getters and Setters

    void learn(RLIB_INTERFACES::Transition) override;
    RLIB_INTERFACES::Transition getTransition() override;

protected:

    REACT_CONC::Variable<RLIB_INTERFACES::Transition> t;
};

RLIB_ABSTRACT_END

#endif //RLIB_TRANSITIONLEARNING_AGENT_H
