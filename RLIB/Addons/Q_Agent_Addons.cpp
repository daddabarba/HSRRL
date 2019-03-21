//
// Created by daddabarba on 26/02/19.
//

#include "Q_Agent_Addons.hpp"

auto add_q_learning(RLIB_BASES::Q_Agent& q_agent) -> RLIB_BASES::Q_Agent& {

    REACT_CONC::make_operator_update(
            [&q_agent](arma::Mat<double>* Q, RLIB_BASES::Transition t) -> void{

                auto mem = q_agent.Q_fun(t.s_start, t.a);
                auto approximation = t.r + q_agent.get_gamma()*q_agent.U_fun(t.s_end);

                Q->at(t.s_start + q_agent.get_S_size()*t.a) = (1-q_agent.get_alpha())*mem + q_agent.get_alpha()*approximation;
            },
            q_agent.getQ(),
            q_agent.get_transition()
    );

    return q_agent;
}

// EXPLORATION METHODS

auto add_greddy(RLIB_BASES::Q_Agent& q_agent) -> RLIB_BASES::Q_Agent& {

    REACT_CONC::make_operator_update(
            [](arma::Mat<double>* P, arma::Mat<double> Q, State s) -> void{
                P->zeros();
                P->at(Q.row(s).index_max()) = 1.0;
            },
            q_agent.getP(),
            q_agent.getQ(),
            q_agent.get_current_state()
    );

    return q_agent;
}

