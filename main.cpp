#include <iostream>

#include "ReactiveCPP/Defs.h"

#include "ReactiveCPP/InputNode.h"
#include "ReactiveCPP/VarNode.h"

int f(int n){
    return 2*(n);
}

int main() {

    auto A = REACT_CONC::make_input(2);
    auto B = REACT_CONC::make_input(3);

    auto X = REACT_CONC::make_var(
            [](int a, int b)->int{
                return a+b;
            },
            REACT_CONC::ANY,
            A, B
    );


    std::cout<<"a: " << A->get_value()<<" + b: " <<B->get_value() << " = x: " << X->get_value()<<std::endl;
    A->set(4);
    std::cout<<"a: " << A->get_value()<<" + b: " <<B->get_value() << " = x: " << X->get_value()<<std::endl;


    return 0;
}