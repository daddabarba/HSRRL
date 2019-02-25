//
// Created by daddabarba on 25/02/19.
//

#ifndef RLIB_RL_AGENT_H
#define RLIB_RL_AGENT_H

#include "Defs.hpp"

#include <armadillo>
#include <random>

RLIB_INTERFACES_START

class RL_Agent {

public:

    RL_Agent(int state_space_size);

    // RL algorithms
    virtual void setPolicy() = 0;

    // Data retrieval
    Action policy(State);


protected:
    arma::Mat<double> P;
};

RLIB_INTERFACES_END
#endif //RLIB_RL_AGENT_H
