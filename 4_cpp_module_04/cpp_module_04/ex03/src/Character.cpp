#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(const std::string& name)
: mName(name)
, mIdx(0)
{
	for (size_t i = 0; i < 4; i++)
	{
		mInventory[i] = NULL;
	}
}
Character::Character(const Character& rhs)
: mName(rhs.mName)
, mIdx(rhs.mIdx)
{
	for (size_t i = 0; i < mIdx; i++)
	{
		mInventory[i] = rhs.mInventory[i];
	}
}
Character::~Character() {}
const Character& Character::operator=(const Character& rhs)
{
	if (this != &rhs)
	{
		mIdx = rhs.mIdx;
		for (size_t i = 0; i < mIdx; i++)
		{
			mInventory[i] = rhs.mInventory[i];
		}
	}
	return *this;
}
const std::string& Character::getName() const
{
	return mName;
}
void Character::equip(AMateria *m)
{
	if (mIdx == 4)
	{
		return ;
	}
	mInventory[mIdx++] = m;
}
void Character::unequip(int idx)
{
	if (!(0 <= idx && static_cast<size_t>(idx) < mIdx))
	{
		return ;
	}
	mInventory[idx] = NULL;
}
void Character::use(int idx, ICharacter &target)
{
	if (!(0 <= idx && static_cast<size_t>(idx) < mIdx))
	{
		return ;
	}
	mInventory[idx]->use(target);
}
