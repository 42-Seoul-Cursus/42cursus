#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(void)
{
	type = "";
}

Weapon::Weapon(const std::string& t)
{
	type = t;
}

const std::string& Weapon::getType() const
{
	return type;
}

void Weapon::setType(const std::string& t)
{
	type = t;
}
