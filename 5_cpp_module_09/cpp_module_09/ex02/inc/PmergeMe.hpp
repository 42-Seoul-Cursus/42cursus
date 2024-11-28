#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe
{
private:
    std::vector<int> mJacobstalNums;
    std::vector<int> mVector;
    std::deque<int> mDeque;

    PmergeMe();
    PmergeMe(const PmergeMe& rhs);
    PmergeMe& operator=(const PmergeMe& rhs);

public:
    PmergeMe(int ac, const char** av);
    ~PmergeMe();
    void run();
};

void printVector(const std::vector<int>& vector);
void printDeque(const std::deque<int>& deque);

#endif
