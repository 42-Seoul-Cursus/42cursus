#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap a("a");
	ScavTrap b(a);
	ScavTrap c;
	c = a;

	a.guardGate();
	a.beRepaired(0);
	for (int i = 0; i < 55; i++)
	{
		a.attack("b");
	}
	for (int i = 0; i < 6; i++)
	{
		a.takeDamage(20);
	}
	a.attack("b");
	a.beRepaired(10);
	return 0;
}
