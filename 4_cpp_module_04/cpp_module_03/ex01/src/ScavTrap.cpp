#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() 
: ClapTrap()
{
	SetHitPoints(100);
	SetEnergyPoints(50);
	SetAttackDamage(20);
	std::cout << "ScavTrap " << GetName() << " is created" << std::endl;
}
ScavTrap::ScavTrap(const std::string& name) 
: ClapTrap(name)
{
	SetHitPoints(100);
	SetEnergyPoints(50);
	SetAttackDamage(20);
	std::cout << "ScavTrap " << GetName() << " is created" << std::endl;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << GetName() << " is destroyed" << std::endl;
};
void ScavTrap::init(const ScavTrap& rhs)
{
	SetName(rhs.GetName());
	SetHitPoints(rhs.GetHitPoints());
	SetEnergyPoints(rhs.GetEnergyPoints());
	SetAttackDamage(rhs.GetAttackDamage());
}
ScavTrap::ScavTrap(const ScavTrap& rhs)
: ClapTrap(rhs)
{
	init(rhs);
	std::cout << "ScavTrap " << GetName() << " is created as a copy" << std::endl;
}
const ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs)
{
	init(rhs);
	std::cout << "ScavTrap " << GetName() << " is copied" << std::endl;
	return *this;
}
void ScavTrap::attack(const std::string& target)
{
	if (GetHitPoints() == 0)
	{
		std::cout << "\033[0;31m" 
		<< "ClapTrap " << GetName() << " can`t do anything because it has no hit point..." 
		<< "\033[0m" << std::endl;
		return ;
	}
	if (GetEnergyPoints() == 0)
	{
		std::cout << "\033[0;33m" 
		<< "ClapTrap " << GetName() << " can`t do anything because it has no energy point..." 
		<< "\033[0m" << std::endl;
		return ;
	}
	std::cout << "\033[0;32m" 
	<< "ScavTrap " << GetName() << " attacks " << target << ", causing " << GetAttackDamage() << " points of damage!" 
	<< "\033[0m" << std::endl;
	SetEnergyPoints(GetEnergyPoints() - 1);
}
void ScavTrap::guardGate()
{
	std::cout << "\033[0;37m" 
	<< "ScavTrap " << GetName() << " is now in Gate" 
	<< "\033[0m" << std::endl;
}
