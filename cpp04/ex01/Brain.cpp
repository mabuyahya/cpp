#include "Brain.hpp"

Brain::Brain(){
    std::cout << "defalut constructor called from Brain class \n";
    for (int i = 0; i < 100; i++)
        ideas[i] = "noIdea";
}

Brain::Brain(const Brain& other){
    std :: cout  << "copy constructor form Brain class \n";
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << " copy assiment operator form Brain class \n";
    if (this != &other)
    {
        for (int i = 0; i < 100 ; i++)
            ideas[i] = other.ideas[i];
    }
    return (*this);
}

Brain::~Brain () {
    std::cout << "destructor called from Brain class\n";
}