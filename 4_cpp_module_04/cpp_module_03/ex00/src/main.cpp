#include "FragTrap.hpp"

int	main(void)
{
	FragTrap a("a");
	FragTrap b(a);
	FragTrap c;
	c = a;

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
