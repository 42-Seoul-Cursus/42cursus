#include "FragTrap.hpp"

int	main(void)
{
	FragTrap a("a");
	FragTrap b(a);
	FragTrap c;
	c = a;

	a.beRepaired(0);
	a.highFivesGuys();
	for (int i = 0; i < 105; i++)
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
