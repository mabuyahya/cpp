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
    private:
    void checkGrade(Bureaucrat const & executor)const ;
};


#endif