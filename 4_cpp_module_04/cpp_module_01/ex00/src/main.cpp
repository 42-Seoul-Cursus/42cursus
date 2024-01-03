#include "Zombie.hpp"

int	main(void)
{
	Zombie a("zomzom");

	a.announce();
	randomChump("rand");

	Zombie* b = newZombie("zzemzzem");
	b->announce();

	delete b;
	return 0;
}
