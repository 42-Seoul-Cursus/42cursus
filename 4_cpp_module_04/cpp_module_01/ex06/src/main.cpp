#include <iostream>
#include "Harl.hpp"

static int GetLevel(std::string s);

int main(int ac, const char *av[])
{
	if (ac != 2)
	{
		std::cerr << "\033[0;31mUsage: ./harlFilter LEVEL\033[0m" << std::endl;
		return 1;
	}

	Harl harl;
	int level = GetLevel(static_cast<std::string>(av[1]));

	switch (level)
	{
	case DEBUG:
		std::cout << "[ DEBUG ]" << std::endl;
		harl.complain("DEBUG");
	case INFO:
		std::cout << "[ INFO ]" << std::endl;
		harl.complain("INFO");
	case WARNING:
		std::cout << "[ WARNING ]" << std::endl;
		harl.complain("WARNING");
	case ERROR:
		std::cout << "[ ERROR ]" << std::endl;
		harl.complain("ERROR");
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return 0;
}

static int GetLevel(std::string s)
{
	if (s == "DEBUG")
	{
		return 4;
	}
	if (s == "INFO")
	{
		return 3;
	}
	if (s == "WARNING")
	{
		return 2;
	}
	if (s == "ERROR")
	{
		return 1;
	}
	return 0;
}
