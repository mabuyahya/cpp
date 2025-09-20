#include "Cat.hpp"

Cat::Cat(){
    std::cout << "defalut constructor called from Cat class \n";
    type = "Cat";
    brain = new Brain;
}

Cat::Cat(const Cat& other){
    std :: cout  << "copy constructor form Cat class \n";
    type = other.type;
    brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat&other) {
    std::cout << " copy assiment operator form Cat class \n";
    if (this != &other)
    {
    delete brain;
        type = other.type;
        brain = new Brain(*other.brain);
    }
    return (*this);
}

Cat::~Cat () {
    std::cout << "destructor called from Cat class\n";
    delete brain;
}

void Cat::makeSound () const{
    std::cout <<"Cat sound\n";
}

