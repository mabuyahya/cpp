#include "Cat.hpp"

Cat::Cat(){
    std::cout << "defalut constructor called from Cat class \n";
    type = "Cat";
}

Cat::Cat(const Animal& other){
    std :: cout  << "copy constructor form Cat class \n";
    *this = other;
}

Cat Cat::operator=(const Cat&other) {
    std::cout << " copy assiment operator form Cat class \n";
    if (this != &other)
    {
        type = other.type;
    }
    return (*this);
}

Cat::~Cat () {
    std::cout << "destructor called from Cat class\n";
}

void Cat::makeSound () const{
    std::cout <<"Cat sound\n";
}

