#include "RobotomyRequestForm.hpp"
#include <cstdlib>

void RobotomyRequestForm::checkGrade(Bureaucrat const & executor)const{
    if(!getIsSigned())
        throw AForm::FormNotSigned();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowToExec();
}

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45, ""){
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
: AForm(obj){
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45, target){
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    checkGrade(executor);
    std::cout << "Attempting robotomy...\a" << std::endl;
    std::srand(time(NULL));
    if (!(std::rand() % 2))
        std::cerr << "Robotomy failed." << std::endl;
    else
        std::cout << this->getTarget() << " has been robotomized." << std::endl;

}