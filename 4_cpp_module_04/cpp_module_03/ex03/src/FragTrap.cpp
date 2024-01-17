#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap() 
: ClapTrap()
{
	SetHitPoints(100);
	SetEnergyPoints(100);
	SetAttackDamage(30);
	std::cout << "FragTrap " << GetName() << " is created" << std::endl;
}
FragTrap::FragTrap(const std::string& name) 
: ClapTrap(name)
{
	SetHitPoints(100);
	SetEnergyPoints(100);
	SetAttackDamage(30);
	std::cout << "FragTrap " << GetName() << " is created" << std::endl;
}
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << GetName() << " is destroyed" << std::endl;
};
void FragTrap::init(const FragTrap& rhs)
{
	SetName(rhs.GetName());
	SetHitPoints(rhs.GetHitPoints());
	SetEnergyPoints(rhs.GetEnergyPoints());
	SetAttackDamage(rhs.GetAttackDamage());
}
FragTrap::FragTrap(const FragTrap& rhs)
{
	init(rhs);
	std::cout << "FragTrap " << GetName() << " is created as a copy" << std::endl;
}
const FragTrap&	FragTrap::operator=(const FragTrap& rhs)
{
	init(rhs);
	std::cout << "FragTrap " << GetName() << " is copied" << std::endl;
	return *this;
}
void FragTrap::highFivesGuys(void)
{
	std::cout << "🙋 High Five guys 🙋" << std::endl;
}
