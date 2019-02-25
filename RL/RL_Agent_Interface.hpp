//
// Created by daddabarba on 25/02/19.
//

#ifndef RLIB_RL_AGENT_INTERFACE_H
#define RLIB_RL_AGENT_INTERFACE_H

#include "Defs.hpp"

#include "../ReactiveCPP/Defs.hpp"
#include "../ReactiveCPP/Variable.hpp"

#include <armadillo>
#include <random>

RLIB_INTERFACES_START

class RL_Agent_Interface {

public:

    // Overwrite variables definitions
    virtual void init() = 0;

    // RL algorithms
    virtual void setPolicy() = 0;

    // Data retrieval
    virtual Action policy(State) = 0;
    virtual Action policy() = 0;

    // Getters and Setters

    virtual Space_Size get_S_size() = 0;
    virtual Space_Size get_A_size() = 0;

    virtual REACT_CONC::Variable<arma::Mat<double>>* getP() = 0;

    virtual REACT_CONC::Variable<State>* get_current_state() = 0;
    virtual void set_current_state(State) = 0;

};

RLIB_INTERFACES_END
#endif //RLIB_RL_AGENT_INTERFACE_H
