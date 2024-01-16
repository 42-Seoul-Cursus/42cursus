#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap a("a");
	ScavTrap b(a);
	ScavTrap c;
	c = a;

	for (int i = 0; i < 55; i++)
	{
		a.attack("b");
	}
	for (int i = 0; i < 5; i++)
	{
		a.takeDamage(20);
	}
	a.attack("b");
	a.beRepaired(10);
	return 0;
}
