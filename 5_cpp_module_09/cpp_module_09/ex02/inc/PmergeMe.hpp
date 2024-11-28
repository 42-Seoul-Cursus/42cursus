#ifndef PMERGEME_HPP
#define PMERGEME_HPP

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
    std::deque<int> sorted(const std::deque<int> &sequence);
    void makePairChains(const std::deque<int> &sequence, std::deque<int> &mainChain, std::deque<int> &subChain);
    HashTable mapping(const std::deque<int> &mainChain, const std::deque<int> &subChain);
    std::deque<int> reorderedSubChain(const std::deque<int> &mainChain, const std::deque<int> &subChain, const HashTable &mappingDatas);
    void insertSubChainToMainChain(std::deque<int> &mainChain, const std::deque<int> &subChain);
    void binaryInsert(std::deque<int> &result, int target, int range);

    // Vector
    std::vector<int> sorted(const std::vector<int> &sequence);
    void makePairChains(const std::vector<int> &sequence, std::vector<int> &mainChain, std::vector<int> &subChain);
    HashTable mapping(const std::vector<int> &mainChain, const std::vector<int> &subChain);
    std::vector<int> reorderedSubChain(const std::vector<int> &mainChain, const std::vector<int> &subChain, const HashTable &mappingDatas);
    void insertSubChainToMainChain(std::vector<int> &mainChain, const std::vector<int> &subChain);
    void binaryInsert(std::vector<int> &result, int target, int range);

    void generateJacobsthalSequence(int n);
    std::vector<int> createInsertionIndex(int n);

public:
    PmergeMe(int ac, const char* av[]);
    ~PmergeMe();
    void run();
};

void printVector(const std::vector<int>& vector);
void printDeque(const std::deque<int>& deque);

#endif
