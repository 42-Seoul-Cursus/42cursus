#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: mName("default")
, mHitPoints(10)
, mEnergyPoints(10)
, mAttackDamage(0) 
{
	std::cout << "ClapTrap " << mName << " is created" << std::endl;
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
	if (mHitPoints <= 0)
	{
		std::cout << "ClapTrap " << mName << " has no hit point and can`t do anything..." << std::endl;
		return ;
	}
	if (mEnergyPoints <= 0)
	{
		std::cout << "ClapTrap " << mName << " has no energy point and can`t do anything..." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << mName << " attacks " << target << ", causing " << mAttackDamage << " points of damage!" << std::endl;
	--mEnergyPoints;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << mName << " is attacked and takes " << amount << " points of damage!" << std::endl;
	mHitPoints -= amount;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (mHitPoints <= 0)
	{
		std::cout << "ClapTrap " << mName << " has no hit point and can`t do anything..." << std::endl;
		return ;
	}
	if (mEnergyPoints <= 0)
	{
		std::cout << "ClapTrap " << mName << " has no energy point and can`t do anything..." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << mName << " repairs and heals for " << amount << " points of damage!" << std::endl;
	--mEnergyPoints;
}
