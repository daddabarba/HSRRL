//
// Created by daddabarba on 26/02/19.
//

#ifndef RLIB_Q_AGENT_ADDONS_HPP
#define RLIB_Q_AGENT_ADDONS_HPP

#include "../Defs.hpp"
#include "../Bases/Q_Agent.hpp"

#include "../../ReactiveCPP/Defs.hpp"
#include "../../ReactiveCPP/Variable.hpp"
#include "../../ReactiveCPP/ParameterNode.hpp"
#include "../../ReactiveCPP/Operator.hpp"

RLIB_ADDONS_START

// LEARNING METHODS

auto add_q_learning(RLIB_BASES::Q_Agent& q_agent) -> RLIB_BASES::Q_Agent&;

// EXPLORATION METHODS

auto add_greddy(RLIB_BASES::Q_Agent& q_agent) -> RLIB_BASES::Q_Agent&;

RLIB_ADDONS_END

#endif //RLIB_Q_AGENT_ADDONS_HPP
