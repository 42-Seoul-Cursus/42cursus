#include <iostream>
#include "FragTrap.hpp"

void	FragTrap::init(const FragTrap& rhs)
{
	mHitPoint = rhs.mHitPoint;
	mMaxHitPoints = rhs.mMaxHitPoints;
	mEnergyPoints = rhs.mEnergyPoints;
	mMaxEnergyPoints = rhs.mMaxEnergyPoints;
	mLevel = rhs.mLevel;
	mName = rhs.mName;
	mMeleeAttackDamage = rhs.mMeleeAttackDamage;
	mRangedAttackDamage = rhs.mRangedAttackDamage;
	mArmorAttackReduction = rhs.mArmorAttackReduction;
}
FragTrap::FragTrap(const std::string& name)
: mHitPoint(100)
, mMaxHitPoints(100)
, mEnergyPoints(100)
, mMaxEnergyPoints(100)
, mLevel(1)
, mName(name)
, mMeleeAttackDamage(30)
, mRangedAttackDamage(20)
, mArmorAttackReduction(5) {}
FragTrap::~FragTrap() {};
FragTrap::FragTrap(const FragTrap& rhs)
{
	init(rhs);
}
const FragTrap&	FragTrap::operator=(const FragTrap& rhs)
{
	init(rhs);
	return *this;
}
void FragTrap::rangedAttack(std::string const& target)
{
	std::cout << target << " attacks at range, causing points of damage!" << std::endl;
}
void FragTrap::meleeAttack(std::string const& target)
{

}
void FragTrap::takeDamage(unsigned int amount)
{

}
void FragTrap::beRepaired(unsigned int amount)
{

}
