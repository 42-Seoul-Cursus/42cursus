#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("a");
	ClapTrap b(a);
	ClapTrap c;
	c = a;

	a.beRepaired(0);
	for (int i = 0; i < 15; i++)
	{
		a.attack("b");
	}
	for (int i = 0; i < 5; i++)
	{
		a.takeDamage(2);
	}
	a.attack("b");
	a.beRepaired(10);
	
	return 0;
}
