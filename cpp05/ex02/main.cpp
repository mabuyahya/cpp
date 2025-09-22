#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

    int main() {
        Bureaucrat alice("Alice", 5);
        Bureaucrat bob("Bob", 75);
        Bureaucrat jone("jone", 144);

        AForm* shrub = new ShrubberyCreationForm("home");
        AForm* robot = new RobotomyRequestForm("Bender");
        AForm* pardon = new PresidentialPardonForm("Ford");
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
