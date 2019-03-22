//
// Created by daddabarba on 3/22/19.
//

#ifndef ACTOR_TRANSITION_LEARNING_ACTOR_HPP
#define ACTOR_TRANSITION_LEARNING_ACTOR_HPP

#include "Defs.hpp"
#include "RL_Actor.hpp"

#include "../RLIB/Defs.hpp"
#include "../RLIB/Bases/Transition_Learning_Agent.hpp"

ACTOR_START

class Transition_Learning_Actor : public RL_Actor {

public:

    explicit Transition_Learning_Actor(RLIB_BASES::Transition_Learning_Agent* pi);

    Action act(State s) override;
    void learn(Reward r, State s);

    RLIB_BASES::Transition_Learning_Agent* getPi() override;
    State getState();
    Action getAction();

private:
    RLIB_BASES::Transition_Learning_Agent* pi;
    State s;
    Action a;
};

ACTOR_END

#endif //ACTOR_TRANSITION_LEARNING_ACTOR_HPP
