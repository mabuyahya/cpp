#include "easyfind.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>

int main(){
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::cout << v[0] << "\n";
    std::cout << v[1] << "\n";
    std::cout << v[2] << "\n";
    std::cout << v.size() << "\n";
    try{
        std::vector<int>::iterator it = easyfind(v, 2);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e){
        std::cout << "not found\n";
    }
    
}