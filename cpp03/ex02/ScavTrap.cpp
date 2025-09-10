#include "ScavTrap.hpp"

void ScavTrap::attack(const std::string& target){
    if (energyPoints != 0 && hitPoints != 0)
    {
        energyPoints--;
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << "\n";
    }
    else
    {
        std::cout << name << " can't attack no energyPoints or hitpoints\n";
    }
}

void ScavTrap::takeDamage(unsigned int amount){
    if (hitPoints != 0)
    {
        hitPoints-= amount;
        if (hitPoints < 0)
            hitPoints = 0;
        std::cout << "ScavTrap " << this->name << " takes " << amount << " points of damage! Current hit points: " << this->hitPoints << "\n";
    }
    else
    {
        std::cout << name << " can't take damage hitpoints is 0\n";
    }
}

void ScavTrap::beRepaired(unsigned int amount){
    if (energyPoints != 0 && hitPoints != 0)
    {
        energyPoints--;
        hitPoints += amount;
        std::cout << "ScavTrap " << this->name << " is repaired by " << amount << " points! Current hit points: " << this->hitPoints << "\n";
    }
    else
    {
        std::cout << name << " can't beRepaired no energyPoints";
    }
}

ScavTrap::ScavTrap()
: ClapTrap() {
    std::cout << "ScavTrap Default constructor called" << "\n";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other){
    std::cout << "ScavTrap Copy constructor called" << "\n";
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
    std::cout << "ScavTrap Copy assignment operator called" << "\n";
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << "\n";
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    std::cout << "ScavTrap Parameterized constructor called" << "\n";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << "\n";
}
