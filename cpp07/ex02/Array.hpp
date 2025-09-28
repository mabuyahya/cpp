#ifndef  ARRAY_HPP
#define  ARRAY_HPP
#include <cstddef>
#include <exception>
#include <iostream>

template <typename T>
class Array {
    private:
        T *arr;
        size_t size;

    public:
        Array();
        Array(const size_t n);
        ~Array();
        Array(const Array &);
        Array & operator=(const Array &);
        T &operator[](size_t i);
        const T &operator[](size_t i) const ;

        size_t getSize() const ;
};

template <typename T>
Array<T>::Array() : size(0){
    arr = new T[0];
}

template <typename T>
Array<T>::Array(size_t n){
    arr = new T[n];
    size = n;
}

template <typename T>
Array<T>::Array(const Array & other): size(other.getSize()){
    arr = new T[other.getSize()];
    for (size_t i = 0; i < other.getSize(); i++)
    {
        arr[i] = other[i];
    }
    
}

template <typename T>
Array<T> &Array<T>::operator=(const Array & other){
    if (this != &other)
    {
        delete[] arr;

        arr = new T[other.getSize()];
        size = other.getSize();
        for (size_t i = 0; i < other.getSize(); i++)
        {
            arr[i] = other[i];
        }
    }
    return (*this);
}




template <typename T>
Array<T>::~Array(){
    delete[] arr;
}


template<typename T>
T &Array<T>::operator[](size_t i){
    if (i >= getSize()){
        throw std::exception();
    }
    return arr[i];
}

template<typename T>
const T &Array<T>::operator[](size_t i) const {
    if (i >= getSize()){
        throw std::exception();
    }
    return arr[i];
}

template <typename T>
size_t Array<T>::getSize() const {
    return (size);
}


#endif