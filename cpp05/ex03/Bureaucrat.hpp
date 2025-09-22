#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string> 
#include <iostream> 
#include "AForm.hpp" 

class AForm;
class Bureaucrat{
    private:
        const std::string name;
        int grade;
        void checkGrade();

    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        const std::string& getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();

        void signForm(AForm & );
        void executeForm(AForm const & form) const;
        
        class GradeTooHighException : public std::exception{
            public:
                const char *what()const throw();
        };
        class GradeTooLowException: public std::exception{
            public:
                const char *what()const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& f);

#endif 