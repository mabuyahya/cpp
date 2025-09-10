#include "ClapTrap.hpp"
int main ()
{
    ClapTrap a("ClapTrap A");
    ClapTrap b("ClapTrap B");

    a.attack("ClapTrap B");
    // b.takeDamage(a.getAttackDamage());
    // b.beRepaired(5);
    // b.attack("ClapTrap A");
    // a.takeDamage(b.getAttackDamage());
    // a.beRepaired(3);
    return 0;

}