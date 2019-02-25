//
// Created by daddabarba on 25/02/19.
//

#ifndef HSRRL_Q_AGENT_INTERFACE_HPP
#define HSRRL_Q_AGENT_INTERFACE_HPP

#include "Defs.hpp"
#include "TransitionLearning_Agent_Interface.hpp"

RLIB_INTERFACES_START

class Q_Agent_Interface : public TransitionLearning_Agent_Interface {

    // Data retrieval
    virtual double U_fun(State) = 0;
    virtual double Q_fun(State, Action) = 0;

    // Getters and Setters

    virtual arma::Mat<double> getQ() = 0;
    virtual arma::Mat<double> getU() = 0;

};

RLIB_INTERFACES_END
#endif //HSRRL_Q_AGENT_INTERFACE_HPP
