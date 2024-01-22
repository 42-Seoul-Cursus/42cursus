#ifndef EASYFIND_HPP
#define EASYFIND_HPP

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
	throw std::exception();
}
#endif
