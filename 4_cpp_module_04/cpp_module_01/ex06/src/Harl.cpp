#include <iostream>
#include "Harl.hpp"

void Harl::complain(std::string level)
{
	std::string levelArr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcArr[4])(void)  = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	void (Harl::*f)(void) = NULL;

	for (int i = 0; i < 4; i++)
	{
		if (level == levelArr[i])
		{
			f = funcArr[i];
		}
	}
	if (f != NULL)
	{
		(this->*f)();
	}
}
void Harl::debug( void )
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I just love it!\n" << std::endl;
}
void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon cost more money." << std::endl;
	std::cout << "You don\'t put enough! If you did I would not have to ask for it!\n" << std::endl;
}
void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I\'ve been coming here for years and you just started working here last month.\n" << std::endl;
}
void Harl::error( void )
{
	std::cout <<  "This is unacceptable, I want to speak to the manager now.\n" << std::endl;
}
