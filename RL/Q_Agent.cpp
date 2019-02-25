//
// Created by daddabarba on 25/02/19.
//

#include "Q_Agent.hpp"
#include "Defs.hpp"

RLIB_ABSTRACT::Q_Agent::Q_Agent(Space_Size state_space_size, Space_Size action_space_size) :
        TransitionLearning_Agent(state_space_size, action_space_size),
        Q(new arma::Mat<double>((arma::uword)state_space_size, (arma::uword)action_space_size)),
        U(new arma::Mat<double>(1, (arma::uword)state_space_size))
{}

auto RLIB_ABSTRACT::Q_Agent::U_fun(State state) -> double {
    return ((arma::Mat<double>)getU()).at((arma::uword)state);
}

auto RLIB_ABSTRACT::Q_Agent::Q_fun(State state, Action action) -> double {
    reactcpp::((arma::Mat<double>)getQ()).at((arma::uword)(state + action*get_S_size()));
}

auto RLIB_ABSTRACT::Q_Agent::getQ() -> REACT_CONC::Variable<arma::Mat<double>>{
    return this->Q;
}

auto RLIB_ABSTRACT::Q_Agent::getU() -> REACT_CONC::Variable<arma::Mat<double>>{
    return this->U;
}