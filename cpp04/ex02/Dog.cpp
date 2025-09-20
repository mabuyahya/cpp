#include "Dog.hpp"

Dog::Dog(){
    std::cout << "defalut constructor called from Dog class \n";
    type = "Dog";
    brain = new Brain;
}

Dog::Dog(const Dog& other){
    std :: cout  << "copy constructor form Dog class \n";
    type = other.type;
    brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog&other) {
    std::cout << " copy assiment operator form Dog class \n";
    if (this != &other)
    {
        delete brain;
        type = other.type;
        brain = new Brain(*other.brain);
    }
    return (*this);
}

Dog::~Dog () {
    std::cout << "destructor called from Dog class\n";
    delete brain;
}

void Dog::makeSound () const{
    std::cout <<"Dog sound\n";
}