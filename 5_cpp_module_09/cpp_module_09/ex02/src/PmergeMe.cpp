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

    for (int i = 1; i < ac; i++)
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

std::deque<int> PmergeMe::sorted(const std::deque<int> &sequence)
{
    if (sequence.size() <= 1)
        return sequence;

    std::deque<int> mainChain;
    std::deque<int> subChain;

    makePairChains(sequence, mainChain, subChain);
    HashTable mappingDatas = mapping(mainChain, subChain);

    mainChain = sorted(mainChain);
    subChain = reorderedSubChain(mainChain, subChain, mappingDatas);

    std::deque<int> result(mainChain);
    insertSubChainToMainChain(result, subChain);

    return result;
}

void PmergeMe::makePairChains(const std::deque<int> &sequence, std::deque<int> &mainChain, std::deque<int> &subChain)
{
    for (size_t i = 0; i + 1 < sequence.size(); i += 2)
    {
        int large = std::max(sequence[i], sequence[i + 1]);
        int small = std::min(sequence[i], sequence[i + 1]);

        mainChain.push_back(large);
        subChain.push_back(small);
    }

    if (sequence.size() % 2 == 1)
        subChain.push_back(sequence.back());
}

HashTable PmergeMe::mapping(const std::deque<int> &mainChain, const std::deque<int> &subChain)
{
    HashTable mappingDatas(mainChain.size());

    for (size_t i = 0; i < mainChain.size(); ++i)
        mappingDatas.insert(mainChain[i], subChain[i]);

    return mappingDatas;
}

std::deque<int> PmergeMe::reorderedSubChain(const std::deque<int> &mainChain, const std::deque<int> &subChain, const HashTable &mappingDatas)
{
    std::deque<int> reorderedSubChain;

    for (size_t i = 0; i < mainChain.size(); ++i)
    {
        int target = mappingDatas.get(mainChain[i]);
        reorderedSubChain.push_back(target);
    }

    if (subChain.size() > mainChain.size())
        reorderedSubChain.push_back(subChain.back());

    return reorderedSubChain;
}

void PmergeMe::insertSubChainToMainChain(std::deque<int> &mainChain, const std::deque<int> &subChain)
{
    std::vector<int> insertionOrder = createInsertionIndex(subChain.size());

    int insertionCnt = 0;
    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        int targetIndex = insertionOrder[i];
        int target = subChain[targetIndex];
        int range = insertionCnt + targetIndex;
        binaryInsert(mainChain, target, range);
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

std::vector<int> PmergeMe::sorted(const std::vector<int> &sequence)
{
    if (sequence.size() <= 1)
        return sequence;

    std::vector<int> mainChain;
    std::vector<int> subChain;

    makePairChains(sequence, mainChain, subChain);
    HashTable mappingDatas = mapping(mainChain, subChain);

    mainChain = sorted(mainChain);
    subChain = reorderedSubChain(mainChain, subChain, mappingDatas);

    std::vector<int> result(mainChain);
    insertSubChainToMainChain(result, subChain);

    return result;
}

void PmergeMe::makePairChains(const std::vector<int> &sequence, std::vector<int> &mainChain, std::vector<int> &subChain)
{
    for (size_t i = 0; i + 1 < sequence.size(); i += 2)
    {
        int large = std::max(sequence[i], sequence[i + 1]);
        int small = std::min(sequence[i], sequence[i + 1]);

        mainChain.push_back(large);
        subChain.push_back(small);
    }

    if (sequence.size() % 2 == 1)
        subChain.push_back(sequence.back());
}

HashTable PmergeMe::mapping(const std::vector<int> &mainChain, const std::vector<int> &subChain)
{
    HashTable mappingDatas(mainChain.size());

    for (size_t i = 0; i < mainChain.size(); ++i)
        mappingDatas.insert(mainChain[i], subChain[i]);

    return mappingDatas;
}

std::vector<int> PmergeMe::reorderedSubChain(const std::vector<int> &mainChain, const std::vector<int> &subChain, const HashTable &mappingDatas)
{
    std::vector<int> reorderedSubChain;

    for (size_t i = 0; i < mainChain.size(); ++i)
    {
        int target = mappingDatas.get(mainChain[i]);
        reorderedSubChain.push_back(target);
    }

    if (subChain.size() > mainChain.size())
        reorderedSubChain.push_back(subChain.back());

    return reorderedSubChain;
}

void PmergeMe::insertSubChainToMainChain(std::vector<int> &mainChain, const std::vector<int> &subChain)
{
    std::vector<int> insertionIndex = createInsertionIndex(subChain.size());

    int insertionCnt = 0;
    for (size_t i = 0; i < insertionIndex.size(); ++i)
    {
        int targetIndex = insertionIndex[i];
        int target = subChain[targetIndex];
        int range = insertionCnt + targetIndex;
        binaryInsert(mainChain, target, range);
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

std::vector<int> PmergeMe::createInsertionIndex(int n)
{
    std::vector<int> insertionOrder;

    int pivot = 0;
    for (size_t i = 0; i < mJacobsthalNumbers.size(); i++)
    {
        if (mJacobsthalNumbers[i] > n)
            break;
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
