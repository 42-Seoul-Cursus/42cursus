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
	virtual void		attack(const std::string& target);
	void	 			takeDamage(unsigned int amount);
	void	 			beRepaired(unsigned int amount);
	void				SetName(const std::string& name);
	const std::string&	GetName(void) const;
	void				SetHitPoints(const int hitPoints);
	int					GetHitPoints(void) const;
	void				SetEnergyPoints(const int energyPoints);
	int					GetEnergyPoints(void) const;
	void				SetAttackDamage(const int attackDamage);
	int					GetAttackDamage(void) const;
};

#endif 
