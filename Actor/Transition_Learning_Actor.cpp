//
// Created by daddabarba on 3/24/19.
//

#include "Transition_Learning_Actor.hpp"
#include "Defs.hpp"

#include <unistd.h>

ACTOR::Transition_Learning_Actor::Transition_Learning_Actor(std::string sockets_path) :
    ACTOR::RL_Actor(sockets_path),
    t({0,0,0,0})
{};

auto ACTOR::Transition_Learning_Actor::start() -> void {

    if(this->getPi() == nullptr)
        return;

    // Get first state and perform first action
    this->act(&((this->t).a),&((this->t).s_start));

    // Loop
    do{

        // Get reward
        this->reward_socket.reset_buffer()<<1>>this->get_next_reward();
        this->log_socket << *(this->get_next_reward());
        this->act();

        this->getPi()->learn(this->t);

        this->t.s_start = this->t.s_end;
        this->t.a = this->next_a;

        usleep(500);

    }while( this->t.s_end < this->get_num_states() );

}

auto ACTOR::Transition_Learning_Actor::setPi(RLIB_BASES::Transition_Learning_Agent *pi) -> void {
    this->pi = pi;
}

auto ACTOR::Transition_Learning_Actor::getPi() -> RLIB_BASES::Transition_Learning_Agent* {
    return this->pi;
}

auto ACTOR::Transition_Learning_Actor::get_next_state() -> State* {
    return &((this->t).s_end);
}

auto ACTOR::Transition_Learning_Actor::get_next_action() -> Action* {
    return &this->next_a;
}

auto ACTOR::Transition_Learning_Actor::get_next_reward() -> double* {
    return &((this->t).r);
}