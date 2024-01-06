#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	std::string mName;
	Weapon const* mWeapon;
public:
	HumanA(const std::string& name, const Weapon& weapon);
	void	attack(void) const;
};

#endif
