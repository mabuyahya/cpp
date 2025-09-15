#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <iostream>

class Ice: public AMateria{
    public:
        Ice();
        Ice(const Ice & src);
        Ice & operator=(const Ice & rhs);
        ~Ice();
        Ice(std::string type);
        AMateria* clone() const;
        void use(ICharacter& target);
        const std::string & getType() const;
};

#endif