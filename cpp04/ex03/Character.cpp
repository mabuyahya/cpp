#include "Character.hpp"
#include <iostream>

std::string const & Character::getName() const {
    return this->name;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4)
    {
        std::cout << "out of range\n";
    return;
    }
    inventory[idx] = 0;
}

void Character::equip(AMateria* m) {
    if (!m)
    {
        return;
    }
    for (int i = 0; i < 4; ++i) {
        if (!inventory[i]) {
            inventory[i] = m;
            return;
        }
    }
    std::cout<<"full inventory \n";
}

void Character::use(int idx, ICharacter& target)
{
    if ( idx < 0 || idx >= 4)
        return;
    if (inventory[idx] != NULL)
    {
        inventory[idx]->use(target);
    }
}

Character::Character(){
    name = "";
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(std::string name){
    this->name = name;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const Character& other){
    name = other.name;
    for (int i = 0; i < 4; i++){
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = 0;
    }
}

Character& Character::operator=(const Character& other){
    if (this != &other){
        name = other.name;
        for (int i = 0; i < 4; i++){
            if (inventory[i])
                delete inventory[i];
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = 0;
        }
    }
    return(*this);
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (inventory[i]) {
            delete inventory[i];
        }
    }
}