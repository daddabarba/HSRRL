//
// Created by daddabarba on 25/02/19.
//

#include "TransitionLearning_Agent_Interface.hpp"
#include "Defs.hpp"

auto RLIB_INTERFACES::TransitionLearning_Agent_Interface::learn(RLIB_INTERFACES::Transition transition) -> void{
    getTransition().set(transition);
}