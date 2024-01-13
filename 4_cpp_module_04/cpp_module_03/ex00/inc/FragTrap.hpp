#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>

class FragTrap
{
private:
	int mHitPoint;
	int mMaxHitPoints;
	int mEnergyPoints;
	int mMaxEnergyPoints;
	int mLevel;
	std::string mName;
	int mMeleeAttackDamage;
	int mRangedAttackDamage;
	int mArmorAttackReduction;
	void init(const FragTrap& rhs);
public:
	FragTrap(const std::string& name);
	~FragTrap();
	FragTrap(const FragTrap& rhs);
	const FragTrap&	operator=(const FragTrap& rhs);
	void rangedAttack(std::string const& target);
	void meleeAttack(std::string const& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

void VaultHunter_dot_exe(std::string const& target);

#endif 
