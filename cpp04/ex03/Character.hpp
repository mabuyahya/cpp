#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter{
    private:
        AMateria* inventory[4];
        std::string name;
    public:
        Character();
        Character(const Character& other);
        Character& operator=(const Character& other);
        ~Character();
        Character(std::string name);

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);


};

#endif