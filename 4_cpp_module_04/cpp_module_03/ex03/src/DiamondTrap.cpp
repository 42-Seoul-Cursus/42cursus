#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
: ClapTrap()
, FragTrap()
, ScavTrap()
{
	mName = "default_clap_name";
	mHitPoints = 100;
	mEnergyPoints = 100;
	mAttackDamage = 20;
	std::cout << "DiamondTrap default_clap_name is created" << std::endl;
}
DiamondTrap::DiamondTrap(const std::string& name)
: ClapTrap(name)
, FragTrap(name)
, ScavTrap(name)
{
	mName = ScavTrap::mName + "_clap_name";
	mHitPoints = 100;
	mEnergyPoints = 100;
	mAttackDamage = 20;
	std::cout << "DiamondTrap " << mName << " is created" << std::endl;
}
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << mName << " is destroyed" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap& rhs)
: ClapTrap(rhs)
, FragTrap(rhs)
, ScavTrap(rhs)
{	
	mName = rhs.mName;
	init(rhs);
	std::cout << "DiamondTrap " << mName << " is created as a copy" << std::endl;
}
const DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& rhs)
{
	mName = rhs.mName;
	init(rhs);
	std::cout << "DiamondTrap " << mName << " is copied" << std::endl;
	return *this;
}
void DiamondTrap::whoAmI()
{
	if (FragTrap::mHitPoints == 0)
	{
		std::cout << "\033[0;31m" 
		<< "DiamondTrap " << mName << " can`t do anything because it has no hit point..." 
		<< "\033[0m" << std::endl;
		return ;
	}
	if (ScavTrap::mEnergyPoints == 0)
	{
		std::cout << "\033[0;33m" 
		<< "DiamondTrap " << mName << " can`t do anything because it has no energy point..." 
		<< "\033[0m" << std::endl;
		return ;
	}
	std::cout << "\033[0;36m" 
	<< mName << ", " << ClapTrap::mName
	<< "\033[0m" << std::endl;
	--ScavTrap::mEnergyPoints;
}
