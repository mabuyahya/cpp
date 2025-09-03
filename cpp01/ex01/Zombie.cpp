#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}
Zombie::Zombie()
{
    this->name = "unnamed";
}
void  Zombie::announce()
{
    std::cout << name << ": " << "BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName( std::string name )
{
    this->name = name;
}
Zombie::~Zombie()
{
	std::cout<< name << " is dead" << "\n";
}
