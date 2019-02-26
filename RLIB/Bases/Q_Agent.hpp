//
// Created by daddabarba on 26/02/19.
//

#ifndef RLIB_Q_AGENT_HPP
#define RLIB_Q_AGENT_HPP

#include "../Defs.hpp"
#include "Transition_Learning_Agent.hpp"

#include "../../ReactiveCPP/Defs.hpp"
#include "../../ReactiveCPP/Variable.hpp"

#include <armadillo>

RLIB_BASES_START

class Q_Agent : public Transition_Learning_Agent{

    Q_Agent(Space_Size state_space_size, Space_Size action_space_size);

    // Data retrieval
    virtual double U_fun(State);
    virtual double Q_fun(State, Action);

    // Getters and Setters
    REACT_CONC::Variable<arma::Mat<double>>* getQ();
    REACT_CONC::Variable<arma::Mat<double>>* getU();


protected:
    REACT_CONC::Variable<arma::Mat<double>> *Q, *U;

};

RLIB_BASES_END
#endif //RLIB_Q_AGENT_HPP
