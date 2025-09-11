#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
: ClapTrap(), ScavTrap(), FragTrap(){
    name = "unnamed";
    std::cout << "DiamondTrap " << this->name << " default constructor called" << std::endl;
    hitPoints = FragTrap::F_DEFAULT_HIT_POINTS;
    energyPoints = ScavTrap::S_DEFAULT_ENERGY_POINTS;
    attackDamage = FragTrap::F_DEFAULT_ATTACK_DAMAGE;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other){
    std::cout << "DiamondTrap " << this->name << " copy constructor called" << std::endl;
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "DiamondTrap " << this->name << " copy assignment operator called" << std::endl;
    if (this != &other)
    {
        hitPoints = other.hitPoints;
        name = other.name;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
        this->ClapTrap::name = other.ClapTrap::name;
    }
    return(*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->name << " destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name){
    this->name = name;
    hitPoints = FragTrap::F_DEFAULT_HIT_POINTS;
    energyPoints = ScavTrap::S_DEFAULT_ENERGY_POINTS;
    attackDamage = FragTrap::F_DEFAULT_ATTACK_DAMAGE;
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << name << ", my ClapTrap name is " << ClapTrap::name  << "\n";
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}