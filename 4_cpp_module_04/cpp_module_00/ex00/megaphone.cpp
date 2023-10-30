#include <iostream>

int main(int ac, char const *av[])
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; av[i][j] != '\0'; j++)
		{
			if ('a' <= av[i][j] && av[i][j] <= 'z')
				std::cout << (char)(av[i][j] - 32);
			else
				std::cout << (char)av[i][j];
		}
	}
	std::cout << std::endl;
	return 0;
}