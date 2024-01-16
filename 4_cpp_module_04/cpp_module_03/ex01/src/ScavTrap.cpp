#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() 
: FragTrap()
{
	SetHitPoints(100);
	SetEnergyPoints(50);
	SetAttackDamage(20);
	std::cout << "ScavTrap " << GetName() << " is created" << std::endl;
}
ScavTrap::ScavTrap(const std::string& name) 
: FragTrap(name)
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
ScavTrap::ScavTrap(const ScavTrap& rhs)
{
	SetName(rhs.GetName());
	SetHitPoints(rhs.GetHitPoints());
	SetEnergyPoints(rhs.GetEnergyPoints());
	SetAttackDamage(rhs.GetAttackDamage());
	std::cout << "ScavTrap " << GetName() << " is created as a copy" << std::endl;
}
const ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs)
{
	SetName(rhs.GetName());
	SetHitPoints(rhs.GetHitPoints());
	SetEnergyPoints(rhs.GetEnergyPoints());
	SetAttackDamage(rhs.GetAttackDamage());
	std::cout << "ScavTrap " << GetName() << " is copied" << std::endl;
	return *this;
}
void ScavTrap::attack(const std::string& target)
{
	if (GetHitPoints() <= 0)
	{
		std::cout << "ScavTrap " << GetName() << " has no hit point and can`t do anything..." << std::endl;
		return ;
	}
	if (GetEnergyPoints() <= 0)
	{
		std::cout << "ScavTrap " << GetName() << " has no energy point and can`t do anything..." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << GetName() << " attacks " << target << ", causing " << GetAttackDamage() << " points of damage!" << std::endl;
	SetEnergyPoints(GetEnergyPoints() - 1);
}
void ScavTrap::guardGate()
{
	if (GetHitPoints() <= 0)
	{
		std::cout << "ScavTrap " << GetName() << " has no hit point and can`t do anything..." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << GetName() << " is now in Gate" << std::endl;
}
