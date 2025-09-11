#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap{
    private:
        std::string name;
    public: 
        DiamondTrap();
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap& operator=(const DiamondTrap& other);
        ~DiamondTrap();

        DiamondTrap(std::string name);
        void whoAmI();
        void attack(const std::string &target);
};

#endif