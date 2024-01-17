#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
	void	init(const FragTrap& rhs);
public:
	FragTrap();
	FragTrap(const std::string& name);
	~FragTrap();
	FragTrap(const FragTrap& rhs);
	const FragTrap&	operator=(const FragTrap& rhs);
	void	highFivesGuys(void);
};

#endif 
