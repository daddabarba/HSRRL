//
// Created by daddabarba on 25/02/19.
//

#ifndef HSRRL_Q_AGENT_INTERFACE_HPP
#define HSRRL_Q_AGENT_INTERFACE_HPP

#include "Defs.hpp"
#include "TransitionLearning_Agent_Interface.hpp"

#include "../ReactiveCPP/Defs.hpp"
#include "../ReactiveCPP/Variable.hpp"

RLIB_INTERFACES_START

class Q_Agent_Interface : public TransitionLearning_Agent_Interface{

    // RL algorithms
    virtual void setQ() = 0;
    virtual void setU();

    // Data retrieval
    virtual double U_fun(State);
    virtual double Q_fun(State, Action);

    // Getters and Setters

    virtual REACT_CONC::Variable<arma::Mat<double>>* getQ() = 0;
    virtual REACT_CONC::Variable<arma::Mat<double>>* getU() = 0;

};

RLIB_INTERFACES_END
#endif //HSRRL_Q_AGENT_INTERFACE_HPP
