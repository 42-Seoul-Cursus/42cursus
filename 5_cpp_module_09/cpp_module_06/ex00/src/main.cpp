#include "ScalarConverter.hpp"

int	main(int ac, char *av[])
{
	for (int i = 1; i < ac; i++)
	{
		std::string input = av[i];
		ScalarConverter::Convert(input);
	}
	return 0;
}
