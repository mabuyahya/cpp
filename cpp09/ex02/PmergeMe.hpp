#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <limits>

class PmergeMe
{
    private:
        std::vector<int> vector;
        std::deque<int> deque;

    public:
        PmergeMe();
        PmergeMe(int , char **);
        ~PmergeMe();
        PmergeMe(const PmergeMe &);
        PmergeMe &operator=(const PmergeMe &);
        PmergeMe(std::string );

        void sort(int argc, char **argv);
    private:
        void parseAndValidatInput(int , char **);
        std::string trem(std::string str);
        bool validNumber(std::string str);
};


#endif