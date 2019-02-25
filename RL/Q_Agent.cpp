//
// Created by daddabarba on 25/02/19.
//

#include "Q_Agent.hpp"
#include "Defs.hpp"

RLIB_INTERFACES::Q_Agent::Q_Agent(int state_space_size, int action_space_size) :
        TransitionLearning_Agent(state_space_size),
        ModelFree_Agent(state_space_size),
        Q(new arma::Mat<double>((arma::uword)state_space_size, (arma::uword)action_space_size)),
        U(new arma::Mat<double>(1, (arma::uword)state_space_size))
{}

auto RLIB_INTERFACES::Q_Agent::getQ() -> arma::Mat<double>{
    return (arma::Mat<double>)(this->Q);
}

auto RLIB_INTERFACES::Q_Agent::getU() -> arma::Mat<double>{
    return (arma::Mat<double>)(this->U);
}