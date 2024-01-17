#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap a("a");
	DiamondTrap b(a);
	DiamondTrap c;
	c = a;
	a.highFivesGuys();
	for (int i = 0; i < 55; i++)
	{
		a.attack("b");
	}
	for (int i = 0; i < 5; i++)
	{
		a.FragTrap::takeDamage(20);
	}
	a.attack("b");
	a.FragTrap::beRepaired(10);
	return 0;
}
