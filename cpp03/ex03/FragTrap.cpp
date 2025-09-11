#include "FragTrap.hpp"

void FragTrap::attack(const std::string& target){
    if (energyPoints != 0 && hitPoints != 0)
    {
        energyPoints--;
        std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << "\n";
    }
    else
    {
        std::cout << name << " can't attack no energyPoints or hitpoints\n";
    }
}

void FragTrap::takeDamage(unsigned int amount){
    if (hitPoints != 0)
    {
        hitPoints-= amount;
        if (hitPoints < 0)
            hitPoints = 0;
        std::cout << "FragTrap " << this->name << " takes " << amount << " points of damage! Current hit points: " << this->hitPoints << "\n";
    }
    else
    {
        std::cout << name << " can't take damage hitpoints is 0\n";
    }
}

void FragTrap::beRepaired(unsigned int amount){
    if (energyPoints != 0 && hitPoints != 0)
    {
        energyPoints--;
        hitPoints += amount;
        std::cout << "FragTrap " << this->name << " is repaired by " << amount << " points! Current hit points: " << this->hitPoints << "\n";
    }
    else
    {
        std::cout << name << " can't beRepaired no energyPoints";
    }
}

FragTrap::FragTrap()
: ClapTrap() {
    std::cout << "FragTrap Default constructor called" << "\n";
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other){
    std::cout << "FragTrap Copy constructor called" << "\n";
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other){
    std::cout << "FragTrap Copy assignment operator called" << "\n";
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << "\n";
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    std::cout << "FragTrap Parameterized constructor called" << "\n";
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "High fives!" << std::endl;
}