#ifndef fRAGtRAP_hPP
#define fRAGtRAP_hPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
    protected:
        static const int F_DEFAULT_HIT_POINTS = 100;
        static const int F_DEFAULT_ENERGY_POINTS = 100;
        static const int F_DEFAULT_ATTACK_DAMAGE = 30;

    public: 
        FragTrap();
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);
        ~FragTrap();

        FragTrap(std::string name);
        void	attack(const std::string &target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        void highFivesGuys(void);
};



#endif