#include "PmergeMe.hpp"
#include <limits>
#include <algorithm>

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
int generateJacob(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int prev2 = 0, prev1 = 1, curr = 0;
    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

void extendJacobNumbers(std::vector<int> &jacobsthalNumbers, int pendingSize) {
    std::vector<int> extendedJacobsthalNumbers;
    size_t i = 0;
    int val;

    while (i < jacobsthalNumbers.size()) {
        val = jacobsthalNumbers[i];
        while (val > 0 && val <= pendingSize) {
            if (std::find(extendedJacobsthalNumbers.begin(), extendedJacobsthalNumbers.end(), val) == extendedJacobsthalNumbers.end())
                extendedJacobsthalNumbers.push_back(val);
            val--;
        }
        i++;
    }

    int j = pendingSize;
    while (j > 0) {
        if (std::find(extendedJacobsthalNumbers.begin(), extendedJacobsthalNumbers.end(), j) == extendedJacobsthalNumbers.end())
            extendedJacobsthalNumbers.push_back(j);
        j--;
    }

    jacobsthalNumbers = extendedJacobsthalNumbers;
}

int binarySearch(std::vector<int> main, int pend, int high){
    if (main.empty())
        return (0);
    int low = 0;
    if (high >= static_cast<int>(main.size()))
        high = main.size() - 1;

    while (low <= high){
        int mid = (high + low) / 2;
        if (main[mid] == pend){
            return (mid);
        }
        else if (main[mid] > pend) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    if (low < static_cast<int>(main.size()) && pend < main[low])
        return (low);
    }
    return (main.size());

}

void sorting(std::vector<int> &main, std::vector<int> pend, std::vector<int> jacob) {
    std::vector<int>::iterator it = jacob.begin();
    int high = 3;   
    main.insert(main.begin(), pend[0]);
    while (it != jacob.end()){
        if (it != jacob.begin() && *it > *(it - 1))
            high = high * 2 + 1;
        if (*it <= static_cast<int>(pend.size()) && *it != 1){
            int i = binarySearch(main, pend[*it - 1], high - 1);
            if (i != -1) {
                main.insert(main.begin() + i, pend[*it - 1]);
            }
        }
        it++;
    }
}

std::vector<int> getJacobNumbers(int pendingSize) {
    std::vector<int> jacobsthalNumbers;

    for (int i = 3; generateJacob(i) <= pendingSize; i++) {
        jacobsthalNumbers.push_back(generateJacob(i));
    }
    extendJacobNumbers(jacobsthalNumbers, pendingSize);
    return (jacobsthalNumbers);
}


std::vector<int> PmergeMe::sortVector(std::vector<int> &vector){
    PairVector  vectorPairs;
    std::vector<int>    main;
    std::vector<int>    pend;
    std::vector<int>    sortedMain;
    std::vector<int>    sortedPend;

    if (vector.size() == 0 || vector.size() == 1){
        return (vector);
    }

    if (vector.size() == 2) {
        if (vector[0] > vector[1])
            std::swap(vector[0], vector[1]);
        return (vector);
    }

    int isOdd = vector.size() % 2;
    int oddElement = 0;
    
    std::vector<int>::iterator it = vector.begin();
    while (it != vector.end()) {
        if (it + 1 == vector.end()) {
            oddElement = *it;
            break;
        }
        if (*it > *(it + 1)){
            vectorPairs.push_back(std::make_pair(*(it + 1), *it));
        } else {
            vectorPairs.push_back(std::make_pair(*it, *(it + 1)));
        }
        it += 2;
    }

    for (size_t i = 0; i < vectorPairs.size(); i++){
        main.push_back(vectorPairs[i].second);
        pend.push_back(vectorPairs[i].first);
    }
    if (isOdd) {
        pend.push_back(oddElement);
    }
    sortedMain = sortVector(main);

    sortedPend.resize(sortedMain.size());
    for (size_t i = 0; i < sortedMain.size(); i++) {
        for (size_t j = 0; j < main.size(); j++){
            if (main[j] == sortedMain[i]){
                sortedPend[i] = pend[j];
                break;
            }
        }
    }
    if (isOdd) {
        sortedPend.push_back(oddElement);
    }
    std::vector<int> jacobsthalNumbers = getJacobNumbers(sortedPend.size());
    sorting(sortedMain, sortedPend, jacobsthalNumbers);
    return (sortedMain);
}



void PmergeMe::sort(int argc, char **argv){
    parseAndValidatInput(argc, argv);
    std::vector<int> sorted = sortVector(vector);
    for (size_t i = 0; i < sorted.size(); i++)
    {
        std::cout << sorted[i] << " ";
    }
}