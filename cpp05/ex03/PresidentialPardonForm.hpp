#ifndef PRESIDENTIALpARDONfORM_HPP
#define PRESIDENTIALpARDONfORM_HPP


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
    private:
        void checkGrade(Bureaucrat const & executor) const;
};


#endif