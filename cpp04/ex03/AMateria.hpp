#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria{
    protected:
        std::string type;
    public:
        AMateria(std::string const & type);
        const std::string & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter & target);
        virtual ~AMateria();
        AMateria();
        AMateria(const AMateria  & src);
        AMateria & operator=(const AMateria  & obj);
};


#endif 
