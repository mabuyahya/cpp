#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>

template <typename T> 
typename T::iterator    easyfind(T& container, int num){
    typename T::iterator result = std::find(container.begin(), container.end(), num);
    if (result == container.end())
        throw std::exception();
    return (result);
}

#endif