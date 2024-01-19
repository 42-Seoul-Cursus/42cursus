#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string mName;
public:
	DiamondTrap();
	DiamondTrap(const std::string& name);
	~DiamondTrap();
	DiamondTrap(const DiamondTrap& rhs);
	const DiamondTrap&	operator=(const DiamondTrap& rhs);
	void				attack(const std::string& target);
	void				whoAmI();
};

#endif 
