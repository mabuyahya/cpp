#include "Span.hpp"

#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>

int main(){
    // Span test(3);

    // test.addNumber(2);
    // test.addNumber(-2);
    // test.addNumber(10);
    // try {
    //     test.addNumber(10);
    // } catch(std::exception &e){
    //     std::cout << e.what();
    // } 
    // std::cout << test.longestSpan() << std::endl;
    // std::cout << test.shortestSpan() << std::endl;
    //------------------------------//
    // Span test(1);

    // test.addNumber(2);
    // try {
    //     std::cout << test.shortestSpan() << std::endl;

    // } catch(std::exception &e){
    //     std::cout << e.what();
    // } 
    //------------------------------//
    // Span test;

    // try {
    //     test.addNumber(1);
    //     std::cout << test.shortestSpan() << std::endl;

    // } catch(std::exception &e){
    //     std::cout << e.what();
    // }
    //------------------------------//
    Span test(100000);
	std::vector<int> test2;
	std::srand(time(NULL));
	for (int i = 0; i < 100000; i++)
    	test2.push_back(rand() % 1000000000);
	try
	{
        test.addNumberViaRange(test2.begin(), test2.end());
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
        std::cout << e.what() << std::endl;
	}
	exit(0);
    return (0);
}