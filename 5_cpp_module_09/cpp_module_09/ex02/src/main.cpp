#include <iostream>
#include "PmergeMe.hpp"

static bool vectors_equal(const std::vector<int>& a, const std::vector<int>& b);
static void odd_test();
static void even_test();
static void random_test();

const int TEST_RUN_COUNT = 10;
const int NUM_ELEMENTS = 999;

int main()
{
    even_test();
    // odd_test();
    // random_test();
    return 0;
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
    std::vector<int> init;
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        init.push_back(i);
    }

    std::srand(std::time(0));

    for (int i = 0; i < TEST_RUN_COUNT; ++i)
    {
        std::vector<int> shuffled = init;

        for (int i = shuffled.size() - 1; i > 0; --i)
        {
            int j = std::rand() % (i + 1);
            std::swap(shuffled[i], shuffled[j]);
        }

        const std::vector<int> tmp = shuffled;
        PmergeMe::mergeInsertionSort(shuffled);

        if (!vectors_equal(shuffled, init))
        {
            std::cout << "Random test " << i + 1 << " failed!" << std::endl;
            print_vector(tmp);
            return;
        }
        std::cout << "Random test " << i + 1 << " passed" << std::endl;
    }

    std::cout << "All tests passed successfully!" << std::endl;
}
