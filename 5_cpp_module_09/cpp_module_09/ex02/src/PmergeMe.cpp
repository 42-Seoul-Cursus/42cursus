#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <set>
#include <sstream>

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

PmergeMe::PmergeMe(int ac, const char** av)
: mInputVec(ac - 1)
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
                mInputVec[i - 1] = d;
                dupCheck.insert(d);
                iss.clear();
            }
            else
            {
                throw std::invalid_argument(aec::fg::RED + "Error: " + av[i] + +" is a duplicate." + aec::RESET);
            }
        }
        else
        {
            throw std::invalid_argument(aec::fg::RED + "Error: " + av[i] + +" is not a positive integer." + aec::RESET);
        }
    }
}

PmergeMe::~PmergeMe()
{
}
void PmergeMe::run()
{
    printVec(mInputVec);
}
void printVec(const std::vector<int>& vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}
