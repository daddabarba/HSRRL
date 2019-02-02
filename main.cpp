#include <iostream>

#include "ReactiveCPP/Defs.h"

#include "ReactiveCPP/InputNode.h"
#include "ReactiveCPP/VarNode.h"

int f(int n){
    return 2*(n);
}

int main() {

    REACT_CONC::InputNode<int> A(2);
    REACT_CONC::InputNode<int> B(3);

    typedef int (*fptr)(int,int);
    REACT_CONC::VarNode<fptr,int,int> X([](int a, int b)->int{
        return a+b;
    }, REACT_CONC::ANY, std::move(A), std::move(B));


    std::cout<<"a: " << A.get_value()<<" + b: " <<B.get_value() << " = x: " << X.get_value()<<std::endl;
    A.set(4);
    std::cout<<"a: " << A.get_value()<<" + b: " <<B.get_value() << " = x: " << X.get_value()<<std::endl;


    return 0;
}