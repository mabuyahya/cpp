#ifndef  WHATEVER_HPP
#define  WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &one, T &two){
    T temp;
    temp = one;
    one = two;
    two = temp;
}

template <typename T>
T min(T &one, T &two){
    return (one < two ? one : two);
}

template <typename T>
T max(T &one, T &two){
    return (one > two ? one : two);
}
#endif