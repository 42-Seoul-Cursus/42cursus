#include <iostream>
#include "RPN.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << aec::fg::YELLOW << "Usage: " << argv[0] << " <RPN expression>" << aec::RESET << std::endl;
        return 1;
    }
    RPN rpn(argv[1]);

    try
    {
        int res = rpn.Evaluate();
        std::cout << aec::fg::GREEN << res << aec::RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << aec::fg::RED << e.what() << aec::RESET << std::endl;
    }
    
    return 0;
}
