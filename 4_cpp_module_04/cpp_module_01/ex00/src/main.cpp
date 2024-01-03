#include "Zombie.hpp"

int	main(void)
{
	Zombie a("zomzom");

	a.announce();
	randomChump("rand");

	Zombie* b = newZombie("zzebzzeb");
	b->announce();

	delete b;
	return 0;
}
