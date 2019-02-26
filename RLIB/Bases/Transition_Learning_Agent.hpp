//
// Created by daddabarba on 26/02/19.
//

#ifndef RLIB_TRANSITION_LEARNING_AGENT_HPP
#define RLIB_TRANSITION_LEARNING_AGENT_HPP

#include "../Defs.hpp"
#include "RL_Agent.hpp"

#include "../../ReactiveCPP/Defs.hpp"
#include "../../ReactiveCPP/Variable.hpp"

RLIB_BASES_START

struct Transition {
    State s_start, s_end;
    Action a;
    double r;
};

class Transition_Learning_Agent : public RL_Agent{

public:
    Transition_Learning_Agent(Space_Size state_space_size, Space_Size action_space_size);

    void learn(Transition);
    REACT_CONC::Variable<Transition> get_transition();

protected:
    REACT_CONC::Variable<Transition> t;

};

RLIB_BASES_END
#endif //RLIB_TRANSITION_LEARNING_AGENT_HPP
