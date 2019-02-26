//
// Created by daddabarba on 25/02/19.
//

#include "RL_Agent_Interface.hpp"
#include "../Defs.hpp"

auto RLIB_INTERFACES::RL_Agent_Interface::init() -> void{
    setPolicy();
}

auto RLIB_INTERFACES::RL_Agent_Interface::policy(State state) -> Action {
    get_current_state()->set(state);
    return this->policy();
}

auto RLIB_INTERFACES::RL_Agent_Interface::policy() -> Action {
    auto M = (arma::Mat<double>)*getP();
    return ((Action)std::discrete_distribution<int>(
            M.size(),
            0.0,
            1.0,
            [M](double i) -> double{
                return M[(unsigned int)ceil(i*M.size()-0.5)];
            }
    )(get_generator()));
}
