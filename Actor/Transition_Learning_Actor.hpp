//
// Created by daddabarba on 3/24/19.
//

#ifndef HSRRL_TRANSITION_LEARNING_ACTOR_HPP
#define HSRRL_TRANSITION_LEARNING_ACTOR_HPP

#include "Defs.hpp"
#include "RL_Actor.hpp"

#include "../RLIB/Defs.hpp"
#include "../RLIB/Bases/Transition_Learning_Agent.hpp"

ACTOR_START

class Transition_Learning_Actor : public RL_Actor {

public:

    explicit Transition_Learning_Actor(std::string sockets_path);

    void start() override;

    void setPi(RLIB_BASES::Transition_Learning_Agent* pi);
    RLIB_BASES::Transition_Learning_Agent* getPi();

    Action* get_next_action() override;
    State* get_next_state() override;
    virtual double* get_next_reward();

private:

    RLIB_BASES::Transition_Learning_Agent *pi;

    RLIB_BASES::Transition t;
    Action next_a;
};

ACTOR_END
#endif //HSRRL_TRANSITION_LEARNING_ACTOR_HPP
