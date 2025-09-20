#include "Bureaucrat.hpp"
#include <iostream>

int main(){
    Bureaucrat test = Bureaucrat("test", 1);
    std::cout << test.getGrade() << std::endl;
    try{
        test.incrementGrade();
    }catch(std::exception & e){
        std::cout << e.what();
    }
}