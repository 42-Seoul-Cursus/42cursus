#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include "HashTable.hpp"

class PmergeMe
{
private:
    std::vector<int> mVector;
    std::deque<int> mDeque;
    std::vector<int> mJacobsthalNumbers;

    PmergeMe();
    PmergeMe(const PmergeMe& rhs);
    PmergeMe& operator=(const PmergeMe& rhs);

    // Deque
    std::deque<int> sorted(const std::deque<int> &original);
    void pairwiseComparison(const std::deque<int> &original, std::deque<int> &mainList, std::deque<int> &pendingList);
    HashTable createMapping(const std::deque<int> &mainList, const std::deque<int> &pendingList);
    std::deque<int> reorderedPendingList(const std::deque<int> &mainList, const std::deque<int> &pendingList, const HashTable &mappingDatas);
    void insertPendingToResult(std::deque<int> &result, const std::deque<int> &pendingList);
    void binaryInsert(std::deque<int> &result, int target, int range);

    // Vector
    std::vector<int> sorted(const std::vector<int> &original);
    void pairwiseComparison(const std::vector<int> &original, std::vector<int> &mainList, std::vector<int> &pendingList);
    HashTable createMapping(const std::vector<int> &mainList, const std::vector<int> &pendingList);
    std::vector<int> reorderedPendingList(const std::vector<int> &mainList, const std::vector<int> &pendingList, const HashTable &mappingDatas);
    void insertPendingToResult(std::vector<int> &result, const std::vector<int> &pendingList);
    void binaryInsert(std::vector<int> &result, int target, int range);

    void generateJacobsthalSequence(int n);
    std::vector<int> generateInsertionOrder(int n);

public:
    PmergeMe(int ac, const char* av[]);
    ~PmergeMe();
    void run();
};

void printVector(const std::vector<int>& vector);
void printDeque(const std::deque<int>& deque);

#endif
