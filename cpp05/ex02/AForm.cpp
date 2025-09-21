#include "AForm.hpp"

AForm::AForm()
:target(""), name(""), gradeToSign(75), gradeToExecute(75) {
    isSigned = false;
    checkGrade();
}

AForm::AForm(const std::string& name, int signGrade, int execGrade, const std::string& target)
: name(name), gradeToSign(signGrade), gradeToExecute(execGrade) {
    isSigned = false;
    checkGrade();
}

AForm::AForm(const AForm& other)
:name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute), target(other.target){
    checkGrade();
}

AForm& AForm::operator=(const AForm& other){
    if (this != &other)
    {
        isSigned = other.isSigned;
        checkGrade();
    }
    return(*this);
}

AForm::~AForm(){
}

const char *AForm::GradeTooHighException::what() const throw(){
    return("Form Grade too high!\n");
}
const char *AForm::GradeTooLowException::what() const throw(){
    return("Form Grade too Low!\n");
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form '" << f.getName()
       << "' is " << (f.getIsSigned() ? "signed" : "not signed")
       << ". Sign grade: " << f.getSignGrade()
       << ", Exec grade: " << f.getExecGrade();
    return os;
}

void AForm::beSigned(Bureaucrat& b){
    if (b.getGrade() > this->gradeToSign)
        throw AForm::GradeTooLowException();
    this->isSigned = true;
}

const std::string& AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getSignGrade() const {
    return gradeToSign;
}

const std::string & AForm::getTarget() const {
    return target;
}

void AForm::setTarget(const std::string & tt){
}

int AForm::getExecGrade() const {
    return gradeToExecute;
}

void AForm::checkGrade(){
    if (gradeToSign < 1 || gradeToSign < 1)
      throw AForm::GradeTooLowException();
    if (gradeToExecute > 150 || gradeToSign > 150 )
       throw AForm::GradeTooHighException();
}