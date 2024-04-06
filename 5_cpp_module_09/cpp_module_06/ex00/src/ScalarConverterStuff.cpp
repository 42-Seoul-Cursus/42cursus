#include <iostream>
#include <iomanip>
#include <limits>
#include "ScalarConverterStuff.hpp"

namespace ScalarConverterStuff
{
	bool IsValidLiteral(const std::string& literal)
	{
		if (literal == "inf" || literal == "+inf" || literal == "-inf")
		{
			return true;
		}

		std::string::const_iterator it = literal.begin();

		if (!isdigit(*it) && *it != '-' && *it != '+')
		{
			return false;
		}
		if (*it == '-' || *it == '+')
		{
			++it;
		}
		for (; it != literal.end(); it++)
		{
			if (!isdigit(*it))
			{
				break;
			}
		}
		if (*it == '.')
		{
			++it;
		}
		for (; it != literal.end(); it++)
		{
			if (!isdigit(*it))
			{
				return false;
			}
		}
		return true;
	}
	bool IsFloat(const std::string& literal)
	{
		if (literal != "+inf" && literal != "-inf" && literal != "inf" && literal.back() == 'f')
		{
			return true;
		}
		return false;
	}
	void PrintChar(double num)
	{
		std::cout << "char : ";
		if (isnan(num) 
		|| std::numeric_limits<char>::max() < num
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
	void PrintInt(double num)
	{
		std::cout << "int : ";
		if (isnan(num)
		|| std::numeric_limits<int>::max() < num
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
	void PrintFloat(double num)
	{
		std::cout << "float : ";
		if (std::numeric_limits<float>::max() < num)
		{
			std::cout << "\033[0;37m" 
			<< "+inff" 
			<< "\033[0m" << std::endl;
		}
		else if (std::numeric_limits<float>::lowest() > num)
		{
			std::cout << "\033[0;37m" 
			<< "-inff" 
			<< "\033[0m" << std::endl;
		}
		else
		{
			std::cout << std::fixed << std::setprecision(1)
			<< static_cast<float>(num) << 'f' << std::endl;
		}
	}
	void PrintDouble(double num)
	{
		std::cout << "double : ";
		if (std::numeric_limits<double>::max() < num)
		{
			std::cout << "\033[0;37m" 
			<< "+inf" 
			<< "\033[0m" << std::endl;
		}
		else if (std::numeric_limits<double>::lowest() > num)
		{
			std::cout << "\033[0;37m" 
			<< "-inf" 
			<< "\033[0m" << std::endl;
		}
		else
		{
			std::cout << std::fixed << std::setprecision(1)
			<< static_cast<double>(num) << std::endl;
		}
	}
	void PrintNan()
	{
		std::cout  
		<< "char : " << "\033[0;31m" << "Impossible" << "\033[0m" << '\n'
		<< "int : " << "\033[0;31m"  << "Impossible"  << "\033[0m" << '\n'
		<< "float : nanf" << '\n' 
		<< "double : nan" 
		<< std::endl;
	}
}
