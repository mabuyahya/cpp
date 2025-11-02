#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <stack>
#include <stdexcept>

class RPN
{
    private:
        std::stack<double> stack; 

    public:
        RPN();
        ~RPN();
        RPN(const RPN &);
        RPN &operator=(const RPN &);
        RPN(std::string );

        void parseRNP(std::string );
};


#endif