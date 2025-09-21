#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;


class Form{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;

    public:
        Form();
        Form(const std::string& name, int signGrade, int execGrade);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();
        const std::string& getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;

        void beSigned(Bureaucrat & b);

        class GradeTooHighException : public std::exception{
            public:
                const char *what()const throw();
        };
        class GradeTooLowException: public std::exception{
            public:
                const char *what()const throw();
        };


};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif