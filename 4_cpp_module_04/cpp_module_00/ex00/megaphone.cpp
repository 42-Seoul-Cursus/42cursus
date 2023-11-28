#include <iostream>

static void PrintLowerToUpper(const char c)
{
	if ('a' <= c && c <= 'z')
	{
		std::cout << (char)(c - 32);
	}
	else
	{
		std::cout << (char)c;
	}
}

int main(int ac, char const *av[])
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; av[i][j] != '\0'; j++)
		{
			PrintLowerToUpper(av[i][j]);
		}
	}
	std::cout << std::endl;
	return 0;
}
