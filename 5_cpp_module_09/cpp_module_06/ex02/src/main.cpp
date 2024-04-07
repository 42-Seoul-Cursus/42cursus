#include <iostream>
#include <random>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static Base*	generate(void);
static void		identify(Base* p);
static void		identify(Base& p);

int	main(void)
{
	Base* base = generate();

	identify(base);
	identify(*base);
	return 0;
}

Base*	generate(void)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 2);

	switch (dis(gen))
	{
		case 0: return new A;
		case 1: return new B;
		case 2: return new C;
		default: return nullptr;
	}
}

void	identify(Base* p)
{
	try
	{
		if (dynamic_cast<A*>(p))
		{
			std::cout << "A" << std::endl;
		}
		else if (dynamic_cast<B*>(p))
		{
			std::cout << "B" << std::endl;
		}
		else if (dynamic_cast<C*>(p))
		{
			std::cout << "C" << std::endl;
		}
		else
		{
			std::cout << "Not Found" << std::endl;
		}
	}
	catch (const std::bad_cast&)
	{
		std::cerr << "hi" << std::endl;
	}
	
}

void	identify(Base& p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {}
	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {}
	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {}
}
