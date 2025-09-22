#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
    Bureaucrat alice("Alice", 5);
    Bureaucrat bob("Bob", 75);
    Bureaucrat jone("jone", 144);
    Intern  darawsheh;


    AForm* shrub = darawsheh.makeForm("shrubbery creation", "home");
    AForm* robot = darawsheh.makeForm("robotomy request", "Bender");
    AForm* pardon = darawsheh.makeForm("presidential pardon", "Ford");
    jone.signForm(*shrub);  
    bob.signForm(*robot);  
    alice.signForm(*pardon); 

    std::cout << "--------------------------------------\n";

    jone.executeForm(*shrub);  
    bob.executeForm(*robot); 
    alice.executeForm(*pardon);

    delete shrub;
    delete robot;
    delete pardon;

    return 0;
}
