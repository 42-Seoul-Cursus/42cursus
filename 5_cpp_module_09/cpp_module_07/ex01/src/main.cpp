#include "iter.hpp"

int main()
{
    int arrInt[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float arrFloat[10] = {1.1f, 2.1f, 3.1f, 4.1f, 5.1f, 6.1f, 7.1f, 8.1f, 9.1f, 10.1f};
    double arrDouble[10] = {1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1, 10.1};
    char arrChar[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

    std::cout << "\033[0;31m" << "INT TEST" << '\n';
    iter(arrInt, 10, print);
    std::cout << "\033[0;33m" << "FLOAT TEST" << '\n';
    iter(arrFloat, 10, print);
    std::cout << "\033[0;32m" << "DOUBLE TEST" << '\n';
    iter(arrDouble, 10, print);
    std::cout << "\033[0;34m" << "CHAR TEST" << '\n';
    iter(arrChar, 10, print);
    return 0;
}
