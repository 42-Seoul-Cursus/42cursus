#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	std::string mName;
	Weapon* mWeapon;
public:
	HumanB(std::string name);
	void	setWeapon(Weapon& weapon);
	void	attack(void) const;
};

#endif
