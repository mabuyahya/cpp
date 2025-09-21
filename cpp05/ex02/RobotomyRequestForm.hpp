#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP


#include "AForm.hpp"
#include <iostream>
#include <fstream>



class RobotomyRequestForm : public AForm
{
    public:
    RobotomyRequestForm();
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& obj);
    RobotomyRequestForm& operator=(const RobotomyRequestForm &obj);

    RobotomyRequestForm(const std::string &target);
    void execute(Bureaucrat const & executor) const ;
};

RobotomyRequestForm::RobotomyRequestForm(): AForm("", 72, 45, ""){
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

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("", 72, 45, target){
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
}

#endif