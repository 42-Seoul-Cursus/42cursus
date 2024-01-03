#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
{
	mName = name;
	mWeapon = &weapon;
}

void	HumanA::attack(void) const
{
	std::cout << mName << " attacks with their " << mWeapon->getType() << std::endl;
}
