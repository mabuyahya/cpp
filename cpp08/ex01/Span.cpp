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
    std::vector<int> temp = myArr;
    std::sort(temp.begin(), temp.end());
    return(temp.at(temp.size() - 1) - temp.front());
}

int Span::shortestSpan(){
    if (myArr.size() <= 1)
        throw Span::canNotFindSpan();
    std::vector<int> temp = myArr;
    std::sort(temp.begin(), temp.end());
    int smallest = temp.at(1) - temp.front();
    for (size_t i = 1; i < temp.size(); i++)
    {
        if (temp.at(i) - temp.at(i - 1) < smallest)
            smallest = temp.at(i) - temp.at(i - 1);
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