#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	mName = name;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	mWeapon = &weapon;
}

void	HumanB::attack(void) const
{
	std::cout << mName << " attacks with their " << mWeapon->getType() << std::endl;
}
