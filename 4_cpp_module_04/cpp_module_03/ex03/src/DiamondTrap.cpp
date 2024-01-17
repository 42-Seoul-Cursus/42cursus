#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	ScavTrap::SetName("default_clap_name");
	FragTrap::SetHitPoints(FragTrap::GetHitPoints());
	ScavTrap::SetEnergyPoints(ScavTrap::GetEnergyPoints());
	FragTrap::SetAttackDamage(FragTrap::GetAttackDamage());
	std::cout << "DiamondTrap " << ScavTrap::GetName() << " is created" << std::endl;
}
DiamondTrap::DiamondTrap(const std::string& name)
{
	ScavTrap::SetName(name + "_clap_name");
	FragTrap::SetHitPoints(FragTrap::GetHitPoints());
	ScavTrap::SetEnergyPoints(ScavTrap::GetEnergyPoints());
	FragTrap::SetAttackDamage(FragTrap::GetAttackDamage());
	std::cout << "DiamondTrap " << ScavTrap::GetName() << " is created" << std::endl;
}
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << ScavTrap::GetName() << " is destroyed" << std::endl;
}
void DiamondTrap::init(const DiamondTrap& rhs)
{
	ScavTrap::SetName(rhs.ScavTrap::GetName());
	FragTrap::SetHitPoints(rhs.FragTrap::GetHitPoints());
	ScavTrap::SetEnergyPoints(rhs.ScavTrap::GetEnergyPoints());
	FragTrap::SetAttackDamage(rhs.FragTrap::GetAttackDamage());
}
DiamondTrap::DiamondTrap(const DiamondTrap& rhs)
{
	init(rhs);
	std::cout << "DiamondTrap " << ScavTrap::GetName() << " is created as a copy" << std::endl;
}
const DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& rhs)
{
	init(rhs);
	std::cout << "DiamondTrap " << ScavTrap::GetName() << " is copied" << std::endl;
	return *this;
}
void DiamondTrap::attack(const std::string& target)
{
	if (FragTrap::GetHitPoints() == 0)
	{
		std::cout << "\033[0;31m" 
		<< "DiamondTrap " << ScavTrap::GetName() << " can`t do anything because it has no hit point..." 
		<< "\033[0m" << std::endl;
		return ;
	}
	if (ScavTrap::GetEnergyPoints() == 0)
	{
		std::cout << "\033[0;33m" 
		<< "DiamondTrap " << ScavTrap::GetName() << " can`t do anything because it has no energy point..." 
		<< "\033[0m" << std::endl;
		return ;
	}
	std::cout << "\033[0;32m" 
	<< "DiamondTrap " << ScavTrap::GetName() << " attacks " << target << ", causing " << FragTrap::GetAttackDamage() << " points of damage!" 
	<< "\033[0m" << std::endl;
	ScavTrap::SetEnergyPoints(ScavTrap::GetEnergyPoints() - 1);
}
