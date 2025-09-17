#include "AMateria.hpp" 

AMateria::AMateria(std::string const & type){
    this->type = type;
}

AMateria::~AMateria(){
}

AMateria::AMateria() : type("unknown") {
}

AMateria::AMateria(const AMateria & src) : type(src.type) {
}

AMateria & AMateria::operator=(const AMateria  & obj) {
    if (this != &obj) {
        this->type = obj.type;
    }
    return *this;
}

std::string const & AMateria::getType() const {
    return this->type;
}

void AMateria::use(ICharacter& target) {
    (void) target;
}
