#include "ScavTrap.hpp"

ScavTrap::ScavTrap();
ScavTrap::ScavTrap(const std::string& name);
ScavTrap::~ScavTrap();
ScavTrap::ScavTrap(const ScavTrap& rhs);
const ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs);
void	ScavTrap::guardGate();
