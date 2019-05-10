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

#include <random>

RLIB_ADDONS_START

// BASE CLASS

class Q_Agent_Addon {
public:

    explicit Q_Agent_Addon(RLIB_BASES::Q_Agent* base);
    explicit Q_Agent_Addon(Q_Agent_Addon* other) : Q_Agent_Addon(other->getBase()) {};

    RLIB_BASES::Q_Agent* getBase();

private:
    RLIB_BASES::Q_Agent* base;
};

// LEARNING METHODS

class Q_Learning : public Q_Agent_Addon {
public:

    explicit Q_Learning(RLIB_BASES::Q_Agent* base);
    explicit Q_Learning(Q_Agent_Addon* other) : Q_Learning(other->getBase()) {};

};

// EXPLORATION METHODS

class Greedy : public Q_Agent_Addon {
public:

    explicit Greedy(RLIB_BASES::Q_Agent* base);
    explicit Greedy(Q_Agent_Addon* other) : Greedy(other->getBase()) {};
};


class E_Greedy : public Q_Agent_Addon {
public:

    explicit E_Greedy(RLIB_BASES::Q_Agent* base, double epsilon);
    explicit E_Greedy(Q_Agent_Addon* other, double epsilon) : E_Greedy(other->getBase(), epsilon) {};

private:

    double epsilon;

    std::random_device rd;
    std::mt19937 m;
    std::uniform_real_distribution<double> dist_prob;
    std::uniform_int_distribution<int> dist_act;
};


class Softmax : public Q_Agent_Addon {
public:

    explicit Softmax(RLIB_BASES::Q_Agent* base, double T);
    explicit Softmax(Q_Agent_Addon* other, double T) : Softmax(other->getBase(), T) {};

private:

    double T;
};

RLIB_ADDONS_END

#endif //RLIB_Q_AGENT_ADDONS_HPP
