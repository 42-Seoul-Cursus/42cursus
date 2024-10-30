#include <iostream>
#include "PmergeMe.hpp"

static void print_vector(const std::vector<int>& v);
static bool vectors_equal(const std::vector<int>& a, const std::vector<int>& b);
static void odd_test();
static void even_test();
static void random_test();

int main()
{
    even_test();
    odd_test();
    random_test();
    return 0;
}

void print_vector(const std::vector<int>& v)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

bool vectors_equal(const std::vector<int>& a, const std::vector<int>& b)
{
    if (a.size() != b.size())
        return false;
    for (size_t i = 0; i < a.size(); ++i)
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

    PmergeMe::mergeInsertionSort(testVec);
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

    PmergeMe::mergeInsertionSort(testVec);
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
        PmergeMe::mergeInsertionSort(shuffled);
        if (!vectors_equal(shuffled, init))
        {
            std::cout << "Random test " << testVec + 1 << " failed!" << std::endl;
            return;
        }
        std::cout << "Random test " << testVec + 1 << " passed" << std::endl;
    }

    std::cout << "All tests passed successfully!" << std::endl;
}
