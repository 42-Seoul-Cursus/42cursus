#include "string"
#include "ScalarConverter.hpp"

#include <iostream>
int	main(int ac, char *av[])
{
	for (int i = 1; i < ac; i++)
	{
		std::string input = av[i];
		ScalarConverter::Convert(input);
	}

	float f = INFINITY;
	std::cout << f << std::endl;
	return 0;
}
