#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(void)
{
	type = "";
}

Weapon::Weapon(std::string t)
{
	type = t;
}

std::string	Weapon::getType() const
{
	return type;
}

void	Weapon::setType(std::string t)
{
	type = t;
}
