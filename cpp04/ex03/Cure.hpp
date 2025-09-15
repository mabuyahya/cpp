#ifndef ICE_HPP 
#define ICE_HPP 

#include "AMateria.hpp"
#include <iostream>

class Cure: public AMateria{
    public:
        Cure();
        Cure(const Cure & src);
        Cure & operator=(const Cure & rhs);
        ~Cure();
        Cure(std::string type);
        AMateria* clone() const;
        void use(ICharacter& target);
        const std::string & getType() const;
};







#endif