#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    meta->makeSound();
    j->makeSound();
    i->makeSound(); 
    delete meta;
    delete j;
    delete i;
return 0;
}