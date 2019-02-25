//
// Created by daddabarba on 25/02/19.
//

#ifndef RLIB_Q_AGENT_HPP
#define RLIB_Q_AGENT_HPP

#include "Defs.hpp"

#include "TransitionLearning_Agent.hpp"
#include "ModelFree_Agent.hpp"

#include "../ReactiveCPP/Defs.hpp"
#include "../ReactiveCPP/Variable.hpp"

#include <armadillo>

RLIB_INTERFACES_START

class Q_Agent : public TransitionLearning_Agent, ModelFree_Agent{

public:

    Q_Agent(Space_Size state_space_size, Space_Size action_space_size);

    // Data retrieval
    //double Q_fun(State, Action);
    double U_fun(State);

    // Getters and Setters

    arma::Mat<double> getQ();
    arma::Mat<double> getU();

protected:

    REACT_CONC::Variable<arma::Mat<double>> Q, U;

};

RLIB_INTERFACES_END

#endif //RLIB_Q_AGENT_HPP
