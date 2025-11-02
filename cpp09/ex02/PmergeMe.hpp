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
        std::vector<int> sortVector(std::vector<int> &vector);
        std::deque<int> sortDeque(std::deque<int> &deque);
        int generateJacob(int n);
        void extendJacobNumbers(std::vector<int> &jacobsthalNumbers, int pendingSize);
        int binarySearch(std::vector<int> main, int pend, int high);
        void sorting(std::vector<int> &main, std::vector<int> pend, std::vector<int> jacob);
        std::vector<int> getJacobNumbers(int pendingSize);
        void parseAndValidatInputDeque(int , char **);
        void extendJacobNumbers(std::deque<int> &jacobsthalNumbers, int pendingSize);
        int binarySearch(std::deque<int> main, int pend, int high);
        void sorting(std::deque<int> &main, std::deque<int> pend, std::deque<int> jacob);
        std::deque<int> getJacobNumbersDeque(int pendingSize);
};

typedef std::vector<std::pair<int, int> > PairVector;
typedef std::deque<std::pair<int, int> > PairDeque;


#endif