#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(const std::string& name)
{
	mName = name;
	for (size_t i = 0; i < 4; i++)
	{
		mInventory[i] = nullptr;
	}
	mIdx = 0;
}
Character::Character(const Character& rhs)
{
	mName = rhs.mName;
	for (size_t i = 0; i < rhs.mIdx; i++)
	{
		mInventory[i] = rhs.mInventory[i];
	}
	mIdx = rhs.mIdx;
}
Character::~Character() {}
const Character& Character::operator=(const Character& rhs)
{
	if (this != &rhs)
	{
		mName = rhs.mName;
		for (size_t i = 0; i < rhs.mIdx; i++)
		{
			mInventory[i] = rhs.mInventory[i];
		}
		mIdx = rhs.mIdx;
	}
	return *this;
}
std::string const& Character::getName() const
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
	mInventory[idx] = nullptr;
}
void Character::use(int idx, ICharacter &target)
{
	if (!(0 < idx && static_cast<size_t>(idx) < mIdx))
	{
		return ;
	}
	mInventory[idx]->use(target);
}
