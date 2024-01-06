#include "Zombie.hpp"

int	main(void)
{
	Zombie a("zomzom");
	a.announce();

	Zombie* b = zombieHorde(5, "zzebzzeb");

	for (int i = 0; i < 5; i++)
	{
		b[i].announce();
	}

	delete[] b;

	return 0;
}
