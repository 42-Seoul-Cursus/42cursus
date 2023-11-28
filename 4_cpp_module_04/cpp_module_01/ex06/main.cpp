#include "Karen.hpp"

int main(int ac, const char *av[])
{
	if (ac != 2)
	{
		std::cerr << "[ Probably complaining about insignificant problems ]\n";
		return 1;
	}
	std::string s = av[1];
	int level = 0;

	if (s == "DEBUG")
	{
		level = 4;
	}
	if (s == "INFO")
	{
		level = 3;
	}
	if (s == "WARNING")
	{
		level = 2;
	}
	if (s == "ERROR")
	{
		level = 1;
	}

	Karen karen;

	if (level >= 4)
	{
		std::cout << "[ DEBUG ]\n";
		karen.complain("debug");
	}
	if (level >= 3)
	{
		std::cout << "[ INFO ]\n";
		karen.complain("info");
	}
	if (level >= 2)
	{
		std::cout << "[ WARNING ]\n";
		karen.complain("warning");
	}
	if (level >= 1)
	{
		std::cout << "[ ERROR ]\n";
		karen.complain("error");
	}
	if (level == 0)
	{
		std::cerr << "[ Probably complaining about insignificant problems ]\n";
	}
	return 0;
}
