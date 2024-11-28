#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <ctime>
#include <set>
#include <sstream>
#include <iostream>

static bool isPositiveInteger(const std::string& str);
static std::vector<int> oneIndexedToZeroIndexed(const std::vector<int> &oneIndexed);

PmergeMe::PmergeMe(int ac, const char* av[])
: mVector(ac - 1)
, mDeque(ac - 1)
, mJacobsthalNumbers()
{
    std::istringstream iss;
    std::string str;
    std::set<int> dupCheck;
    double d;

    for (size_t i = 1; i < ac; i++)
    {
        str = av[i];

        if (isPositiveInteger(str))
        {
            iss.str(str);
            iss >> d;
            if (dupCheck.find(d) == dupCheck.end())
            {
                mVector[i - 1] = d;
                mDeque[i - 1] = d;
                dupCheck.insert(d);
                iss.clear();
            }
            else
            {
                throw std::invalid_argument("Error: " + str + " is a duplicate.");
            }
        }
        else
        {
            throw std::invalid_argument("Error: " + str + " is not a positive integer.");
        }
    }
    generateJacobsthalSequence(ac - 1);
}
PmergeMe::~PmergeMe()
{
}
void PmergeMe::run()
{
    /* Vector */
    {
        std::cout << "Vector\nBefore: " << std::endl;
        printVector(mVector);

        const clock_t start = clock();
        std::vector<int> sortedVector = sorted(mVector);
        const clock_t end = clock();

        std::cout << "After: ";
        printVector(sortedVector);

        const double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
        std::cout << "Elapsed time: " << elapsedTime << " microseconds" << std::endl;
    }

    /* Deque */
    {
        std::cout << "Deque\nBefore: " << std::endl;
        printDeque(mDeque);

        const clock_t start = clock();
        std::deque<int> sortedDeque = sorted(mDeque);
        const clock_t end = clock();

        std::cout << "After: ";
        printDeque(sortedDeque);

        const double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
        std::cout << "Elapsed time: " << elapsedTime << " microseconds" << std::endl;
    }

    printVector(mJacobsthalNumbers);
}

/* Deque */

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

void PmergeMe::generateJacobsthalSequence(int n)
{
    mJacobsthalNumbers.push_back(1);

    int i = 1;
    while (true)
    {
        int value = (1 << (i + 1)) - mJacobsthalNumbers[i - 1];
        if (value > n)
            break;
        mJacobsthalNumbers.push_back(value);
        ++i;
    }
}

void PmergeMe::binaryInsert(std::deque<int> &result, int target, int range)
{
    std::deque<int>::iterator end = result.begin() + range;
    end = std::min(end, result.end());

    std::deque<int>::iterator insertPos = std::lower_bound(result.begin(), end, target);
    result.insert(insertPos, target);
}

/* Vector */

std::vector<int> PmergeMe::sorted(const std::vector<int> &original)
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

void PmergeMe::pairwiseComparison(const std::vector<int> &original, std::vector<int> &mainList, std::vector<int> &pendingList)
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

HashTable PmergeMe::createMapping(const std::vector<int> &mainList, const std::vector<int> &pendingList)
{
    HashTable mappingDatas(mainList.size());

    for (size_t i = 0; i < mainList.size(); ++i)
        mappingDatas.insert(mainList[i], pendingList[i]);

    return mappingDatas;
}

std::vector<int> PmergeMe::reorderedPendingList(const std::vector<int> &mainList, const std::vector<int> &pendingList, const HashTable &mappingDatas)
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

void PmergeMe::insertPendingToResult(std::vector<int> &result, const std::vector<int> &pendingList)
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

void PmergeMe::binaryInsert(std::vector<int> &result, int target, int range)
{
    std::vector<int>::iterator end = result.begin() + range;
    end = std::min(end, result.end());

    std::vector<int>::iterator insertPos = std::lower_bound(result.begin(), end, target);
    result.insert(insertPos, target);
}

static bool isPositiveInteger(const std::string& str)
{
    if (str.empty() || (str[0] == '0' && str.length() > 1))
    {
        return false;
    }
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

static std::vector<int> oneIndexedToZeroIndexed(const std::vector<int> &oneIndexed)
{
    std::vector<int> zeroIndexed;
    for (size_t i = 0; i < oneIndexed.size(); ++i)
        zeroIndexed.push_back(oneIndexed[i] - 1);

    return zeroIndexed;
}

std::vector<int> PmergeMe::generateInsertionOrder(int n)
{
    std::vector<int> insertionOrder;

    int pivot = 0;
    for (size_t i = 0; i < mJacobsthalNumbers.size(); i++)
    {
        for (int order = mJacobsthalNumbers[i]; order > pivot; --order)
            insertionOrder.push_back(order);
        pivot = mJacobsthalNumbers[i];
    }

    for (int i = n; i > pivot; --i)
        insertionOrder.push_back(i);

    return oneIndexedToZeroIndexed(insertionOrder);
}

void printVector(const std::vector<int>& vector)
{
    for (size_t i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

void printDeque(const std::deque<int>& deque)
{
    for (size_t i = 0; i < deque.size(); i++)
    {
        std::cout << deque[i] << " ";
    }
    std::cout << std::endl;
}
