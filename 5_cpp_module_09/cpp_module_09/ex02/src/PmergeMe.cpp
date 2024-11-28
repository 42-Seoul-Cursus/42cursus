#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <set>
#include <sstream>
#include <iostream>

static bool isPositiveInteger(const std::string& str)
{
    if (str.empty() || (str[0] == '0' && str.length() > 1))
    {
        return false;
    }
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

PmergeMe::PmergeMe(int ac, const char* av[])
: mVector(ac - 1)
, mDeque(ac - 1)
{
    std::istringstream iss;
    std::string str;
    std::set<int> dupCheck;
    double d;

    for (size_t i = 1; i < ac; i++)
    {
        str = av[i];

        if (isPositiveInteger(str))
        {
            iss.str(str);
            iss >> d;
            if (dupCheck.find(d) == dupCheck.end())
            {
                mVector[i - 1] = d;
                mDeque[i - 1] = d;
                dupCheck.insert(d);
                iss.clear();
            }
            else
            {
                throw std::invalid_argument("Error: " + str + " is a duplicate.");
            }
        }
        else
        {
            throw std::invalid_argument("Error: " + str + " is not a positive integer.");
        }
    }
}

PmergeMe::~PmergeMe()
{
}
void PmergeMe::run()
{
    printVector(mVector);
    printDeque(mDeque);
}
void printVector(const std::vector<int>& vector)
{
    for (size_t i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}
void printDeque(const std::deque<int>& deque)
{
    for (size_t i = 0; i < deque.size(); i++)
    {
        std::cout << deque[i] << " ";
    }
    std::cout << std::endl;
}
