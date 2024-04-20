#include <iostream>
#include <random>
#include <vector>
#include "Span.hpp"

const int MAX_STORE = 20;

void test_random(void);
void test_subject(void);

int main()
{
    // test_subject();
    test_random();  // ./span | sort -n
    return 0;
}

void test_subject(void)
{
    Span sp = Span(5);

    sp.AddNumber(6);
    sp.AddNumber(3);
    sp.AddNumber(17);
    sp.AddNumber(9);
    sp.AddNumber(11);

    std::cout << sp.ShortestSpan() << '\n' << sp.LongestSpan() << std::endl;
    /*
    $> ./ex01
    2
    14
    $>
     */
}

void test_random(void)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 100);

    Span sp = Span(MAX_STORE);
    std::vector<int> v(MAX_STORE);

    for (size_t i = 0; i < MAX_STORE; i++)
    {
        v[i] = dis(gen);
    }
    sp.AddNumbers<std::vector<int> >(v.begin(), v.end());

    for (size_t i = 0; i < MAX_STORE; i++)
    {
        std::cout << sp[i] << ' ' << sp[i] << '\n';
    }

    std::cout << "\033[0;37m" << "LongestSpan: " << sp.LongestSpan()
              << " ShortestSpan: " << sp.ShortestSpan() << "\033[0m"
              << std::endl;
}
