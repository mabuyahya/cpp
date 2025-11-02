#include "RPN.hpp"

void RPN::parseRNP(std::string str){
    int i = 0;
    while (str[i])
    {
        while (str[i] && str[i] == ' ')
            i++;

        if (!str[i])
            break;

        if (std::isdigit(str[i]))
        {
            stack.push(str[i] - '0');
        }
        else if (str[i] == '*' || str[i] == '/' || str[i] == '-' || str[i] == '+')
        {
            if (stack.size() >= 2)
            {
                double first = stack.top();
                stack.pop();
                double second = stack.top();
                stack.pop();
                double result = 0;
                switch (str[i]) {
                    case '+': 
                        result = second + first;
                        break;
                    case '-': 
                        result = second - first;
                        break;
                    case '*': 
                        result = second * first;
                        break;
                    case '/': 
                        if (first == 0)
                            throw std::runtime_error("Error: division by zero");
                        result = second / first;
                        break;
                }
                stack.push(result);
            }
            else
            {
                std::cerr << "Error\n";
                return ;
            }
        }
        else
        {
            std::cerr << "Error\n";
            return ;
        }
        i++;
    }
    if (stack.size() == 1)
    {
        std::cout << stack.top() << std::endl;

    }
    else 
        std::cerr << "Error\n";

}

RPN::RPN(std::string str){
    parseRNP(str);
}

RPN::~RPN(){
}

RPN::RPN(){
}

RPN &RPN::operator=(const RPN &tt){
    if (this != &tt)
        stack = tt.stack;
    return (*this);
}

RPN::RPN(const RPN &tt){
        stack = tt.stack;
}