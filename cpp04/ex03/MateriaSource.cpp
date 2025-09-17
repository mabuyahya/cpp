#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(){
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
}
MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (materias[i]) {
            delete materias[i];
        }
    }
}

MateriaSource::MateriaSource(const MateriaSource &obj) {
    for (int i = 0; i < 4; i++) {
        if (obj.materias[i])
            materias[i] = obj.materias[i]->clone();
        else
            materias[i] = 0;
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (materias[i] && materias[i]->getType() == type)
            return materias[i]->clone();
    }
    return 0;
}

void MateriaSource::learnMateria(AMateria* materia) {
    if (!materia) {
        std::cout << "materia is null\n";
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!materias[i]) {
            materias[i] = materia; 
            return; 
        }
    }
}

MateriaSource & MateriaSource::operator=(const MateriaSource &obj) {
    if (this != &obj) {
        for (int i = 0; i < 4; i++) {
            if (materias[i]) {
                delete materias[i];
                materias[i] = 0;
            }
            if (obj.materias[i])
                materias[i] = obj.materias[i]->clone();
        }
    }
    return *this;
}