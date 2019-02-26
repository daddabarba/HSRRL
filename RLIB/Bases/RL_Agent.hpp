//
// Created by daddabarba on 26/02/19.
//

#ifndef RLIB_RL_AGENT_HPP
#define RLIB_RL_AGENT_HPP

#include "../Defs.hpp"

#include "../../ReactiveCPP/Defs.hpp"
#include "../../ReactiveCPP/Variable.hpp"

#include <armadillo>
#include <random>

RLIB_BASES_START

class RL_Agent {

public:

    RL_Agent(Space_Size state_space_size, Space_Size action_space_size);

    // Data retrieval
    Action policy(State);
    Action policy();

    // Getters and Setters

    Space_Size get_S_size();
    Space_Size get_A_size();

    REACT_CONC::Variable<arma::Mat<double>>* getP();

    REACT_CONC::Variable<State>* get_current_state();
    void set_current_state(State);

    std::mt19937& get_generator();

protected:

    Space_Size state_space_size, action_space_size;

    REACT_CONC::Variable<arma::Mat<double>> *P;
    REACT_CONC::Variable<State> *current_state;

    std::mt19937 generator;
};

RLIB_BASES_END
#endif //RLIB_RL_AGENT_HPP
