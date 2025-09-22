#include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::checkGrade(Bureaucrat const & executor)const{
    if(!getIsSigned())
        throw AForm::FormNotSigned();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowToExec();
}
PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5, ""){
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
: AForm(obj){
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PresidentialPardonForm", 25, 5, target){
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    checkGrade(executor);
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}

