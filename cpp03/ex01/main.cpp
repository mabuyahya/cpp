#include "ScavTrap.hpp"

int main ()
{
    ScavTrap a("Scavvy");
    a.attack("num 1");
    a.takeDamage(30);
    a.beRepaired(20);
    a.guardGate();
    return 0;
}
