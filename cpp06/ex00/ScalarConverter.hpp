#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

//is digit
#include <cctype>

// atoi
#include <cstdlib>
// setprecision
#include <iomanip>

enum Type{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    SPECIAL,
    NONE
};

enum Kind{
    NUM,
    DOT,
    F,
    ELSE,
    SIGN,
};

class ScalarConverter{
    private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(ScalarConverter const &);
    ScalarConverter& operator=(ScalarConverter const &);
    public:
        static void convert(const std::string & str);
};

#endif

