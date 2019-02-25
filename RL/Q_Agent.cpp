//
// Created by daddabarba on 25/02/19.
//

#include "Q_Agent.hpp"
#include "Defs.hpp"

RLIB_ABSTRACT::Q_Agent::Q_Agent(Space_Size state_space_size, Space_Size action_space_size) :
        TransitionLearning_Agent(state_space_size, action_space_size),
        Q(REACT_CONC::make_variable<arma::Mat<double>>(arma::Mat<double>((arma::uword)state_space_size, (arma::uword)action_space_size))),
        U(REACT_CONC::make_variable<arma::Mat<double>>(arma::Mat<double>(state_space_size, 1)))
{}

auto RLIB_ABSTRACT::Q_Agent::getQ() -> REACT_CONC::Variable<arma::Mat<double>>*{
    return this->Q;
}

auto RLIB_ABSTRACT::Q_Agent::getU() -> REACT_CONC::Variable<arma::Mat<double>>*{
    return this->U;
}