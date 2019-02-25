//
// Created by daddabarba on 25/02/19.
//

#include "ModelFree_Agent.hpp"
#include "Defs.hpp"

RLIB_INTERFACES::ModelFree_Agent::ModelFree_Agent(Space_Size state_space_size, Space_Size action_space_size) :
        RL_Agent(state_space_size, action_space_size)
{};
