#include "Array.hpp"
#include <ctime>
#include <cstdlib>

int main(){
    Array<int>* numbers;
    numbers = new Array<int>(10);
    std::srand(time(NULL));
	for (size_t i = 0; i < 10; i++)
		(*numbers)[i] = rand() % 101;
	std::cout << "Array preview:\n";
	for (size_t i = 0; i < 10; i++)
		std::cout << (*numbers)[i] << '\n';
    std::cout << "Attempting access to index -1 and 10:\n";
    try
	{
		std::cout << (*numbers)[-1] << '\n';
		// std::cout << (*numbers)[10] << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
        delete numbers;
        return (1);
	}
    std::cout << std::endl;
    delete numbers;
    return (0);
}