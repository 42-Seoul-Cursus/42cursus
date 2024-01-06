#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie()
{
	mName = "";
}
Zombie::Zombie(const std::string name)
{
	mName = name;
}
Zombie::~Zombie()
{
	std::cout << "Zombie \"" << mName << "\" has been destroyed.\n";
}
const std::string& Zombie::getName() const
{
	return mName;
}
void Zombie::setName(const std::string name)
{
	mName = name;
}
void Zombie::announce(void) const
{
	std::cout << mName << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
