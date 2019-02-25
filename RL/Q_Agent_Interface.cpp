//
// Created by daddabarba on 25/02/19.
//

#include "Q_Agent_Interface.hpp"
#include "Defs.hpp"

#include "../ReactiveCPP/Defs.hpp"
#include "../ReactiveCPP/Operator.hpp"

auto RLIB_INTERFACES::Q_Agent_Interface::setU() -> void {
    REACT_CONC::make_operator_set([](arma::Mat<double> Q, arma::Mat<double> Pi) -> arma::Mat<double>{
        return Q*Pi;
    }, getU(), getQ(), getP());
}

auto RLIB_INTERFACES::Q_Agent_Interface::U_fun(State state) -> double {
    return ((arma::Mat<double>)*getU()).at((arma::uword)state);
}

auto RLIB_INTERFACES::Q_Agent_Interface::Q_fun(State state, Action action) -> double {
    return ((arma::Mat<double>)*getQ()).at((arma::uword)(state + action*get_S_size()));
}