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
    class FileNotOpen : public std::exception{
        public:
        const char * what()const  throw();

    };
    private:
        void checkGrade(Bureaucrat const & executor)const ;
};


#endif