#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, const char *argv[])
{
    try
    {
        PmergeMe pmm(argc, argv);
        pmm.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
