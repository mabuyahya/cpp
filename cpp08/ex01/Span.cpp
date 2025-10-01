#include "Span.hpp"

Span::Span(){
    size = 0;
}

Span::~Span(){}

Span::Span(const Span &tt){
    size = tt.size;
    myArr = tt.myArr;
}

Span &Span::operator=(const Span &tt){
    if (this != &tt){
        size = tt.size;
        myArr = tt.myArr;
    }
    return (*this);
}

Span::Span(unsigned int size){
    this->size = size;
}

void Span::addNumber(int num){
    if (myArr.size() >= size)
        throw Span::SpanIsFull();
    myArr.push_back(num);
}

int Span::longestSpan(){
    if (myArr.size() <= 1)
        throw Span::canNotFindSpan();
    return(getLargest() - getSmallest(0, 1));
}

int Span::shortestSpan(){
    if (myArr.size() <= 1)
        throw Span::canNotFindSpan();
    int temp = getSmallest(0, 1);
    return (getSmallest(temp, 0) - temp);
}

int Span::getLargest(){
    int largest = myArr.front();
    for (std::vector<int>::iterator it = myArr.begin(); it != myArr.end(); it++){
        if (*it > largest)
            largest = *it;
    }
    return (largest);
}

int Span::getSmallest(int num, int flag){
    int smallest = myArr.front();
    for (std::vector<int>::iterator it = myArr.begin(); it != myArr.end(); it++){
        if (*it < smallest && (*it != num || flag))
            smallest = *it;
    }
    return (smallest);
}

void Span::addNumberViaRange(std::vector<int>::iterator first, std::vector<int>::iterator last){
    if (myArr.size() + std::distance(first, last) > size)
        throw Span::SpanIsFull();
    myArr.insert(myArr.end(), first, last);
}

const  char *Span::SpanIsFull::what()const throw(){
    return "there are no space in the span\n";
}

const  char *Span::canNotFindSpan::what()const throw(){
    return "span does not have enough numbers\n";
}