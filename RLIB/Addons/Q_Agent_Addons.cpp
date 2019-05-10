//
// Created by daddabarba on 26/02/19.
//

#include "Q_Agent_Addons.hpp"

#include "../../ReactiveCPP/Defs.hpp"
#include "../Defs.hpp"

// BASE CLASS

RLIB_ADDONS::Q_Agent_Addon::Q_Agent_Addon(RLIB_BASES::Q_Agent* base) :
        base(base)
{};

auto RLIB_ADDONS::Q_Agent_Addon::getBase() -> RLIB_BASES::Q_Agent* {
    return this->base;
}

// LEARNING

RLIB_ADDONS::Q_Learning::Q_Learning(RLIB_BASES::Q_Agent* base) :
        RLIB_ADDONS::Q_Agent_Addon(base)
{
    REACT_CONC::make_operator_set(
            [q_agent=getBase()](arma::Mat<double> Q, RLIB_BASES::Transition t) -> arma::Mat<double> {

                auto mem = q_agent->Q_fun(t.s_start, t.a);
                auto approximation = t.r + q_agent->get_gamma()*q_agent->U_fun(t.s_end);

                Q.at(t.s_start + q_agent->get_S_size()*t.a) = (1-q_agent->get_alpha())*mem + q_agent->get_alpha()*approximation;

                return Q;
            },
            getBase()->getQ(),
            REACT_CONC::make_parameter(getBase()->getQ()),
            getBase()->get_transition()
    );
};

// EXPLORATION METHODS

RLIB_ADDONS::Greedy::Greedy(RLIB_BASES::Q_Agent* base) :
        RLIB_ADDONS::Q_Agent_Addon(base)
{
    REACT_CONC::make_operator_set(
            [](arma::Mat<double> P, arma::Mat<double> Q, State s) -> arma::Mat<double> {

                P.zeros();

                arma::uword index_max;
                Q.row(s).max(index_max);

                P.at(index_max) = 1.0;

                return P;
            },
            getBase()->getP(),
            REACT_CONC::make_parameter(getBase()->getP()),
            getBase()->getQ(),
            getBase()->get_current_state()
    );
};


RLIB_ADDONS::E_Greedy::E_Greedy(RLIB_BASES::Q_Agent* base, double epsilon) :
        RLIB_ADDONS::Q_Agent_Addon(base),
        epsilon(epsilon),
        m(rd()),
        dist_act(0, base->get_A_size())
{
    REACT_CONC::make_operator_set(
            [this](arma::Mat<double> P, arma::Mat<double> Q, State s) -> arma::Mat<double> {

                P.zeros();

                auto prob = this->dist_prob(this->m);

                if (prob<this->epsilon) {
                    P.at(this->dist_act(this->m)) = 1.0;
                } else {
                    arma::uword index_max;
                    Q.row(s).max(index_max);

                    P.at(index_max) = 1.0;
                }

                return P;
            },
            getBase()->getP(),
            REACT_CONC::make_parameter(getBase()->getP()),
            getBase()->getQ(),
            getBase()->get_current_state()
    );
};


RLIB_ADDONS::Softmax::Softmax(RLIB_BASES::Q_Agent* base, double T) :
        RLIB_ADDONS::Q_Agent_Addon(base),
        T(T)
{
    REACT_CONC::make_operator_set(
            [this](arma::Mat<double> P, arma::Mat<double> Q, State s) -> arma::Mat<double> {

                auto vals = Q.row(s)/(this->T);
                auto exps = arma::exp(vals);
                auto sum = arma::sum(exps);

                auto ret =  exps/sum;

                return ret;
            },
            getBase()->getP(),
            REACT_CONC::make_parameter(getBase()->getP()),
            getBase()->getQ(),
            getBase()->get_current_state()
    );
};

