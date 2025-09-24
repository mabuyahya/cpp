#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

#include <limits>
#include <cmath>

#include <sstream>
#include <cstdlib>
#include <iomanip>

#include <climits>
#include <cctype>
class ScalarConverter{
    private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(ScalarConverter const &);
    ScalarConverter& operator=(ScalarConverter const &);
    public:
        static void convert(const std::string & str);
    private:
        static int checkIfMix(const std::string & str);
        static void toChar(const std::string & str);
        static void toInt(const std::string & str);
        static void toFloat(const std::string & str);
        static void toDouble(const std::string & str);
//         static void toChar(const std::string & str);
};

#endif

