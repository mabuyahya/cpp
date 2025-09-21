#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP


#include "AForm.hpp"
#include <iostream>
#include <fstream>



class ShrubberyCreationForm : public AForm
{
    public:
    ShrubberyCreationForm();
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& obj);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &obj);

    ShrubberyCreationForm(const std::string &target);
    void execute(Bureaucrat const & executor) const ;
};

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("", 145, 137, ""){
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
: AForm(obj){
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("", 145, 137, target){
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    std::ofstream outFile((getTarget() + "_shrubbery").c_str());
    outFile << "what";
    outFile.close();
}

#endif