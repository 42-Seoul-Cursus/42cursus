#pragma once

#include <utility>
#include <string>
#include <exception>
#include <utility>
#include "HashTable.hpp"

struct PmergeMeVector
{
public:
    std::vector<int> sorted(const std::vector<int> &original);

private:
    void pairwiseComparison(const std::vector<int> &original, std::vector<int> &mainList, std::vector<int> &pendingList);
    HashTable createMapping(const std::vector<int> &mainList, const std::vector<int> &pendingList);
    std::vector<int> reorderedPendingList(const std::vector<int> &mainList, const std::vector<int> &pendingList, const HashTable &mappingDatas);

    void insertPendingToResult(std::vector<int> &result, const std::vector<int> &pendingList);
    void binaryInsert(std::vector<int> &result, int target, int range);
};