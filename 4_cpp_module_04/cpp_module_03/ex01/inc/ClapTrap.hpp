#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
private:
	std::string mName;
	unsigned int mHitPoints;
	unsigned int mEnergyPoints;
	unsigned int mAttackDamage;
	static const unsigned int mMaxHP = 2000;
public:
	ClapTrap();
	ClapTrap(const std::string& name);
	~ClapTrap();
	ClapTrap(const ClapTrap& rhs);
	const ClapTrap&	operator=(const ClapTrap& rhs);
	void				attack(const std::string& target);
	void				takeDamage(unsigned int amount);
	void				beRepaired(unsigned int amount);
	void				SetName(const std::string& name);
	const std::string&	GetName(void) const;
	void 				SetHitPoints(const unsigned int hitPoints);
	int					GetHitPoints(void) const;
	void 				SetEnergyPoints(const unsigned int energyPoints);
	int					GetEnergyPoints(void) const;
	void 				SetAttackDamage(const unsigned int attackDamage);
	int					GetAttackDamage(void) const;
};

#endif 
