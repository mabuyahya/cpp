#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>

class Notfound : public std::exception {
    public:
        const char *what() const throw(){
            return ("number Not Found\n");
        }
};

template <typename T> 
typename T::iterator    easyfind(T& container, int num){
    typename T::iterator result = std::find(container.begin(), container.end(), num);
    if (result == container.end())
        throw Notfound();
    return (result);
}

#endif