#ifndef CLAPTRAP_CPP
#define CLAPTRAP_CPP

#include <string>
#include <iostream>

class ClapTrap{
    private:
        std::string name;
        int hitPoints;
        int attackDamage;
        int energyPoints;

    public:
        ClapTrap();
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();


        ClapTrap( std::string name );
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        // int getAttackDamage();
};



#endif