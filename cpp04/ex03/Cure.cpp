#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure()
: AMateria("cure"){
}

Cure::Cure(const Cure & src)
: AMateria("cure"){
    (void) src;
}

Cure & Cure::operator=(const Cure  & rhs) {
    (void) rhs;
    return (*this);
}

Cure::~Cure(){
}

void Cure::use(ICharacter& target){
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const {
    return(new Cure(*this));
}

const std::string & Cure::getType() const{
    return (type);
}

