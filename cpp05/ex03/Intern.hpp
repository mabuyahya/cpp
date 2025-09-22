#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
    private:
    public:
    Intern();
    ~Intern();
    Intern( const Intern  &);
    Intern& operator=( const Intern  &);

    AForm* makeForm(std::string formName, std::string target);
};


#endif