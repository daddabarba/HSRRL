#include <iostream>
#include <armadillo>

#include "ReactiveCPP/Defs.h"

#include "ReactiveCPP/InputNode.h"
#include "ReactiveCPP/VarNode.h"
#include "ReactiveCPP/ParameterNode.h"


int main() {

    auto A = REACT_CONC::make_input<arma::Mat<double>>(arma::randu(3, 3)*2 -1);
    auto B = REACT_CONC::make_input<arma::Mat<double>>(arma::ones(3, 3)*2);
    auto C = REACT_CONC::make_input<arma::Mat<double>>(arma::ones(3, 3)*3);

    std::cout << "Setting X"<<std::endl;

    auto X = REACT_CONC::make_var(
            [](arma::Mat<double> a, arma::Mat<double> b, arma::Mat<double> c)->arma::Mat<double>{
                return (a*b)+c;
            },
            REACT_CONC::ANY,
            A, B, REACT_CONC::make_parameter(*C)
    );

    std::cout << "Armadillo test"<<std::endl;

    std::cout<<"(a: \n" << A->get_value()<<"\n + b: \n" <<B->get_value() << "\n) * c: \n" << C->get_value()<< "\n = x: \n" << X->get_value()<< "\n\n" << std::endl;
    A->set(A->get_value().for_each([](arma::mat::elem_type& val)->void{  if(val<0){val = 0;}}));
    A->set(A->get_value()*2);
    std::cout<<"(a: \n" << A->get_value()<<"\n + b: \n" <<B->get_value() << "\n) * c: \n" << C->get_value()<< "\n = x: \n" << X->get_value()<< "\n\n" << std::endl;
    C->set(C->get_value()/3);
    std::cout<<"(a: \n" << A->get_value()<<"\n + b: \n" <<B->get_value() << "\n) * c: \n" << C->get_value()<< "\n = x: \n" << X->get_value()<< "\n\n" << std::endl;
    A->set(A->get_value()/2);
    std::cout<<"(a: \n" << A->get_value()<<"\n + b: \n" <<B->get_value() << "\n) * c: \n" << C->get_value()<< "\n = x: \n" << X->get_value()<< "\n\n" << std::endl;



    return 0;
}