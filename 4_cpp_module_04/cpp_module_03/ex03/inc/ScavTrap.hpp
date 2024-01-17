#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:
	void	init(const ScavTrap& rhs);
public:
	ScavTrap();
	ScavTrap(const std::string& name);
	~ScavTrap();
	ScavTrap(const ScavTrap& rhs);
	const ScavTrap&	operator=(const ScavTrap& rhs);
	void	attack(const std::string& target);
	void	guardGate();
};

#endif 
