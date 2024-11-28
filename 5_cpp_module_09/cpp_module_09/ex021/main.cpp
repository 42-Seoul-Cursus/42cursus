#include <iostream>
#include "Parser.hpp"
#include "PmergeMe.hpp"
#include "PmergeMeVector.hpp"
#include "Output.hpp"
#include <ctime>
#include "Utils.hpp"

int main(int argc, const char *argv[])
{
    if (argc < 2)
        return 0;

    try
    {
        std::vector<int> numbers = parse(ac, av);

        // --- deque ---
        {
            std::cout << "Before: ";
            printVector(numbers);

            PmergeMe pmerge;
            clock_t start = clock();
            std::deque<int> sortedDeque = pmerge.sorted(vectorToDeque(numbers));
            clock_t end = clock();

            std::cout << "After: ";
            printDeque(sortedDeque);

            double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
            printResult(numbers.size(), "std::deque", elapsedTime);
        }

        // --- vector ---
        {
            PmergeMeVector pmergeVector;
            clock_t start = clock();
            std::vector<int> sortedVector = pmergeVector.sorted(numbers);
            clock_t end = clock();

            std::cout << "After: ";
            printVector(sortedVector);

            double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
            printResult(numbers.size(), "std::vector", elapsedTime);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
