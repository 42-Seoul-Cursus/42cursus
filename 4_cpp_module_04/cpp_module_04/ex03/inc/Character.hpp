#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string mName;
	size_t mIdx;
	AMateria* mInventory[4];
public:
	Character(const std::string& name);
	Character(const Character& rhs);
	virtual ~Character();
	const Character&			operator=(const Character& rhs);
	virtual std::string const&	getName() const;
	virtual void				equip(AMateria *m);
	virtual void				unequip(int idx);
	virtual void				use(int idx, ICharacter &target);
};

#endif
