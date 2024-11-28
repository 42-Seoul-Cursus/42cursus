#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>

class PmergeMe
{
private:
    std::vector<int> mInputVec;

    PmergeMe();
    PmergeMe(const PmergeMe& rhs);
    PmergeMe& operator=(const PmergeMe& rhs);

public:
    PmergeMe(int ac, const char** av);
    ~PmergeMe();
    void run();
};

/* ANSI Escape Codes */
namespace aec
{
    namespace fg
    {
        const std::string BLACK = "\033[30m";
        const std::string RED = "\033[31m";
        const std::string GREEN = "\033[32m";
        const std::string YELLOW = "\033[33m";
        const std::string BLUE = "\033[34m";
        const std::string MAGENTA = "\033[35m";
        const std::string CYAN = "\033[36m";
        const std::string WHITE = "\033[37m";
    }  // namespace fg
    namespace bg
    {
        const std::string BLACK = "\033[40m";
        const std::string RED = "\033[41m";
        const std::string GREEN = "\033[42m";
        const std::string YELLOW = "\033[43m";
        const std::string BLUE = "\033[44m";
        const std::string MAGENTA = "\033[45m";
        const std::string CYAN = "\033[46m";
        const std::string WHITE = "\033[47m";
    }  // namespace bg
    namespace st
    {
        const std::string REGULAR = "\033[0m";
        const std::string BOLD = "\033[1m";
        const std::string FAINT = "\033[2m";
        const std::string ITALIC = "\033[3m";
        const std::string UNDERLINE = "\033[4m";
        const std::string BLINK = "\033[5m";
        const std::string RAPID_BLINK = "\033[6m";
        const std::string REVERSE = "\033[7m";
        const std::string HIDDEN = "\033[8m";
        const std::string STRIKE_THROUGH = "\033[9m";
    }  // namespace st
    const std::string RESET = "\033[0m";
}  // namespace aec

void printVec(const std::vector<int>& vec);

#endif
