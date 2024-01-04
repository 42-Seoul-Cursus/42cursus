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

	// 파일 읽기
	std::ifstream readFile(av[1]);
	if (!readFile)
	{
		std::cerr << "\033[31mFile open error" << std::endl;
		return 1;
	}

	std::string fileName = av[1];
	fileName.append(".replace");

	// 파일 쓰기
	std::ofstream writeFile(fileName);

	int beforeLen = 0;

	while (av[2][beforeLen])
	{
		++beforeLen;
	}

	while (!readFile.eof())
	{
		std::string line;
		std::string replace("");

		std::getline(readFile, line);
		size_t idx = line.find(av[2]);

		if (idx != std::string::npos)
		{
			replace += line.substr(0, idx);
			replace += av[3];
			replace += line.substr(idx + beforeLen);
			line = replace;
		}

		if (!readFile.eof())
		{
			line.append("\n");
		}
		writeFile.write(line.c_str(), line.length());
	}

	return 0;
}
