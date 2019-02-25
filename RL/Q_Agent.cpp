//
// Created by daddabarba on 25/02/19.
//

#include "Q_Agent.hpp"
#include "Defs.hpp"

RLIB_INTERFACES::Q_Agent::Q_Agent(Space_Size state_space_size, Space_Size action_space_size) :
        TransitionLearning_Agent(state_space_size, action_space_size),
        ModelFree_Agent(state_space_size, action_space_size),
        Q(new arma::Mat<double>((arma::uword)state_space_size, (arma::uword)action_space_size)),
        U(new arma::Mat<double>(1, (arma::uword)state_space_size))
{}

auto RLIB_INTERFACES::Q_Agent::U_fun(State state) -> double {
    return ((arma::Mat<double>)this->Q).at((arma::uword)state);
}

auto RLIB_INTERFACES::Q_Agent::Q_fun(State state, Action action) -> double {
    reactcpp::((arma::Mat<double>)this->Q).at((arma::uword)(state + action*this->state_space_size));
}

auto RLIB_INTERFACES::Q_Agent::getQ() -> arma::Mat<double>{
    return (arma::Mat<double>)(this->Q);
}

auto RLIB_INTERFACES::Q_Agent::getU() -> arma::Mat<double>{
    return (arma::Mat<double>)(this->U);
}