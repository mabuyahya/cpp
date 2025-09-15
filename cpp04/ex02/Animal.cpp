#include "Animal.hpp"

Animal::Animal(){
    std::cout << "defalut constructor called from Animal class \n";
    type = "animal";
}

Animal::Animal(const Animal& other){
    std :: cout  << "copy constructor form Animal class \n";
    *this = other;
}

Animal& Animal::operator=(const Animal&other) {
    std::cout << " copy assiment operator form Animal class \n";
    if (this != &other)
    {
        type = other.type;
    }
    return (*this);
}

Animal::~Animal() {
    std::cout << "destructor called from Animal class\n";
}

void Animal::makeSound () const{
    std::cout <<"???\n";
}