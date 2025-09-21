#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;


class AForm{
    private:
        const std::string name;
        const std::string target;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
    private:
        void AForm::checkGrade();

    public:
        AForm();
        AForm(const std::string& name, int signGrade, int execGrade, const std::string& target);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        ~AForm();
        const std::string& getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        const std::string& getTarget() const;
        void setTarget(const std::string &);

        void beSigned(Bureaucrat & b);

        virtual void execute(Bureaucrat const & executor) = 0;

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