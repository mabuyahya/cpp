#include "Intern.hpp"
#include <iostream>

Intern::Intern(){
}
Intern::Intern(const Intern  & t){
    (void) t;
}
Intern& Intern::operator=(const Intern  & t){
    (void) t;
    return (*this);
}

Intern::~Intern(){
}

AForm* createShrubbery(std::string const& target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(std::string const& target) {
    return new RobotomyRequestForm(target);
}

AForm* createPardon(std::string const& target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm( std::string formName, std::string target){
    std::string formsNames[] =  {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm * (*functions[])(const std::string&) = {&createShrubbery, &createRobotomy, &createPardon};
    
    for (int i = 0; i < 3; i++){
        if (formsNames[i].compare(formName) == 0) {
            std::cout << "Intern creates " << formName << std::endl;
            return functions[i](target);
        }
    }
    
    std::cout << "Form name '" << formName << "' is unknown" << std::endl;
    return (NULL);
}