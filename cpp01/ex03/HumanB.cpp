#include "HumanB.hpp"

void HumanB::attack() {
    std::cout << name <<  " attacks with their " << weapon->getType() << "\n";
}
HumanB::HumanB( std::string name ){
    this->name = name;
    weapon = NULL;
}
void HumanB::setWeapon( Weapon& weapon){
    this->weapon = &weapon;
}