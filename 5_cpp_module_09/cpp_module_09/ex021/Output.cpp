#include "Output.hpp"
#include <iostream>

void printDeque(std::deque<int> deque)
{
    for (size_t i = 0; i < deque.size(); i++)
    {
        std::cout << deque[i];
        if (i != deque.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void printVector(std::vector<int> vector)
{
    for (size_t i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i];
        if (i != vector.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void printResult(int range, const std::string &containerType, double elapsedTime)
{
    std::cout << "Time to process a range of " << range
              << " elements with " << containerType << ": " << elapsedTime << " us\n";
}
