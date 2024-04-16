#ifndef EASYFIND_HPP
#define EASYFIND_HPP

class NotFoundException : public std::exception 
{
public:
    const char* what() const throw() 
    {
        return "\033[0;31mNot Found\033[0m";
    }
};

template <typename T>
int	easyfind(T& dst, int src)
{
    for (typename T::iterator it = dst.begin(); it != dst.end(); ++it)
    {
        if (*it == src)
        {
            return src;
        }
    }
    throw NotFoundException();
}
#endif
