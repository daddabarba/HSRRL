//
// Created by daddabarba on 25/02/19.
//

#ifndef RLIB_Q_AGENT_HPP
#define RLIB_Q_AGENT_HPP

#include "Defs.hpp"

#include "TransitionLearning_Agent.hpp"
#include "Q_Agent_Interface.hpp"

#include "../ReactiveCPP/Defs.hpp"
#include "../ReactiveCPP/Variable.hpp"

#include <armadillo>

RLIB_ABSTRACT_START

class Q_Agent : public TransitionLearning_Agent, RLIB_INTERFACES::Q_Agent_Interface{

public:

    Q_Agent(Space_Size state_space_size, Space_Size action_space_size);

    //RL algorithms
    void setU() override;

    // Data retrieval
    double U_fun(State) override;
    double Q_fun(State, Action) override;

    // Getters and Setters

    REACT_CONC::Variable<arma::Mat<double>>* getQ() override;
    REACT_CONC::Variable<arma::Mat<double>>* getU() override;

protected:

    REACT_CONC::Variable<arma::Mat<double>> *Q, *U;

};

RLIB_ABSTRACT_END

#endif //RLIB_Q_AGENT_HPP
