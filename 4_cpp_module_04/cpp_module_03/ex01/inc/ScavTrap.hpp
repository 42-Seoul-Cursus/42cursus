#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "FragTrap.hpp"

class ScavTrap : public FragTrap
{
public:
	ScavTrap();
	ScavTrap(const std::string& name);
	~ScavTrap();
	ScavTrap(const ScavTrap& rhs);
	const ScavTrap&	operator=(const ScavTrap& rhs);
	void	guardGate();
};

#endif 
