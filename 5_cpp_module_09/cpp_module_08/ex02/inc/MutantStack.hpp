#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack(void);
    MutantStack(const MutantStack<T>& rhs);
    ~MutantStack(void);
    const MutantStack<T>& operator=(const MutantStack<T>& rhs);
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin(void)
    {
        return this->c.begin();
    }
    iterator end(void)
    {
        return this->c.end();
    }
};

#endif
