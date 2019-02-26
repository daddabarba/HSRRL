//
// Created by daddabarba on 26/02/19.
//

#include "Q_Agent.hpp"
#include "../Defs.hpp"

#include "../../ReactiveCPP/Defs.hpp"
#include "../../ReactiveCPP/Operator.hpp"

RLIB_BASES::Q_Agent::Q_Agent(Space_Size state_space_size, Space_Size action_space_size) :
        Transition_Learning_Agent(state_space_size, action_space_size),
        Q(REACT_CONC::make_variable<arma::Mat<double>>(arma::Mat<double>((arma::uword)state_space_size, (arma::uword)action_space_size))),
        U(REACT_CONC::make_variable<arma::Mat<double>>(arma::Mat<double>(state_space_size, 1)))
{

    // Set up U as the expected value of Q, with respect to Pi
    REACT_CONC::make_operator_set([](arma::Mat<double> Q, arma::Mat<double> Pi) -> arma::Mat<double>{
        return Q*Pi;
    }, getU(), getQ(), getP());

}

auto RLIB_BASES::Q_Agent::U_fun(State state) -> double {
    return ((arma::Mat<double>)*getU()).at((arma::uword)state);
}

auto RLIB_BASES::Q_Agent::Q_fun(State state, Action action) -> double {
    return ((arma::Mat<double>)*getQ()).at(state + action*get_S_size());
}

auto RLIB_BASES::Q_Agent::getQ() -> REACT_CONC::Variable<arma::Mat<double>>*{
    return this->Q;
}

auto RLIB_BASES::Q_Agent::getU() -> REACT_CONC::Variable<arma::Mat<double>>*{
    return this->U;
}