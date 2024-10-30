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

    // std::cout << "mainChain: ";
    // print_vector(mainChain);
    // std::cout << "subChain: ";
    // print_vector(subChain);

    // Step 3: Recursively sort the [n/2] larger elements from each pair, creating a sorted sequence S of |n/2] of the input elements, in ascending order, using
    // the merge-insertion sort.
    mergeInsertionSort(mainChain);

    // Step 4: Insert at the start of S the element that was paired with the first and smallest element of S.
    std::vector<int> sortedSeq = mainChain;
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
