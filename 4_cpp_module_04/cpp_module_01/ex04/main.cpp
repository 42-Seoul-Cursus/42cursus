#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char const *av[])
{
	if (ac != 4)
	{
		std::cout << "Usage: ./replace filename s1 s2\n";
		return 1;
	}

	std::ifstream ifs(av[1]);
	if (!ifs)
	{
		std::cerr << "Error!" << std::endl;
		return 1;
	}

	std::string file;
	ifs >> file;
	for (int i = 0; i < 100; i++)
	{
		std::cout << file << '\n';
		ifs >> file;
	}


	return 0;
}
