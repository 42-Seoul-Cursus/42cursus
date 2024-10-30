#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#ifdef TEST

void mergeInsertionSort(std::vector<int>& arr);
int binarySearch(const std::vector<int>& sortedSeq, int value);

void print_vector(const std::vector<int>& v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

bool vectors_equal(const std::vector<int>& a, const std::vector<int>& b)
{
    if (a.size() != b.size())
        return false;
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

void odd_test()
{
    std::vector<int> testVec;
    testVec.push_back(3);
    testVec.push_back(5);
    testVec.push_back(1);
    testVec.push_back(2);
    testVec.push_back(4);

    std::cout << "Original array: ";
    print_vector(testVec);

    mergeInsertionSort(testVec);
    std::cout << "Sorted array: ";
    print_vector(testVec);

    std::vector<int> expected;
    for (int i = 1; i <= 5; ++i)
    {
        expected.push_back(i);
    }

    if (!vectors_equal(testVec, expected))
    {
        std::cout << "Basic test failed!" << std::endl;
        return;
    }
    std::cout << "Basic test passed" << std::endl;
}

void even_test()
{
    std::vector<int> testVec;
    testVec.push_back(3);
    testVec.push_back(5);
    testVec.push_back(9);
    testVec.push_back(2);
    testVec.push_back(6);
    testVec.push_back(1);
    testVec.push_back(4);
    testVec.push_back(7);
    testVec.push_back(10);
    testVec.push_back(8);

    std::cout << "Original array: ";
    print_vector(testVec);

    mergeInsertionSort(testVec);
    std::cout << "Sorted array: ";
    print_vector(testVec);

    std::vector<int> expected;
    for (int i = 1; i <= 10; ++i)
    {
        expected.push_back(i);
    }

    if (!vectors_equal(testVec, expected))
    {
        std::cout << "Basic test failed!" << std::endl;
        return;
    }
    std::cout << "Basic test passed" << std::endl;
}

void random_test()
{
    // 랜덤 테스트
    std::vector<int> init;
    for (int i = 0; i < 100; ++i)
    {
        init.push_back(i);
    }

    std::srand(std::time(0));

    for (int testVec = 0; testVec < 10; ++testVec)
    {
        std::vector<int> shuffled = init;
        // Fisher-Yates shuffle
        for (int i = shuffled.size() - 1; i > 0; --i)
        {
            int j = std::rand() % (i + 1);
            std::swap(shuffled[i], shuffled[j]);
        }

        std::cout << "Random test " << testVec + 1 << " starting..." << std::endl;
        mergeInsertionSort(shuffled);
        if (!vectors_equal(shuffled, init))
        {
            std::cout << "Random test " << testVec + 1 << " failed!" << std::endl;
            return;
        }
        std::cout << "Random test " << testVec + 1 << " passed" << std::endl;
    }

    std::cout << "All tests passed successfully!" << std::endl;
}

int main()
{
    // even_test();
    odd_test();
    // random_test();
    return 0;
}

#endif

// Function to perform binary search for insertion
int binarySearch(const std::vector<int>& sortedSeq, int value)
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
void mergeInsertionSort(std::vector<int>& arr)
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

    std::cout << "mainChain: ";
    print_vector(mainChain);
    std::cout << "subChain: ";
    print_vector(subChain);

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
    for (int i = 1; i < subChain.size(); ++i)
    {
        int pos = binarySearch(sortedSeq, subChain[i]);
        sortedSeq.insert(sortedSeq.begin() + pos, subChain[i]);
    }

    // Copy the sorted sequence back to the original array
    arr = sortedSeq;
}
