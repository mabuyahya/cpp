#include "Bureaucrat.hpp"


void Bureaucrat::checkGrade(){
    if (grade < 1)
      throw Bureaucrat::GradeTooLowException();
    if (grade > 150)
       throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat():name(""), grade(75){}
Bureaucrat::Bureaucrat(const Bureaucrat& obj):name(obj.name),grade(obj.grade)
{
    checkGrade();
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj){
    if (this != &obj){
        grade = obj.grade;
        checkGrade();
    }
    return (*this);
}
Bureaucrat::~Bureaucrat(){}

const std::string& Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::incrementGrade()
{
    --grade;
    checkGrade();
}

void Bureaucrat::decrementGrade()
{
    ++grade;
    checkGrade();
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
    return("Grade too high!\n");
}
const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return("Grade too Low!\n");
}

Bureaucrat::Bureaucrat(const std::string& name, const int grade):name(name),grade(grade)
{
    checkGrade();
}