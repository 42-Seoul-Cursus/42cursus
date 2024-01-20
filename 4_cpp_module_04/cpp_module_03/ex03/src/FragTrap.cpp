#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap() 
: ClapTrap()
{
	mHitPoints = 100;
	mEnergyPoints = 100;
	mAttackDamage = 30;
	std::cout << "FragTrap " << mName << " is created" << std::endl;
}
FragTrap::FragTrap(const std::string& name) 
: ClapTrap(name)
{
	mHitPoints = 100;
	mEnergyPoints = 100;
	mAttackDamage = 30;
	std::cout << "FragTrap " << mName << " is created" << std::endl;
}
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << mName << " is destroyed" << std::endl;
};
FragTrap::FragTrap(const FragTrap& rhs)
: ClapTrap(rhs)
{
	init(rhs);
	std::cout << "FragTrap " << mName << " is created as a copy" << std::endl;
}
const FragTrap&	FragTrap::operator=(const FragTrap& rhs)
{
	init(rhs);
	std::cout << "FragTrap " << mName << " is copied" << std::endl;
	return *this;
}
void FragTrap::highFivesGuys(void)
{
	if (mHitPoints == 0)
	{
		std::cout << "\033[0;31m" 
		<< "ScavTrap " << mName << " can`t do anything because it has no hit point..." 
		<< "\033[0m" << std::endl;
		return ;
	}
	if (mEnergyPoints == 0)
	{
		std::cout << "\033[0;33m" 
		<< "ScavTrap " << mName << " can`t do anything because it has no energy point..." 
		<< "\033[0m" << std::endl;
		return ;
	}
	--mEnergyPoints;
	std::cout << "\033[44m" 
	<< "🙋 High Five guys 🙋"
	<< "\033[0m" << std::endl;
}
