#include "iter.hpp"


void print(const int &num)
{
        std::cout << num;
}


void increment(int &num)
{
    num++;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    std::cout << "Int Array Before Increment : ";
    ::iter(arr, 5, print);
    std::cout << "\n";
    std::cout << "Int Array After Increment : ";
    ::iter(arr, 5, increment);
    ::iter(arr, 5, print);
    std::cout << "\n";
    return (0);
}