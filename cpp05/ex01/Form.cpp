#include "Form.hpp"

Form::Form()
: name(""), gradeToSign(75), gradeToExecute(75) {
    isSigned = false;
}

Form::Form(const std::string& name, int signGrade, int execGrade)
: name(name), gradeToSign(signGrade), gradeToExecute(execGrade) {
    isSigned = false;
}

Form::Form(const Form& other)
:name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute){
}

Form& Form::operator=(const Form& other){
    if (this != &other)
    {
        isSigned = other.isSigned;
    }
    return(*this);
}

Form::~Form(){
}

const char *Form::GradeTooHighException::what() const throw(){
    return("Form Grade too high!\n");
}
const char *Form::GradeTooLowException::what() const throw(){
    return("Form Grade too Low!\n");
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form '" << f.getName()
       << "' is " << (f.getIsSigned() ? "signed" : "not signed")
       << ". Sign grade: " << f.getSignGrade()
       << ", Exec grade: " << f.getExecGrade();
    return os;
}

void Form::beSigned(Bureaucrat& b){
    if (b.getGrade() > this->gradeToSign)
        throw Form::GradeTooLowException();
    this->isSigned = true;
}

const std::string& Form::getName() const {
    return name;
}

bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getSignGrade() const {
    return gradeToSign;
}

int Form::getExecGrade() const {
    return gradeToExecute;
}