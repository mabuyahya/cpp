#ifndef CAR_HPP
#define CAR_HPP

#include "Animal.hpp"

class Cat : public Animal{
    public:
        Cat();
        Cat(const Animal& other);
        Cat operator=(const Cat& other);
        ~Cat();
        void makeSound() const;

};

#endif 
