#ifndef fRAGtRAP_hPP
#define fRAGtRAP_hPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
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