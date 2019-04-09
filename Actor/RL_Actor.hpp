//
// Created by daddabarba on 3/21/19.
//

#ifndef HSRRL_ACTOR_HPP
#define HSRRL_ACTOR_HPP

#include "Defs.hpp"

#include "../RLIB/Defs.hpp"
#include "../RLIB/Bases/RL_Agent.hpp"

#include "../CPP_SocketWrapper/cppsockets/SocketClient.h"

#include <string>

ACTOR_START

class RL_Actor {
public:

    explicit RL_Actor(std::string sockets_path);

    virtual void start() = 0;

    void act();
    Action getAction();

    virtual void setPi(RLIB_BASES::RL_Agent* pi);
    virtual RLIB_BASES::RL_Agent* getPi();

    Space_Size get_num_states();
    Space_Size get_num_actions();

    virtual Action* get_next_action() = 0;
    virtual State* get_next_state() = 0;

private:
    RLIB_BASES::RL_Agent *pi;
    Space_Size num_states, num_actions;

protected:
    void act(Action* a, State* s);
    Action getAction(Action* a, State* s);

    skt::SocketClient reward_socket, state_socket, action_socket, log_socket;
};

ACTOR_END

#endif //HSRRL_ACTOR_HPP
