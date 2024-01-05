#include "Harl.hpp"

static size_t hashCode(const char* str)
{
	size_t hash = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		hash = (hash + str[0]) % 10000;
		++i;
	}
	return hash ^ (hash >> 16);
}

int main(int ac, const char *av[])
{
	if (ac != 2)
	{
		std::cerr << "\033[0;31mUsage: ./harlFilter LEVEL\033[0m;";
		return 1;
	}

	Harl harl;
	size_t hash = hashCode(av[1]);

	std::cout << hash << std::endl;
	switch (hash)
	{
	case /* constant-expression */:
		std::cout << "[ DEBUG ]\n";
		harl.complain("DEBUG");
		break;
	case /* constant-expression */:
		std::cout << "[ INFO ]\n";
		harl.complain("INFO");
		break;
	case /* constant-expression */:
		std::cout << "[ WARNING ]\n";
		harl.complain("WARNING");
		break;
	case /* constant-expression */:
		std::cout << "[ ERROR ]\n";
		harl.complain("ERROR");
		break;

	default:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
	return 0;
}
