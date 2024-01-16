#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
private:
	std::string mName;
	unsigned int mHitPoints;
	unsigned int mEnergyPoints;
	unsigned int mAttackDamage;
public:
	ClapTrap();
	ClapTrap(const std::string& name);
	~ClapTrap();
	ClapTrap(const ClapTrap& rhs);
	const ClapTrap&	operator=(const ClapTrap& rhs);
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif 
