#include <iostream>
#include <fstream>
#include <string>

static void WriteOriginalContentToFile(std::ifstream& readFile, std::ofstream& writeFile, std::string s1, std::string s2);
static void WriteReplaceContentToFile(std::ifstream& readFile, std::ofstream& writeFile);

int main(int ac, char const *av[])
{
	if (ac != 4)
	{
		std::cout << "\033[37mUsage: ./replace filename s1 s2\n";
		return 1;
	}

	std::ifstream readFile(av[1]);
	if (!readFile)
	{
		std::cerr << "\033[31mError: Unable to open input file \'" << av[1] << '\'' << std::endl;
		return 1;
	}

	std::ofstream writeFile(std::string(av[1]).append(".replace").c_str());
	if (!writeFile)
	{
		std::cerr << "\033[31mError: Unable to open output file \'" << av[1] << ".replace\'" << std::endl;
		return 1;
	}

	if (static_cast<std::string>(av[2]) != static_cast<std::string>(av[3]))
	{
		WriteOriginalContentToFile(readFile, writeFile, av[2], av[3]);
	}
	else
	{
		WriteReplaceContentToFile(readFile, writeFile);
	}

	return 0;
}

static void WriteOriginalContentToFile(std::ifstream& readFile, std::ofstream& writeFile, std::string s1, std::string s2)
{
	int beforeLen = 0;

	while (s1[beforeLen])
	{
		++beforeLen;
	}

	while (!readFile.eof())
	{
		std::string line;
		std::string replace("");

		std::getline(readFile, line);
		size_t idx = line.find(s1);

		while (idx != std::string::npos)
		{
			replace += line.substr(0, idx);
			replace += s2;
			replace += line.substr(idx + beforeLen);
			line = replace;
			idx = line.find(s1);
			replace = "";
		}

		if (!readFile.eof())
		{
			line.append("\n");
		}

		writeFile.write(line.c_str(), line.length());
	}
}

static void WriteReplaceContentToFile(std::ifstream& readFile, std::ofstream& writeFile)
{
	while (!readFile.eof())
	{
		std::string line;

		std::getline(readFile, line);
		if (!readFile.eof())
		{
			line.append("\n");
		}
		writeFile.write(line.c_str(), line.length());
	}
}
