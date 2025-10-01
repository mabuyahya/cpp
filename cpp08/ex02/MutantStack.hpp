#ifndef MUTANTSTACK_HPP 
#define MUTANTSTACK_HPP 

#include <stack>
#include <deque>


template <typename T>
class MutantStack :public std::stack<T>
{
    public:
        typedef typename std::deque<T>::iterator  iterator;


        MutantStack(): std::stack<T>(){
        }
        MutantStack(const MutantStack &other): std::stack<T>(other){
        }
        MutantStack& operator=(const MutantStack &other){
            std::stack<T>::operator=(other);
            return(*this);
        }
        ~MutantStack(){
        }

        iterator    begin(){
            return(this->c.begin());
        }
        iterator    end(){
            return(this->c.end());
        }
};





#endif