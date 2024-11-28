#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " [positive integer] ..." << std::endl;
        return 1;
    }
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
