#include <iostream>

#include "ReactiveCPP/Defs.h"

#include "ReactiveCPP/InputNode.h"
#include "ReactiveCPP/VarNode.h"

int main() {

    REACT_CONC::InputNode<int> A;
    REACT_CONC::InputNode<int> B;

    typedef int (*fptr)(int,int);
    REACT_CONC::VarNode<fptr,int,int>([](int a, int b)->int{
        std::cout<<"a: " << a<<"\tb: " <<b<<std::endl;
        return a+b;
    }, REACT_CONC::ANY, std::move(A), std::move(B));

    return 0;
}