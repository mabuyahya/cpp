#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice()
: AMateria("ice"){
}

Ice::Ice(const Ice & src)
: AMateria("ice"){
    (void)src;
}

Ice & Ice::operator=(const Ice  & rhs) {
    (void) rhs;
    return (*this);
}

Ice::~Ice(){
}

void Ice::use(ICharacter& target){
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const {
    return(new Ice(*this));
}

const std::string & Ice::getType() const{
    return (type);
}

