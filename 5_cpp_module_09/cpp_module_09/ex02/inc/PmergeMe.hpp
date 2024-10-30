#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>

class PmergeMe
{
private:
    static int binarySearch(const std::vector<int>& sortedSeq, int value);

public:
    PmergeMe();
    ~PmergeMe();
    static void mergeInsertionSort(std::vector<int>& arr);
};

void print_vector(const std::vector<int>& v);

namespace aec
{
    namespace fg
    {
        extern const char* BLACK;
        extern const char* RED;
        extern const char* GREEN;
        extern const char* YELLOW;
        extern const char* BLUE;
        extern const char* MAGENTA;
        extern const char* CYAN;
        extern const char* WHITE;
    }  // namespace fg
    namespace bg
    {
        extern const char* BLACK;
        extern const char* RED;
        extern const char* GREEN;
        extern const char* YELLOW;
        extern const char* BLUE;
        extern const char* MAGENTA;
        extern const char* CYAN;
        extern const char* WHITE;
    }  // namespace bg
    namespace st
    {
        extern const char* REGULAR;
        extern const char* BOLD;
        extern const char* FAINT;
        extern const char* ITALIC;
        extern const char* UNDERLINE;
        extern const char* BLINK;
        extern const char* RAPID_BLINK;
        extern const char* REVERSE;
        extern const char* HIDDEN;
        extern const char* STRIKE_THROUGH;
    }  // namespace st
    extern const char* RESET;
}  // namespace aec

#endif
