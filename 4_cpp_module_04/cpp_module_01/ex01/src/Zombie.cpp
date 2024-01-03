#include "Zombie.hpp"

Zombie::Zombie()
{
	mName = "";
}
Zombie::Zombie(std::string name)
{
	mName = name;
}
Zombie::~Zombie()
{
	std::cout << "Zombie \"" << mName << "\" has been destroyed.\n";
}
void Zombie::setName(std::string name)
{
	mName = name;
}
std::string Zombie::getName() const
{
	return mName;
}
void Zombie::announce(void) const
{
	std::cout << mName << " BraiiiiiiinnnzzzZ..." << std::endl;
}
