#include "Dog.hpp"

Dog::Dog(){
    std::cout << "defalut constructor called from Dog class \n";
    type = "Dog";
}

Dog::Dog(const Dog& other){
    std :: cout  << "copy constructor form Dog class \n";
    *this = other;
}

Dog Dog::operator=(const Dog&other) {
    std::cout << " copy assiment operator form Dog class \n";
    if (this != &other)
    {
        type = other.type;

    }
    return (*this);
}

Dog::~Dog () {
    std::cout << "destructor called from Dog class\n";
}

void Dog::makeSound () const{
    std::cout <<"Dog sound\n";
}