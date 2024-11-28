#pragma once

#include <utility>
#include <string>
#include <exception>
#include <deque>
#include <utility>

struct PmergeMe
{
public:
    std::deque<int> sorted(const std::deque<int> &original);

private:
    void pairwiseComparison(const std::deque<int> &original, std::deque<int> &mainList, std::deque<int> &pendingList);
    HashTable createMapping(const std::deque<int> &mainList, const std::deque<int> &pendingList);
    std::deque<int> reorderedPendingList(const std::deque<int> &mainList, const std::deque<int> &pendingList, const HashTable &mappingDatas);

    void insertPendingToResult(std::deque<int> &result, const std::deque<int> &pendingList);
    void binaryInsert(std::deque<int> &result, int target, int range);
};
