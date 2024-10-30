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

#endif
