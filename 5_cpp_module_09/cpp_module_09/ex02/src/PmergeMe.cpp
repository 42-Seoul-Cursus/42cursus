#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

// Function to perform binary search for insertion
int PmergeMe::binarySearch(const std::vector<int>& sortedSeq, int value)
{
    int left = 0;
    int right = sortedSeq.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (sortedSeq[mid] < value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left;
}

#include <iostream>

// Function to perform the Merge-Insertion Sort
void PmergeMe::mergeInsertionSort(std::vector<int>& arr)
{
    int n = arr.size();
    if (n <= 1)
        return;

    // Step 1: Group the elements of X into [n/2] pairs of elements
    int mid = n / 2;
    std::vector<int> mainChain;
    std::vector<int> subChain;

    for (int i = 0; i < mid; ++i)
    {
        // Step 2: Perform [n/2] comparisons, one per pair, to determine the larger of the two elements in each pair.
        if (arr[2 * i] > arr[2 * i + 1])
        {
            mainChain.push_back(arr[2 * i]);
            subChain.push_back(arr[2 * i + 1]);
        }
        else
        {
            mainChain.push_back(arr[2 * i + 1]);
            subChain.push_back(arr[2 * i]);
        }
    }

    // If there is an odd element, leave it unpaired
    if (n % 2 != 0)
    {
        mainChain.push_back(arr[n - 1]);
    }

    // TEST: 테스트 코드
    std::cout << aec::fg::BLUE << "mainChain: " << aec::RESET;
    print_vector(mainChain);
    std::cout << aec::fg::GREEN << "subChain: " << aec::RESET;
    print_vector(subChain);

    // Step 3: Recursively sort the [n/2] larger elements from each pair, creating a sorted sequence S of |n/2] of the input elements, in ascending order, using
    // the merge-insertion sort.
    mergeInsertionSort(mainChain);

    // Step 4: Insert at the start of S the element that was paired with the first and smallest element of S.
    std::vector<int> sortedSeq = mainChain;

    // TEST: 테스트 코드
    std::cout << aec::fg::MAGENTA << "sortedSeq: " << aec::RESET;
    print_vector(sortedSeq);

    if (!subChain.empty())
    {
        int pos = binarySearch(sortedSeq, subChain[0]);
        sortedSeq.insert(sortedSeq.begin() + pos, subChain[0]);
    }

    // Step 5: Insert the remaining [n/2] - 1 elements of X \ S into S, one at a time, with a specially chosen insertion ordering describedbelow. Use binary
    // search in subsequences of S (as described below) to determine the position at which each element should be inserted.
    for (size_t i = 1; i < subChain.size(); ++i)
    {
        int pos = binarySearch(sortedSeq, subChain[i]);
        sortedSeq.insert(sortedSeq.begin() + pos, subChain[i]);
    }

    // Copy the sorted sequence back to the original array
    arr = sortedSeq;
}

void print_vector(const std::vector<int>& v)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

namespace aec
{
    namespace fg
    {
        const char* BLACK = "\033[30m";
        const char* RED = "\033[31m";
        const char* GREEN = "\033[32m";
        const char* YELLOW = "\033[33m";
        const char* BLUE = "\033[34m";
        const char* MAGENTA = "\033[35m";
        const char* CYAN = "\033[36m";
        const char* WHITE = "\033[37m";
    }  // namespace fg
    namespace bg
    {
        const char* BLACK = "\033[40m";
        const char* RED = "\033[41m";
        const char* GREEN = "\033[42m";
        const char* YELLOW = "\033[43m";
        const char* BLUE = "\033[44m";
        const char* MAGENTA = "\033[45m";
        const char* CYAN = "\033[46m";
        const char* WHITE = "\033[47m";
    }  // namespace bg
    namespace st
    {
        const char* REGULAR = "\033[0m";
        const char* BOLD = "\033[1m";
        const char* FAINT = "\033[2m";
        const char* ITALIC = "\033[3m";
        const char* UNDERLINE = "\033[4m";
        const char* BLINK = "\033[5m";
        const char* RAPID_BLINK = "\033[6m";
        const char* REVERSE = "\033[7m";
        const char* HIDDEN = "\033[8m";
        const char* STRIKE_THROUGH = "\033[9m";
    }  // namespace st
    const char* RESET = "\033[0m";
}  // namespace aec
