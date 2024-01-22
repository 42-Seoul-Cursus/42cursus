#include <iostream>
#include "Span.hpp"

int	main()
{
	Span sp = Span(10);

	try
	{
		for (size_t i = 0; i < 11; i++)
		{
			sp.AddNumber(i + 1);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;
	
	return 0;
}
