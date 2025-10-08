#include "RPN.hpp"

int main(int c, char **s){
    if (c != 2){
        std::cout << "on args\n";
        return (1);
    }
    RPN test;
    test.parseRNP(s[1]);
    return (0);
}