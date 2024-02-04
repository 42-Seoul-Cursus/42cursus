#include <iostream>
#include <list>
#include <vector>
#include "easyfind.hpp"

int	main()
{
	std::list<int> l;
	std::vector<int> v;
	
	for (size_t i = 0; i < 10; i++)
	{
		l.push_back(i + 1);
		v.push_back(i + 1);
	}

	try
	{
		std::cout << easyfind(l, 11) << std::endl;
		std::cout << easyfind(v, 5) << std::endl;
	}
	catch(const char* error)
	{
		std::cerr << error << std::endl;
	}
	
	return 0;
}
