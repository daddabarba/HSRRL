//
// Created by daddabarba on 3/21/19.
//

#ifndef HSRRL_ACTOR_HPP
#define HSRRL_ACTOR_HPP

#include "Defs.hpp"

#include "../RLIB/Defs.hpp"
#include "../RLIB/Bases/RL_Agent.hpp"

ACTOR_START

class RL_Actor {
public:

    explicit RL_Actor(RLIB_BASES::RL_Agent *pi);

    virtual Action act(State s);
    virtual RLIB_BASES::RL_Agent* getPi();

private:
    RLIB_BASES::RL_Agent *pi;
};

ACTOR_END

#endif //HSRRL_ACTOR_HPP
