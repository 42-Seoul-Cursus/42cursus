#include "Utils.hpp"
#include <sstream>

int strToInt(const std::string &str)
{
    std::stringstream ss(str);
    int result;

    if (!(ss >> result) || !ss.eof())
        throw std::invalid_argument("fail to convert str to int");
    return result;
}

std::deque<int> vectorToDeque(const std::vector<int> &vec)
{
    return std::deque<int>(vec.begin(), vec.end());
}

std::vector<int> oneIndexedToZeroIndexed(const std::vector<int> &oneIndexed)
{
    std::vector<int> zeroIndexed;
    for (size_t i = 0; i < oneIndexed.size(); ++i)
        zeroIndexed.push_back(oneIndexed[i] - 1);

    return zeroIndexed;
}

std::vector<int> generateInsertionOrder(int n)
{
    std::vector<int> insertionOrder;
    std::deque<int> Jooncobsthal = generateJooncobsthalSequence(n);

    int pivot = 0;
    for (size_t i = 0; i < Jooncobsthal.size(); i++)
    {
        for (int order = Jooncobsthal[i]; order > pivot; --order)
            insertionOrder.push_back(order);
        pivot = Jooncobsthal[i];
    }

    for (int i = n; i > pivot; --i)
        insertionOrder.push_back(i);

    return oneIndexedToZeroIndexed(insertionOrder);
}

std::deque<int> generateJooncobsthalSequence(int n)
{
    std::deque<int> Jooncobsthal;
    Jooncobsthal.push_back(1);

    int i = 1;
    while (true)
    {
        int value = (1 << (i + 1)) - Jooncobsthal[i - 1];
        if (value > n)
            break;
        Jooncobsthal.push_back(value);
        ++i;
    }

    return Jooncobsthal;
}