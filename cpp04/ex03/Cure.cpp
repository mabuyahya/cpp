#include "Cure.hpp"

Cure::Cure()
: AMateria("Cure"){
}

Cure::Cure(const Cure & src)
: AMateria("Cure"){
    (void) src;
}

Cure & Cure::operator=(const Cure  & rhs) {
    (void) rhs;
    return (*this);
}

Cure::~Cure(){
}

void Cure::use(ICharacter& target){
    (void)target;
    std::cout << "Cure\n";
    // std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Cure::clone() const {
    return(new Cure(*this));
}

const std::string & Cure::getType() const{
    return (type);
}

