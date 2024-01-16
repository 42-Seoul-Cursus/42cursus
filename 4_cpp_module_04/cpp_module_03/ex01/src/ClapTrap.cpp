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
	mName = rhs.mName;
	mHitPoints = rhs.mHitPoints;
	mEnergyPoints = rhs.mEnergyPoints;
	mAttackDamage = rhs.mAttackDamage;
	std::cout << "ClapTrap " << mName << " is copied" << std::endl;
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
	--mEnergyPoints;
	std::cout << "ClapTrap " << mName << " attacks " << target << ", causing " << mAttackDamage << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	mHitPoints -= amount;
	std::cout << "ClapTrap " << mName << " is attacked and takes " << amount << " points of damage!" << std::endl;
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
	--mEnergyPoints;
	std::cout << "ClapTrap " << mName << " repairs and heals for " << amount << " points of damage!" << std::endl;
}
void ClapTrap::SetName(const std::string& name)
{
	mName = name;
}
const std::string&	ClapTrap::GetName(void) const
{
	return mName;
}
void ClapTrap::SetHitPoints(const int hitPoints)
{
	mHitPoints = hitPoints;
}
int ClapTrap::GetHitPoints(void) const
{
	return mHitPoints;
}
void ClapTrap::SetEnergyPoints(const int energyPoints)
{
	mEnergyPoints = energyPoints;
}
int ClapTrap::GetEnergyPoints(void) const
{
	return mEnergyPoints;
}
void ClapTrap::SetAttackDamage(const int attackDamage)
{
	mAttackDamage = attackDamage;
}
int ClapTrap::GetAttackDamage(void) const
{
	return mAttackDamage;
}
