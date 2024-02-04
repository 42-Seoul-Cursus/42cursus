#include <iostream>
#include <vector>
#include <random>
#include "Span.hpp"

int	main()
{
	// Span sp = Span(5);
	// sp.AddNumber(6);
	// sp.AddNumber(3);
	// sp.AddNumber(17);
	// sp.AddNumber(9);
	// sp.AddNumber(11);
	// std::cout << sp.ShortestSpan() << std::endl;
	// std::cout << sp.LongestSpan() << std::endl;

	Span sp = Span(20000);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 20000);

	std::vector<int> v(20000);

	for (size_t i = 0; i < 20000; i++)
	{
		v[i] = dis(gen);
	}
	sp.AddNumbers<std::vector<int> >(v.begin(), v.end());

	std::cout << sp.LongestSpan() << '\n'
	<< sp.ShortestSpan() << std::endl;

	for (size_t i = 0; i < 20000; i++)
	{
		std::cout << sp[i] << ' ';
	}
	
	return 0;
}
