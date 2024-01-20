#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() 
: ClapTrap()
{
	mHitPoints = 100;
	mEnergyPoints = 50;
	mAttackDamage = 20;
	std::cout << "ScavTrap " << mName << " is created" << std::endl;
}
ScavTrap::ScavTrap(const std::string& name) 
: ClapTrap(name)
{
	mHitPoints = 100;
	mEnergyPoints = 50;
	mAttackDamage = 20;
	std::cout << "ScavTrap " << mName << " is created" << std::endl;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << mName << " is destroyed" << std::endl;
};
ScavTrap::ScavTrap(const ScavTrap& rhs)
: ClapTrap(rhs)
{
	init(rhs);
	std::cout << "ScavTrap " << mName << " is created as a copy" << std::endl;
}
const ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs)
{
	init(rhs);
	std::cout << "ScavTrap " << mName << " is copied" << std::endl;
	return *this;
}
void ScavTrap::attack(const std::string& target)
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
	std::cout << "\033[0;32m" 
	<< "ScavTrap " << mName << " attacks " << target << ", causing " << mAttackDamage << " points of damage!" 
	<< "\033[0m" << std::endl;
}
void ScavTrap::guardGate()
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
	std::cout << "\033[0;37m" 
	<< "ScavTrap " << mName << " is now in Gate" 
	<< "\033[0m" << std::endl;
}
