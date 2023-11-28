#include "Karen.hpp"

void Karen::complain(std::string level)
{
	void (Karen::*f)(void);
	if (level == "debug")
	{
		f = &Karen::debug;
	}
	else if (level == "info")
	{
		f = &Karen::info;
	}
	else if (level == "warning")
	{
		f = &Karen::warning;
	}
	else if (level == "error")
	{
		f = &Karen::error;
	}
	else
	{
		std::cout << "Invalid level\n";
		return;
	}
	(this->*f)();
}
void Karen::debug( void )
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\n";
}
void Karen::info( void )
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don\'t put enough! If you did I would not have to ask for it!\n";
}
void Karen::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I\'ve been coming here for years and you just started working here last month.\n";
}
void Karen::error( void )
{
	std::cout <<  "This is unacceptable, I want to speak to the manager now.\n";
}
