#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(const std::string& name)
{
	mName = name;
	mWeapon = NULL;
}

void HumanB::setWeapon(const Weapon& weapon)
{
	mWeapon = &weapon;
}

void	HumanB::attack(void) const
{
	if (mWeapon == NULL)
	{
		std::cout << mName << " attacks failed because he/she hasn\'t a weapon" << std::endl;
		return ;
	}
	std::cout << mName << " attacks with their " << mWeapon->getType() << std::endl;
}
