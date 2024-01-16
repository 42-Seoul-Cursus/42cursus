#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>

class FragTrap
{
private:
	std::string mName;
	int mHitPoints;
	int mEnergyPoints;
	int mAttackDamage;
public:
	FragTrap();
	FragTrap(const std::string& name);
	~FragTrap();
	FragTrap(const FragTrap& rhs);
	const FragTrap&	operator=(const FragTrap& rhs);
	void	 attack(const std::string& target);
	void	 takeDamage(unsigned int amount);
	void	 beRepaired(unsigned int amount);
};

void VaultHunter_dot_exe(std::string const& target);

#endif 
