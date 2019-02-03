#include <iostream>

#include "ReactiveCPP/Defs.h"

#include "ReactiveCPP/InputNode.h"
#include "ReactiveCPP/VarNode.h"
#include "ReactiveCPP/ParameterNode.h"


int main() {

    int bVal = 3;

    auto A = REACT_CONC::make_input<int>(2);
    auto B = REACT_CONC::make_input(&bVal);
    auto C = REACT_CONC::make_input<int>(1);

    auto X = REACT_CONC::make_var(
            [](int a, int b, int c)->int{
                return (a+b)*c;
            },
            REACT_CONC::ANY,
            A, B, REACT_CONC::make_parameter(*C)
    );



    std::cout<<"(a: " << A->get_value()<<" + b: " <<B->get_value() << ") * c: " << C->get_value()<< " = x: " << X->get_value()<<std::endl;
    A->set(4);
    std::cout<<"(a: " << A->get_value()<<" + b: " <<B->get_value() << ") * c: " << C->get_value()<< " = x: " << X->get_value()<<std::endl;
    C->set(2);
    std::cout<<"(a: " << A->get_value()<<" + b: " <<B->get_value() << ") * c: " << C->get_value()<< " = x: " << X->get_value()<<std::endl;
    A->set(2);
    std::cout<<"(a: " << A->get_value()<<" + b: " <<B->get_value() << ") * c: " << C->get_value()<< " = x: " << X->get_value()<<std::endl;



    return 0;
}