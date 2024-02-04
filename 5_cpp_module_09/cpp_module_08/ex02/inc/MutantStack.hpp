#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
public:
	class iterator : public std::deque<T>::iterator 
	{
		iterator(typename std::deque<T>::iterator it) : std::deque<T>::iterator(it) {}
	};
	iterator begin() 
	{
        return c.begin();
    }
    iterator end() 
	{
        return c.end();
    }
};

#include "MutantStack.tpp"

#endif
