#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("seunan");

	// LOW TEST
	try 
	{
		a.Decrement(1);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	// HIGH TEST
	try 
	{
		a.Increment(150);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << a << std::endl;

	// NORMAL TEST

	for (size_t i = 0; i < 15; i++)
	{
		try 
		{
			a.Increment(10);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << a << std::endl;
	}
	
	try 
	{
		a.Decrement(140);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << a << std::endl;
	return 0;
}
