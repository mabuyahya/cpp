#include "Cure.hpp"
#include "Ice.hpp"

int main(){
    AMateria *c = new Cure;
    AMateria *cc = c->clone();
    std::cout << cc->getType() << std::endl;
    // cc->use();
}