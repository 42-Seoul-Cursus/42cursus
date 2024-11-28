#include "PmergeMeVector.hpp"
#include "Utils.hpp"
#include <utility>
#include <string>
#include <exception>
#include <vector>
#include <algorithm>

std::vector<int> PmergeMeVector::sorted(const std::vector<int> &original)
{
    if (original.size() <= 1)
        return original;

    std::vector<int> mainList;
    std::vector<int> pendingList;

    pairwiseComparison(original, mainList, pendingList);
    HashTable mappingDatas = createMapping(mainList, pendingList);

    mainList = sorted(mainList);
    pendingList = reorderedPendingList(mainList, pendingList, mappingDatas);

    std::vector<int> result(mainList);
    insertPendingToResult(result, pendingList);

    return result;
}

void PmergeMeVector::pairwiseComparison(const std::vector<int> &original, std::vector<int> &mainList, std::vector<int> &pendingList)
{
    for (size_t i = 0; i + 1 < original.size(); i += 2)
    {
        int large = std::max(original[i], original[i + 1]);
        int small = std::min(original[i], original[i + 1]);

        mainList.push_back(large);
        pendingList.push_back(small);
    }

    if (original.size() % 2 == 1)
        pendingList.push_back(original.back());
}

HashTable PmergeMeVector::createMapping(const std::vector<int> &mainList, const std::vector<int> &pendingList)
{
    HashTable mappingDatas(mainList.size());

    for (size_t i = 0; i < mainList.size(); ++i)
        mappingDatas.insert(mainList[i], pendingList[i]);

    return mappingDatas;
}

std::vector<int> PmergeMeVector::reorderedPendingList(const std::vector<int> &mainList, const std::vector<int> &pendingList, const HashTable &mappingDatas)
{
    std::vector<int> reorderedPendingList;

    for (size_t i = 0; i < mainList.size(); ++i)
    {
        int target = mappingDatas.get(mainList[i]);
        reorderedPendingList.push_back(target);
    }

    if (pendingList.size() > mainList.size())
        reorderedPendingList.push_back(pendingList.back());

    return reorderedPendingList;
}

void PmergeMeVector::insertPendingToResult(std::vector<int> &result, const std::vector<int> &pendingList)
{
    std::vector<int> insertionOrder = generateInsertionOrder(pendingList.size());

    int insertionCnt = 0;
    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        int targetIndex = insertionOrder[i];
        int target = pendingList[targetIndex];
        int range = insertionCnt + targetIndex;
        binaryInsert(result, target, range);
        insertionCnt++;
    }
}

void PmergeMeVector::binaryInsert(std::vector<int> &result, int target, int range)
{
    std::vector<int>::iterator end = result.begin() + range;
    end = std::min(end, result.end());

    std::vector<int>::iterator insertPos = std::lower_bound(result.begin(), end, target);
    result.insert(insertPos, target);
}