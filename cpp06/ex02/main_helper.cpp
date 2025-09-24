#include "main_helper.hpp"

Base * generate(void){

}

void identify(Base* p){
    A* ptrA = dynamic_cast<A*>(p);
    if (ptrA)
    {
        std::cout << "the Base ptr is pointing to a A class obj\n" ;
        return ;
    }
    B* ptrB = dynamic_cast<B*>(p);
    if (ptrB)
    {
        std::cout << "the Base ptr is pointing to a B class obj\n" ;
        return ;
    }
    C* ptrC = dynamic_cast<C*>(p);
    if (ptrC)
    {
        std::cout << "the Base ptr is pointing to a C class obj\n" ;
        return ;
    }
}

void identify(Base& p){

}