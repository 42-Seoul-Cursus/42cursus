#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat tooLow("d", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat tooHigh("d", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Bureaucrat a("a", 1);
	Bureaucrat b("b", 100);
	Bureaucrat c("c", 150);

	std::cout << a << '\n'
	<< b << '\n'
	<< c << std::endl;
	// LOW TEST
	try 
	{
		c.Decrement(1);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	// HIGH TEST
	try 
	{
		c.Increment(150);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	// NORMAL TEST

	for (size_t i = 0; i < 15; i++)
	{
		try 
		{
			c.Increment(10);
		}
		catch (std::exception& e)
		{
			std::cout <<  e.what() << std::endl;
		}
		std::cout << c << std::endl;
	}
	
	try 
	{
		c.Decrement(140);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << c << std::endl;
	return 0;
}
