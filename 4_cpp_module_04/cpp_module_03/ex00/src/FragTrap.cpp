#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap()
: mName("default")
, mHitPoints(10)
, mEnergyPoints(10)
, mAttackDamage(0) 
{
	std::cout << "ClapTrap " << mName << " is created" << std::endl;
}
FragTrap::FragTrap(const std::string& name)
: mName(name)
, mHitPoints(10)
, mEnergyPoints(10)
, mAttackDamage(0) 
{
	std::cout << "ClapTrap " << mName << " is created" << std::endl;
}
FragTrap::~FragTrap() 
{
	std::cout << "ClapTrap " << mName << " is destroyed" << std::endl;
}
FragTrap::FragTrap(const FragTrap& rhs)
: mName(rhs.mName)
, mHitPoints(rhs.mHitPoints)
, mEnergyPoints(rhs.mEnergyPoints)
, mAttackDamage(rhs.mAttackDamage) 
{
	std::cout << "ClapTrap " << mName << " is created as a copy" << std::endl;
}
const FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << "ClapTrap " << mName << " is copied" << std::endl;
	mName = rhs.mName;
	mHitPoints = rhs.mHitPoints;
	mEnergyPoints = rhs.mEnergyPoints;
	mAttackDamage = rhs.mAttackDamage;
	return *this;
}
void FragTrap::attack(const std::string& target)
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
void FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << mName << " is attacked and takes " << amount << " points of damage!" << std::endl;
	mHitPoints -= amount;
}
void FragTrap::beRepaired(unsigned int amount)
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
