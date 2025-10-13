#include "PmergeMe.hpp"
#include <limits>

PmergeMe::PmergeMe(){
}
PmergeMe::PmergeMe(int c, char **v){
    parseAndValidatInput(c, v);
}
PmergeMe & PmergeMe::operator=(const PmergeMe & tt){
    (void) tt;
    return (*this);
}
PmergeMe::PmergeMe(const PmergeMe & tt){
    (void) tt;
}
PmergeMe::~PmergeMe(){
}

bool PmergeMe::validNumber(std::string str){
    for (size_t i = 0; i < str.length(); i++){
        if (!std::isdigit(str[i]) && !((str[i] == '+') && i == 0)){
            return (false);
        }
    }
    return (true);
}

std::string PmergeMe::trem(std::string str){
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos)
        return ("");
    int len = str.find_last_not_of("  \t") - first + 1;
    return(str.substr(first, len));
}

void PmergeMe::parseAndValidatInput(int argc, char **argv){
    for(int i = 1; i < argc ; i++){
        std::string trimmed = trem(argv[i]);
        if (!validNumber(trimmed)){
            throw std::runtime_error("not a valid number");
        }
        std::string numStr = trimmed;
        if (numStr[0] == '+') {
            numStr = numStr.substr(1);
        }
        if (numStr.length() > 10 || (numStr.length() == 10 && numStr > "2147483647")) {
            throw std::runtime_error("number is out of int range");
        }
        
        long long num = std::atoll(trimmed.c_str());
        if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min()) {
            throw std::runtime_error("number is out of int range");
        }
        vector.push_back(static_cast<int>(num));
    }
}

void PmergeMe::sortVector(std::vector<int> &vector){
    std::vector<int> smalles;
    std::vector<int> larges;

    for (int i = 0; i + 1 < vector.size(); i += 2){
        int a = vector[i];
        int b = vector[i + 1];

        if (a > b){
            larges.push_back(a);
            smalles.push_back(b);
        }
        else {
            larges.push_back(b);
            smalles.push_back(a);
        }
    }
    if (vector.size() % 2 != 0){
        smalles.push_back(vector.back());
    }
    sortVector(larges);

    for (size_t i = 0; i < smalles.size(); i++){
        std::vector<int>::iterator it = std::lower_bound(larges.begin(), larges.end(), smalles[i]);
        larges.insert(it, smalles[i]);
    }
    vector = larges;
}

void PmergeMe::sort(int argc, char **argv){
    parseAndValidatInput(argc, argv);
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    
}