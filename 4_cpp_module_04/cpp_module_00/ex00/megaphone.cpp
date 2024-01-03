#include <iostream>

int main(int ac, char const *av[])
{
	std::string s;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	for (int i = 1; i < ac; i++)
	{
		s = av[i];
		for (size_t j = 0; j < s.length(); j++)
		{
			std::cout << static_cast<char>(toupper(s[j]));
		}
	}
	std::cout << std::endl;
	return 0;
}
