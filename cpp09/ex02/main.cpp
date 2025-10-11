#include "PmergeMe.hpp"
#include <iostream>
#include <exception>

int main(int c, char **v){
    if (c == 1){
        std::cerr << "no args\n";
        return (0);
    }
    PmergeMe sort; 
    try{
        sort.sort(c, v);
    } catch(std::exception & e){
        std::cout << e.what() << std::endl;
    }
    return (0);
    return (0);
}