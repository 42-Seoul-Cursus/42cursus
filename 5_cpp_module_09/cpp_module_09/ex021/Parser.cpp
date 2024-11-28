#include "Parser.hpp"
#include "Utils.hpp"
#include <string>

std::vector<int> parse(int ac, char *av[])
{
    std::vector<int> v;
    try
    {
        for (int i = 1; i < ac; i++)
        {
            int num = strToInt(av[i]);
            if (num < 1)
                throw ParsingError();
            v.push_back(num);
        }
    }
    catch (const std::invalid_argument &e)
    {
        throw ParsingError();
    }

    return v;
}

const char *ParsingError::what() const throw()
{
    return "Error";
}