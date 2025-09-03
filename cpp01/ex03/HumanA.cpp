#include "HumanA.hpp"

void HumanA::attack() {
    std::cout << name <<  " attacks with their " << weapon.getType() << "\n";
}

HumanA::HumanA( std::string name, Weapon& weapon ):
weapon(weapon)
{
    this->name = name;
}