//
// Created by daddabarba on 3/24/19.
//

#include "Actor/Defs.hpp"
#include "Actor/Transition_Learning_Actor.hpp"

#include "RLIB/Defs.hpp"
#include "RLIB/Bases/Q_Agent.hpp"
#include "RLIB/Addons/Q_Agent_Addons.hpp"

#include <string>

int main(int argc, char **argv){

    if (argc < 4)
        exit(EXIT_FAILURE);

    auto agent = new ACTOR::Transition_Learning_Actor(argv[1]);

    agent->setPi(
            (new RLIB_ADDONS::Q_Learning(
                    new RLIB_ADDONS::Greedy(
                            new RLIB_BASES::Q_Agent(
                                    agent->get_num_states(),
                                    agent->get_num_actions(),
                                    std::stod(argv[2]),
                                    std::stod(argv[3])
                            )
                    )
            ))->getBase()
    );

    agent->start();

    exit(EXIT_SUCCESS);
}