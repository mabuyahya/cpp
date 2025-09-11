#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
    protected:
        static const int S_DEFAULT_HIT_POINTS = 100;
        static const int S_DEFAULT_ENERGY_POINTS = 50;
        static const int S_DEFAULT_ATTACK_DAMAGE = 20;

    public: 
        ScavTrap();
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);
        ~ScavTrap();

        ScavTrap(std::string name);
        void	attack(const std::string &target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        void    guardGate();
};



#endif