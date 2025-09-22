#include "ShrubberyCreationForm.hpp"

const char *ShrubberyCreationForm::FileNotOpen::what() const throw(){
    return("file not open!\n");
}
void ShrubberyCreationForm::checkGrade(Bureaucrat const & executor)const{
    if(!getIsSigned())
        throw AForm::FormNotSigned();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowToExec();
}
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137, ""){
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

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreationForm", 145, 137, target){
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    checkGrade(executor);
    std::ofstream file((getTarget() + "_shrubbery").c_str());
    if (!file.is_open())
    {
        throw ShrubberyCreationForm::FileNotOpen();
    }
    file << "       ###\n"
            "      #o###\n"
            "    #####o###\n"
            "   #o#\\#|#/###\n"
            "    ###\\|/#o#\n"
            "     }' `{>\n"
            "     }}{ \n"
            "    }}{{ \n"
            "    {{}} \n"
            "    }}{{ \n"
            "    {{}}\n";
    file.close();
    std::cout << "* Created shrubbery at " << getTarget() << " *\n";
}