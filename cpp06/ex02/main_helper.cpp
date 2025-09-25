#include "main_helper.hpp"

Base * generate(void){
    srand(time(NULL));
    int num = rand();
    num = num % 3;
    switch (num)
    {
    case 0:
        std::cout << "the random generator generates A\n";
        return (new A());
    case 1:
        std::cout << "the random generator generates B\n";
        return (new B());
    case 2:
        std::cout << "the random generator generates  C\n";
        return (new C());
    default:
        break;
    }
    return (NULL); 
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
    std::cout << "No Type ptr\n";
}

void identify(Base& p){
    try{
        A& refA = dynamic_cast<A&>(p);
        static_cast<void>(refA);
        std::cout << "the Base ref is refering to a A class obj\n";
        return ;
    } catch(...){
    }
    try{
        B& refB = dynamic_cast<B&>(p);
        static_cast<void>(refB);
        std::cout << "the Base ref is refering to a B class obj\n";
        return ;
    } catch(...){
    }
    try{
        C& refC = dynamic_cast<C&>(p);
        static_cast<void>(refC);
        std::cout << "the Base ref is refering to a C class obj\n";
        return ;
    } catch(...){
        std::cout << "No Type ref\n";
    }
}