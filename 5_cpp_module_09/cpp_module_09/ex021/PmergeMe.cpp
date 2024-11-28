#include "PmergeMe.hpp"
#include "Utils.hpp"
#include <utility>
#include <string>
#include <exception>
#include <deque>
#include <vector>
#include <algorithm>

std::deque<int> PmergeMe::sorted(const std::deque<int> &original)
{
    if (original.size() <= 1)
        return original;

    std::deque<int> mainList;
    std::deque<int> pendingList;

    pairwiseComparison(original, mainList, pendingList);
    HashTable mappingDatas = createMapping(mainList, pendingList);

    mainList = sorted(mainList);
    pendingList = reorderedPendingList(mainList, pendingList, mappingDatas);

    std::deque<int> result(mainList);
    insertPendingToResult(result, pendingList);

    return result;
}

void PmergeMe::pairwiseComparison(const std::deque<int> &original, std::deque<int> &mainList, std::deque<int> &pendingList)
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

HashTable PmergeMe::createMapping(const std::deque<int> &mainList, const std::deque<int> &pendingList)
{
    HashTable mappingDatas(mainList.size());

    for (size_t i = 0; i < mainList.size(); ++i)
        mappingDatas.insert(mainList[i], pendingList[i]);

    return mappingDatas;
}

std::deque<int> PmergeMe::reorderedPendingList(const std::deque<int> &mainList, const std::deque<int> &pendingList, const HashTable &mappingDatas)
{
    std::deque<int> reorderedPendingList;

    for (size_t i = 0; i < mainList.size(); ++i)
    {
        int target = mappingDatas.get(mainList[i]);
        reorderedPendingList.push_back(target);
    }

    if (pendingList.size() > mainList.size())
        reorderedPendingList.push_back(pendingList.back());

    return reorderedPendingList;
}

void PmergeMe::insertPendingToResult(std::deque<int> &result, const std::deque<int> &pendingList)
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

void PmergeMe::binaryInsert(std::deque<int> &result, int target, int range)
{
    std::deque<int>::iterator end = result.begin() + range;
    end = std::min(end, result.end());

    std::deque<int>::iterator insertPos = std::lower_bound(result.begin(), end, target);
    result.insert(insertPos, target);
}