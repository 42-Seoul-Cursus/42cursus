#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	std::string mName;
	Weapon const* mWeapon;
public:
	HumanB(const std::string& name);
	void	setWeapon(const Weapon& weapon);
	void	attack(void) const;
};

#endif
