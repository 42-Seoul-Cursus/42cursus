#include <iostream>
#include "whatever.hpp"

int main()
{
    int aInt = 1, bInt = 2;
    float aFloat = 1.1f, bFloat = 2.2f;
    double aDouble = 1.1, bDouble = 2.2;
    char aChar = 'a', bChar = 'b';

    std::cout << "\033[0;31m" << "INT TEST" << '\n'
              << "Before swap(aInt, bInt)" << "\n\n"
              << "aInt: " << aInt << ' ' << &aInt << '\n'
              << "bInt: " << bInt << ' ' << &bInt << "\n\n";
    ::swap(aInt, bInt);
    std::cout << "After swap(aInt, bInt)" << "\n\n"
              << "aInt: " << aInt << ' ' << &aInt << '\n'
              << "bInt: " << bInt << ' ' << &bInt << "\n\n"
              << "max: " << ::max(aInt, bInt) << '\n'
              << "min: " << ::min(aInt, bInt) << "\n\n";

    std::cout << "\033[0;33m" << "FLOAT TEST" << '\n'
              << "Before swap(aFloat, bFloat)" << "\n\n"
              << "aFloat: " << aFloat << ' ' << &aFloat << '\n'
              << "bFloat: " << bFloat << ' ' << &bFloat << "\n\n";
    ::swap(aFloat, bFloat);
    std::cout << "After swap(aFloat, bFloat)" << "\n\n"
              << "aFloat: " << aFloat << ' ' << &aFloat << '\n'
              << "bFloat: " << bFloat << ' ' << &bFloat << "\n\n"
              << "max: " << ::max(aFloat, bFloat) << '\n'
              << "min: " << ::min(aFloat, bFloat) << "\n\n";

    std::cout << "\033[0;32m" << "DOUBLE TEST" << '\n'
              << "Before swap(aDouble, bDouble)" << "\n\n"
              << "aDouble: " << aDouble << ' ' << &aDouble << '\n'
              << "bDouble: " << bDouble << ' ' << &bDouble << "\n\n";
    ::swap(aDouble, bDouble);
    std::cout << "After swap(aDouble, bDouble)" << "\n\n"
              << "aDouble: " << aDouble << ' ' << &aDouble << '\n'
              << "bDouble: " << bDouble << ' ' << &bDouble << "\n\n"
              << "max: " << ::max(aDouble, bDouble) << '\n'
              << "min: " << ::min(aDouble, bDouble) << "\n\n";

    std::cout << "\033[0;34m" << "CHARACTER TEST" << '\n'
              << "Before swap(aChar, bChar)" << "\n\n"
              << "aChar: " << aChar << ' ' << static_cast<void*>(&aChar) << '\n'
              << "bChar: " << bChar << ' ' << static_cast<void*>(&bChar)
              << "\n\n";
    ::swap(aChar, bChar);
    std::cout << "After swap(aChar, bChar)" << "\n\n"
              << "aChar: " << aChar << ' ' << static_cast<void*>(&aChar) << '\n'
              << "bChar: " << bChar << ' ' << static_cast<void*>(&bChar)
              << "\n\n"
              << "max: " << ::max(aChar, bChar) << '\n'
              << "min: " << ::min(aChar, bChar) << std::endl;

    return 0;
}
