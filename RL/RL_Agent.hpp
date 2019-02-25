//
// Created by daddabarba on 25/02/19.
//

#ifndef RLIB_RL_AGENT_H
#define RLIB_RL_AGENT_H

#include "Defs.hpp"
#include "RL_Agent_Interface.hpp"

#include "../ReactiveCPP/Defs.hpp"
#include "../ReactiveCPP/Variable.hpp"

#include <armadillo>
#include <random>

RLIB_ABSTRACT_START

class RL_Agent : public RLIB_INTERFACES::RL_Agent_Interface{

public:

    RL_Agent(Space_Size state_space_size, Space_Size action_space_size);

    // Getters and Setters

    Space_Size get_S_size() override;
    Space_Size get_A_size() override;

    REACT_CONC::Variable<arma::Mat<double>>* getP() override;

    REACT_CONC::Variable<State>* get_current_state() override;
    void set_current_state(State) override;

    std::mt19937& get_generator() override;


protected:

    Space_Size state_space_size, action_space_size;

    REACT_CONC::Variable<arma::Mat<double>> *P;
    REACT_CONC::Variable<State> *current_state;

    std::mt19937 generator;
};

RLIB_ABSTRACT_END
#endif //RLIB_RL_AGENT_H
