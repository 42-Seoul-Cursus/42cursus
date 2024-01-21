#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include "ScalarConverter.hpp"

static void printChar(double num);
static void printInt(double num);
static void printFloat(double num);
static void printDouble(double num);

void ScalarConverter::Convert(std::string& literal)
{
	if (literal.back() == 'f')
	{
		literal.pop_back();
	}
	std::istringstream iss(literal);
	double num;
	std::string remainder;

	iss >> num;
	printChar(num);
	printInt(num);
	printFloat(num);
	printDouble(num);
}

static void printChar(double num)
{
	std::cout << "char : ";
	if (std::numeric_limits<char>::max() < num
	|| std::numeric_limits<char>::min() > num)
	{
		std::cout << "\033[0;31m" 
		<< "Impossible" 
		<< "\033[0m" << std::endl;
	}
	else if (!std::isprint(num))
	{
		std::cout << "\033[0;33m" 
		<< "Non displayable" 
		<< "\033[0m" << std::endl;
	}
	else
	{
		std::cout << '\'' 
		<< static_cast<char>(num) 
		<< '\'' << std::endl;
	}
}
static void printInt(double num)
{
	std::cout << "int : ";
	if (std::numeric_limits<int>::max() < num
	|| std::numeric_limits<int>::min() > num)
	{
		std::cout << "\033[0;31m" 
		<< "Impossible" 
		<< "\033[0m" << std::endl;
	}
	else
	{
		std::cout << static_cast<int>(num) << std::endl;
	}
}
static void printFloat(double num)
{
	std::cout << "float : ";
	if (std::numeric_limits<float>::max() < num
	|| std::numeric_limits<float>::min() > num)
	{
		std::cout << "\033[0;31m" 
		<< "Impossible" 
		<< "\033[0m" << std::endl;
	}
	else
	{
		std::cout << std::fixed << std::setprecision(1)
		<< static_cast<float>(num) << 'f' << std::endl;
	}
}
static void printDouble(double num)
{
	std::cout << "double : ";
	if (std::numeric_limits<double>::max() < num
	|| std::numeric_limits<double>::min() > num)
	{
		std::cout << "\033[0;31m" 
		<< "Impossible" 
		<< "\033[0m" << std::endl;
	}
	else
	{
		std::cout << std::fixed << std::setprecision(1)
		<< static_cast<double>(num) << std::endl;
	}
}
