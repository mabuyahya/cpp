#ifndef PRESIDENTIALpARDONfORM_HPP
#define pRESIDENTIALpARDONfORM_HPP


#include "AForm.hpp"
#include <iostream>
#include <fstream>



class PresidentialPardonForm : public AForm
{
    public:
    PresidentialPardonForm();
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& obj);
    PresidentialPardonForm& operator=(const PresidentialPardonForm &obj);

    PresidentialPardonForm(const std::string &target);
    void execute(Bureaucrat const & executor) const ;
};

PresidentialPardonForm::PresidentialPardonForm(): AForm("", 25, 5, ""){
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

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("", 25, 5, target){
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
}

#endif