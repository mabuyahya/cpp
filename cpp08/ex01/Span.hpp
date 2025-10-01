#ifndef SPAN_HPP 
#define SPAN_HPP 

#include <vector>
#include <algorithm>
#include <iterator>
#include <exception>

class Span{
    private:
        unsigned int    size;
        std::vector<int> myArr;

    public:
        Span();
        ~Span();
        Span(const Span &);
        Span &operator=(const Span &);

        Span(unsigned int);
        void    addNumber(int );
        void    addNumberViaRange(std::vector<int>::iterator first, std::vector<int>::iterator last);
        int shortestSpan();
        int longestSpan();


        class SpanIsFull: public std::exception{
            public:
                const char *what() const throw();
        };
        class canNotFindSpan: public std::exception{
            public:
                const char *what() const throw();
        };
    private:
        int getLargest();
        int getSmallest(int, int);
};




#endif