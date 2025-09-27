#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(ScalarConverter const & tt){(void ) tt;}
ScalarConverter& ScalarConverter::operator=(ScalarConverter const & tt){(void) tt; return (*this);}

bool isAllDigit(char kinds[], int len){
    int i = 0;

    if (kinds[0] == SIGN && len != 1)
        i++;
    while (i < len)
    {
        if (kinds[i] != NUM)
            return false;
        i++;
    }
    return true;
}

bool isDouble(char kinds[], int len){
    int dotCont = 0;
    for (int i = 0; i < len; i++){
        if (kinds[i] == DOT){
            dotCont++;
            continue ;
        }
        if (kinds[i] != NUM)
            return (false);
    }
    if (dotCont != 1)
        return (false);
    return (true);
}

bool isFloat(char kinds[], int len){
    int dotCont = 0;
    for (int i = 0; i < len - 1; i++){
        if (kinds[i] == DOT){
            dotCont++;
            continue ;
        }
        if (kinds[i] != NUM && (kinds[i] != F && i != len - 1))
            return (false);
    }
    if (dotCont != 1)
        return (false);
    return (true);
}

bool isOneChar(char kinds[], int len){
    if ((kinds[0] == ELSE || kinds[0] == DOT || kinds[0] == F) && len == 1)
        return true;
    return false;
}

Type whichType(const std::string & str){
    char kinds[str.length()];
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == 'f') kinds[i] = F;
        else if (isdigit(str[i])) kinds[i] = NUM;
        else if (str[i] == '.') kinds[i] = DOT;
        else if (str[i] == '+' || str[i] == '-') kinds[i] = SIGN;
        else kinds[i] = ELSE;
    }
    if (isOneChar(kinds, str.length()))
        return CHAR;
    else
    if (isAllDigit(kinds, str.length()))
        return INT;
    if (isDouble(kinds, str.length()))
        return DOUBLE;
    if (isFloat(kinds, str.length()))
        return FLOAT;
    if (str == "nan" || str == "+inf" || str == "-inf" || str == "nanf" || str == "+inff" || str == "-inff")
        return SPECIAL;
    return NONE;
}

void charPath(const std::string & str){
    char c = str[0];
    std::cout << "char: '" << c << "'\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << "float: " << static_cast<float>(c) << ".0f" << "\n";
    std::cout << "double: " << static_cast<double>(c) << ".0" << "\n";
}

void intPath(const std::string & str){
    int n = std::atoi(str.c_str());
    if ( n < 0 || n > 127)
        std::cout << "char: impossible\n";
    else if (n < 32 || n > 126)
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(n) << "'\n";
    std::cout << "int: " << n << "\n";
    std::cout << "float: " << static_cast<float>(n) << ".0f" << "\n";
    std::cout << "double: " << static_cast<double>(n) << ".0" << "\n";
}

void floatPath(const std::string & str){
    std::cout << std::fixed << std::setprecision(1);
    float f = std::atof(str.c_str());
    if (f  != static_cast<int>(f))
        std::cout << "char: impossible\n";
    else if (f < 0 || f > 127)
        std::cout << "char: impossible\n";
    else if (f < 32 || f > 126)
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(f) << "'\n";
    std::cout << "int: " << static_cast<int>(f) << "\n";
    std::cout << "float: " << f << "f\n";
    std::cout << "double: " << static_cast<double>(f) << "\n";
}

void doublePath(const std::string & str){
    std::cout << std::fixed << std::setprecision(1);
    double d = strtod(str.c_str(), NULL);
    if (d  != static_cast<int>(d))
        std::cout << "char: impossible\n";
    else if (d < 0 || d > 127)
        std::cout << "char: impossible\n";
    else if (d < 32 || d > 126)
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(d) << "'\n";
    std::cout << "int: " << static_cast<int>(d) << "\n";
    std::cout << "float: " << static_cast<float>(d) << "f\n";
    std::cout << "double: " << d << "\n";
}

void specialPath(const std::string & str){
    if (str == "nan" || str == "nanf"){
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
    }
    else if (str == "+inf" || str == "+inff"){
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: +inff\n";
        std::cout << "double: +inf\n";
    }
    else if (str == "-inf" || str == "-inff"){
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: -inff\n";
        std::cout << "double: -inf\n";
    }
}

void nonePath(const std::string & str){
    (void) str;
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
}

void    ScalarConverter::convert(const std::string & str){
    Type type = whichType(str);

    switch (type)
    {
        case CHAR:
            std::cout << "CHAR\n";
            charPath(str);
            break;
        case INT:
            std::cout << "INT\n";
            intPath(str);
            break;
        case FLOAT:
            std::cout << "FLOAT\n";
            floatPath(str);
            break;
        case DOUBLE:
            std::cout << "DOUBLE\n";
            doublePath(str);
            break;
        case SPECIAL:
            specialPath(str);
            break;
        case NONE:
            nonePath(str);
            break;
    }
}