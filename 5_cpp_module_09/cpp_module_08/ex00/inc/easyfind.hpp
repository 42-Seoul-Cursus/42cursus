#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

class NotFoundException : public std::exception
{
public:
    const char* what() const throw()
    {
        return "\033[0;31mNot Found\033[0m";
    }
};

template <typename T>
int easyfind(T& dst, int src)
{
    typename T::iterator it = std::find(dst.begin(), dst.end(), src);
    if (it == dst.end())
    {
        throw NotFoundException();
    }
    return *it;
}
#endif
