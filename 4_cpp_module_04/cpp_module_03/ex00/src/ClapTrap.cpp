#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: mName("default")
, mHitPoints(10)
, mEnergyPoints(10)
, mAttackDamage(0) 
{
	std::cout << "ClapTrap default is created" << std::endl;
}
ClapTrap::ClapTrap(const std::string& name)
: mName(name)
, mHitPoints(10)
, mEnergyPoints(10)
, mAttackDamage(0) 
{
	std::cout << "ClapTrap " << mName << " is created" << std::endl;
}
ClapTrap::~ClapTrap() 
{
	std::cout << "ClapTrap " << mName << " is destroyed" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& rhs)
: mName(rhs.mName)
, mHitPoints(rhs.mHitPoints)
, mEnergyPoints(rhs.mEnergyPoints)
, mAttackDamage(rhs.mAttackDamage) 
{
	std::cout << "ClapTrap " << mName << " is created as a copy" << std::endl;
}
const ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "ClapTrap " << mName << " is copied" << std::endl;
	mName = rhs.mName;
	mHitPoints = rhs.mHitPoints;
	mEnergyPoints = rhs.mEnergyPoints;
	mAttackDamage = rhs.mAttackDamage;
	return *this;
}
void ClapTrap::attack(const std::string& target)
{
	if (mHitPoints == 0)
	{
		std::cout << "\033[0;31m" 
		<< "ClapTrap " << mName << " can`t do anything because it has no hit point..." 
		<< "\033[0m" << std::endl;
		return ;
	}
	if (mEnergyPoints == 0)
	{
		std::cout << "\033[0;33m" 
		<< "ClapTrap " << mName << " can`t do anything because it has no energy point..." 
		<< "\033[0m" << std::endl;
		return ;
	}
	std::cout << "\033[0;32m" 
	<< "ClapTrap " << mName << " attacks " << target << ", causing " << mAttackDamage << " points of damage!" 
	<< "\033[0m" << std::endl;
	--mEnergyPoints;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= mHitPoints)
	{
		mHitPoints = 0;
	}
	else
	{
		mHitPoints -= amount;
	}
	std::cout << "ClapTrap " << mName << " is attacked and takes " << amount << " points of damage and has " << mHitPoints << " hit points remaining..." << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (mHitPoints == 0)
	{
		std::cout << "\033[0;31m" 
		<< "ClapTrap " << mName << " can`t do anything because it has no hit point..." 
		<< "\033[0m" << std::endl;
		return ;
	}
	if (mEnergyPoints == 0)
	{
		std::cout << "\033[0;33m" 
		<< "ClapTrap " << mName << " can`t do anything because it has no energy point..." 
		<< "\033[0m" << std::endl;
		return ;
	}
	std::cout << "\033[0;32m" 
	<< "ClapTrap " << mName << " repairs and heals for " << amount << " points of damage!" 
	<< "\033[0m" << std::endl;
	--mEnergyPoints;
}
