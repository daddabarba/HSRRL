//
// Created by daddabarba on 25/02/19.
//

#ifndef RLIB_TRANSITIONLEARNING_AGENT_H
#define RLIB_TRANSITIONLEARNING_AGENT_H

#include "Defs.hpp"

#include "RL_Agent.hpp"

#include "../ReactiveCPP/Defs.hpp"
#include "../ReactiveCPP/Variable.hpp"

RLIB_INTERFACES_START

struct Transition {
    State s_start, s_end;
    Action a;
    double r;
};

class TransitionLearning_Agent : public RL_Agent{

public:

    TransitionLearning_Agent(Space_Size state_space_size, Space_Size action_space_size);

    // Getters and Setters

    void learn(Transition);
    Transition getTransition();

protected:

    REACT_CONC::Variable<Transition> t;
};

RLIB_INTERFACES_END

#endif //RLIB_TRANSITIONLEARNING_AGENT_H
