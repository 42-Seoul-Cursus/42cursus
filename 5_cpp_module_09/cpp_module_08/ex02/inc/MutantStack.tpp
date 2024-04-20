#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void)
: std::stack<T>()
{
}
template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& rhs)
: std::stack<T>(rhs)
{
}
template <typename T>
MutantStack<T>::~MutantStack(void)
{
}
template <typename T>
const MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return *this;
}
