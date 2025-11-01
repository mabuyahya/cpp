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

    // Step 1: use the Jacobsthal numbers to fill extendedJacobsthalNumbers
    while (i < jacobsthalNumbers.size()) {
        val = jacobsthalNumbers[i];
        while (val > 0 && val <= pendingSize) {
            if (std::find(extendedJacobsthalNumbers.begin(), extendedJacobsthalNumbers.end(), val) == extendedJacobsthalNumbers.end())
                extendedJacobsthalNumbers.push_back(val);
            val--;
        }
        i++;
    }

    // Step 2: fill in any missing indices from pendingSize down to 1
    int j = pendingSize;
    while (j > 0) {
        if (std::find(extendedJacobsthalNumbers.begin(), extendedJacobsthalNumbers.end(), j) == extendedJacobsthalNumbers.end())
            extendedJacobsthalNumbers.push_back(j);
        j--;
    }

    // Step 3: replace original vector
    jacobsthalNumbers = extendedJacobsthalNumbers;
}


  std::vector<int> getJacobNumbers(int pendingSize) {
    std::vector<int> jacobsthalNumbers;

    for (int i = 3; generateJacob(i) <= pendingSize; i++) {
        jacobsthalNumbers.push_back(generateJacob(i));
    }

    std::cout << "Initial jacobsthal numbers:";
    for (size_t i = 0; i < jacobsthalNumbers.size(); i++)
    {
        std::cout << jacobsthalNumbers[i] << " ";
    }
    std::cout << "\n";

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
    sortedMain = main;//sortVector(main);

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
    std::cout << "pend :";
    for (size_t i = 0; i < pend.size(); i++)
    {
        std::cout << pend[i] << " ";
    }
    std::cout << "\n";
    std::cout << "jacob :";
    for (size_t i = 0; i < jacobsthalNumbers.size(); i++)
    {
        std::cout << jacobsthalNumbers[i] << " ";
    }
    std::cout << "\n";
    return (sortedMain);
}



void PmergeMe::sort(int argc, char **argv){
    parseAndValidatInput(argc, argv);
    std::vector<int> sorted = sortVector(vector);
}