//
// Created by daddabarba on 25/02/19.
//

#ifndef RLIB_MODELFREE_AGENT_HPP
#define RLIB_MODELFREE_AGENT_HPP

#include "Defs.hpp"
#include "RL_Agent.hpp"

RLIB_INTERFACES_START

class ModelFree_Agent : public RL_Agent {

public:

    explicit ModelFree_Agent(int state_space_size);

};

RLIB_INTERFACES_END


#endif //HSRRL_MODELFREE_AGENT_HPP
