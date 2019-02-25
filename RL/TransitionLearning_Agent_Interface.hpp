//
// Created by daddabarba on 25/02/19.
//

#ifndef HSRRL_TRANSITIONLEARNING_AGENT_INTERFACE_HPP
#define HSRRL_TRANSITIONLEARNING_AGENT_INTERFACE_HPP

#include "Defs.hpp"
#include "RL_Agent_Interface.hpp"

#include "../ReactiveCPP/Defs.hpp"
#include "../ReactiveCPP/Variable.hpp"

RLIB_INTERFACES_START

struct Transition {
    State s_start, s_end;
    Action a;
    double r;
};

class TransitionLearning_Agent_Interface {

    // Getters and Setters

    virtual void learn(Transition) = 0;
    virtual REACT_CONC::Variable<Transition> getTransition() = 0;

};

RLIB_INTERFACES_END


#endif //HSRRL_TRANSITIONLEARNING_AGENT_INTERFACE_HPP
