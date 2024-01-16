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
	mName = rhs.mName;
	mHitPoints = rhs.mHitPoints;
	mEnergyPoints = rhs.mEnergyPoints;
	mAttackDamage = rhs.mAttackDamage;
	std::cout << "ClapTrap " << mName << " is copied" << std::endl;
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
	--mEnergyPoints;
	std::cout << "ClapTrap " << mName << " attacks " << target << ", causing " << mAttackDamage << " points of damage!" << std::endl;
}
void FragTrap::takeDamage(unsigned int amount)
{
	mHitPoints -= amount;
	std::cout << "ClapTrap " << mName << " is attacked and takes " << amount << " points of damage!" << std::endl;
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
	--mEnergyPoints;
	std::cout << "ClapTrap " << mName << " repairs and heals for " << amount << " points of damage!" << std::endl;
}
void FragTrap::SetName(const std::string& name)
{
	mName = name;
}
const std::string&	FragTrap::GetName(void) const
{
	return mName;
}
void FragTrap::SetHitPoints(const int hitPoints)
{
	mHitPoints = hitPoints;
}
int FragTrap::GetHitPoints(void) const
{
	return mHitPoints;
}
void FragTrap::SetEnergyPoints(const int energyPoints)
{
	mEnergyPoints = energyPoints;
}
int FragTrap::GetEnergyPoints(void) const
{
	return mEnergyPoints;
}
void FragTrap::SetAttackDamage(const int attackDamage)
{
	mAttackDamage = attackDamage;
}
int FragTrap::GetAttackDamage(void) const
{
	return mAttackDamage;
}
