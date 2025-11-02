#include "RPN.hpp"

int main(int c, char **s){
    if (c != 2){
        std::cout << "Error: wrong args\n";
        return (1);
    }
    try {
        RPN test;
        test.parseRNP(s[1]);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}