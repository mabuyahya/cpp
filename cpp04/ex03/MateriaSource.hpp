#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
    private:
        AMateria*  materias[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource & src);
        MateriaSource & operator=(const MateriaSource & rhs);
        ~MateriaSource();
        AMateria* createMateria(std::string const & type);
        void learnMateria(AMateria*);
};


#endif