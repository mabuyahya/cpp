#include "iter.hpp"

void print(const int &i)
{
    std::cout << i << std::endl;
}

void addOne(int &n)
{
    n += 1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    iter(arr, 5, print);
    std::cout << std::endl;
    iter(arr, 5, addOne);
    iter(arr, 5, print);
    return (0);
}