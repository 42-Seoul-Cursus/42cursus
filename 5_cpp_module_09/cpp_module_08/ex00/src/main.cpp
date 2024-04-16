#include <iostream>
#include <list>
#include <vector>
#include <stack>
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
		std::cout << easyfind(l, 10) << std::endl;
		std::cout << easyfind(v, 1) << std::endl;
		std::cout << easyfind(v, 0) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}
