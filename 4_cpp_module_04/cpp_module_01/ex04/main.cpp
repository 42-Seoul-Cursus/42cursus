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

	std::ifstream readFile(av[1]);
	if (!readFile)
	{
		std::cerr << "Error!" << std::endl;
		return 1;
	}

	std::string fileName = av[1];
	fileName.append(".replace");

	std::ofstream writeFile(fileName);

	while (!readFile.eof())
	{
		std::string line;

		std::getline(readFile, line);

		/* line에서 문자열 s1을 s2로 바꿔주는 작업 */
		while (line.find(av[2]) != std::string::npos)
		{
			int len = 0;
			while (av[2][len] != '\0')
			{
				++len;
			}
			line.replace(line.find(av[2]), len, av[3]);
		}
		/* --------------------------------------- */

		if (!readFile.eof())
		{
			line.append("\n");
		}
		writeFile.write(line.c_str(), line.length());
	}

	return 0;
}
