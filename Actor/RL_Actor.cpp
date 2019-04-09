//
// Created by daddabarba on 3/21/19.
//

#include "RL_Actor.hpp"

#include "../RLIB/Defs.hpp"

ACTOR::RL_Actor::RL_Actor(std::string sockets_path) :
        pi(nullptr),
        reward_socket(sockets_path + "_r"),
        state_socket(sockets_path + "_s"),
        action_socket(sockets_path + "_a"),
        log_socket(sockets_path + "_log")
{
    reward_socket.start_connection();
    state_socket.start_connection();
    action_socket.start_connection();
    log_socket.start_connection();

    state_socket >> &this->num_states;
    action_socket >> &this->num_actions;
};

auto ACTOR::RL_Actor::act() -> void {
    this->act(this->get_next_action(), this->get_next_state());
}

auto ACTOR::RL_Actor::act(Action*a, State* s) -> void {
    this->action_socket << (int)(this->getAction(a, s));
}

auto ACTOR::RL_Actor::getAction() -> Action {
    return this->getAction(this->get_next_action(), this->get_next_state());
}

auto ACTOR::RL_Actor::getAction(Action* a, State* s) -> Action {

    if (this->getPi() != nullptr)
        return *a = this->getPi()->policy((State)(this->state_socket.reset_buffer()<<1>>(int*)s));

    return 0;
}

auto ACTOR::RL_Actor::setPi(RLIB_BASES::RL_Agent* pi) -> void {
    this->pi = pi;
}

auto ACTOR::RL_Actor::getPi() -> RLIB_BASES::RL_Agent* {
    return this->pi;
}

auto ACTOR::RL_Actor::get_num_actions() -> Space_Size {
    return this->num_actions;
}

auto ACTOR::RL_Actor::get_num_states() -> Space_Size {
    return this->num_states;
}