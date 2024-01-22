#include <iostream>
#include "whatever.hpp"

int	main()
{
	int aInt = 1, bInt = 2;
	float aFloat = 1.1f, bFloat = 2.2f;
	double aDouble = 1.1, bDouble = 2.2;
	char aChar = 'a', bChar = 'b';

	::swap(aInt, bInt);
	std::cout << "\033[0;31m" << "INT TEST" << '\n'
	<< "aInt: " << aInt << ' ' << &aInt << '\n'
	<< "bInt: " << bInt << ' ' << &bInt << '\n'
	<< "max: " << ::max(aInt, bInt) << '\n'
	<< "max: " << ::min(aInt, bInt) << '\n' << '\n';

	::swap(aFloat, bFloat);
	std::cout << "\033[0;33m" << "FLOAT TEST" << '\n'
	<< "aFloat: " << aFloat << ' ' << &aFloat << '\n'
	<< "bFloat: " << bFloat << ' ' << &bFloat << '\n'
	<< "max: " << ::max(aFloat, bFloat) << '\n'
	<< "max: " << ::min(aFloat, bFloat) << '\n' << '\n';

	::swap(aDouble, bDouble);
	std::cout << "\033[0;32m" << "DOUBLE TEST" << '\n'
	<< "aDouble: " << aDouble << ' ' << &aDouble << '\n'
	<< "bDouble: " << bDouble << ' ' << &bDouble << '\n'
	<< "max: " << ::max(aDouble, bDouble) << '\n'
	<< "max: " << ::min(aDouble, bDouble) << '\n' << '\n';

	::swap(aChar, bChar);
	std::cout << "\033[0;34m" << "CHAR TEST" << '\n'
	<< "aChar: " << aChar << ' ' << static_cast<void*>(&aChar) << '\n'
	<< "bChar: " << bChar << ' ' << static_cast<void*>(&bChar) << '\n'
	<< "max: " << ::max(aChar, bChar) << '\n'
	<< "max: " << ::min(aChar, bChar) << "\033[0m" << std::endl;;

	return 0;
}
