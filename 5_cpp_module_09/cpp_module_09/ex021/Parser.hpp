#pragma once

#include <vector>
#include <exception>

std::vector<int> parse(int ac, char *av[]);

class ParsingError : public std::exception
{
public:
    virtual const char *what() const throw();
};