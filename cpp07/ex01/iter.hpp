#ifndef  WHATEVER_HPP
#define  WHATEVER_HPP

#include <iostream>

template <typename T, typename F>
void    iter(T arr[], const size_t  len, F function){
    if (len <= 0)
        return ;
    for (size_t i = 0; i < len; i++)
    {
        function(arr[i]);
    }
}

#endif