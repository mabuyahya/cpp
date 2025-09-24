#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(ScalarConverter const & tt){(void ) tt;}
ScalarConverter& ScalarConverter::operator=(ScalarConverter const & tt){(void) tt; return (*this);}


int ScalarConverter::checkIfMix(const std::string & str){
    int flag[] = {0, 0};
    for (size_t i = 0; i < str.length(); i++)
    {
        if (std::isdigit(str[i]))
            flag[0] = 1;
        if (std::isalpha(str[i]) && str[i] != 'f')
            flag[1] = 1;
    }
    if (flag[0] && flag[1])
        return(1);
    return (0);
    
}

void ScalarConverter::toChar(const std::string & str){
   std::cout << "char: ";
   if (str.length() == 1 && !std::isdigit(str[0])){
        char c = str[0];
        if (c >= 32 && c <= 126){
            std::cout << "'" << c << "'" << std::endl;
        }
        else{
            std::cout << "Non displayable \n";
        }
        return ;
    }
    try
    {
        if (checkIfMix(str)){
            std::cout << "impossible\n";
            return ;
        }
        double d = std::stod(str);
         if (d != d || d == std::numeric_limits<double>::infinity() ||
            d == -std::numeric_limits<double>::infinity()) {
            std::cout << "impossible\n";
            return;
        }
        if (d < 0 || d > 127){
            std::cout << "impossible\n";
            return ;
        }
        char c = static_cast<char>(d); 
        if (c >= 32 && c <= 126){
            std::cout << "'" << c << "'" << std::endl;
        }
        else
        {
            std::cout << "Non displayable\n";
        }
    }
    catch(...)
    {
        std::cout << "impossible\n";
        return ;
    }
}

void ScalarConverter::toInt(const std::string & str){
    std::cout << "int: ";
    try {
        double d = std::stod(str);
        if (d != d || d == std::numeric_limits<double>::infinity() ||
            d == -std::numeric_limits<double>::infinity()) {
            std::cout << "impossible\n";
            return;
        }
        if (d < INT_MIN || d > INT_MAX) {
            std::cout << "impossible\n";
            return;
        }
        int i = static_cast<int>(d);
        std::cout << i << "\n";
    } catch (...) {
        std::cout << "impossible\n";
    }
}

void ScalarConverter::toFloat(const std::string & str){
    std::cout << "float: ";
    try {
        double f = std::stof(str);
        if (f != f){
            std::cout << "nanf\n";
        } else if (f == std::numeric_limits<float>::infinity()){
            std::cout <<  "+inff\n";
        } else if (f == -std::numeric_limits<float>::infinity()){
            std::cout <<  "-inff\n";
        } else {
            std::cout << std::fixed << std::setprecision(1) << f << "f"<< std::endl;
        }
    } catch (...) {
        std::cout << "impossible\n";
    }
}

void ScalarConverter::toDouble(const std::string & str){
    std::cout << "double: ";
    try {
        double d = std::stod(str);
        if (d != d){
            std::cout << "nan\n";
        } else if (d == std::numeric_limits<double>::infinity()){
            std::cout <<  "+inf\n";
        } else if (d == -std::numeric_limits<double>::infinity()){
            std::cout <<  "-inf\n";
        } else {
            std::cout << std::fixed << std::setprecision(1) << d << std::endl;
        }
    } catch (...) {
        std::cout << "impossible\n";
    }
}
void    ScalarConverter::convert(const std::string & str){
    toChar(str);
    toInt(str);
    toFloat(str);
    toDouble(str);
}