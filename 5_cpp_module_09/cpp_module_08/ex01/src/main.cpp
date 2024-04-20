#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include "Span.hpp"

const int MAX_STORE = 10;

void test_random(void);
void test_subject(void);

int main()
{
    test_subject();
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
    std::srand(std::time(NULL));

    Span sp = Span(MAX_STORE);
    std::vector<int> v(MAX_STORE);

    for (size_t i = 0; i < MAX_STORE; i++)
    {
        v[i] = std::rand() % 1000 + 1;
    }
    sp.AddNumbers<std::vector<int> >(v.begin(), v.end());

    for (size_t i = 0; i < MAX_STORE; i++)
    {
        std::cout << v[i] << ' ' << sp[i] << '\n';
    }

    Span sp2(1);
    sp2 = sp;

    std::cout << "\033[0;37m" << "LongestSpan: " << sp2.LongestSpan()
              << " ShortestSpan: " << sp2.ShortestSpan() << "\033[0m"
              << std::endl;
    try
    {
        sp2.AddNumbers<std::vector<int> >(v.begin(), v.begin() + 1);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        sp2.AddNumber(1);
        sp2.AddNumber(2);
        sp2.AddNumber(3);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << sp2[20] << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
