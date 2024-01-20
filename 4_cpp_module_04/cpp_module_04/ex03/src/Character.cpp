#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(const std::string& name)
{
	mName = name;
	for (mIdx = 0; mIdx < 4; ++mIdx)
	{
		mInventory[mIdx] = nullptr;
	}
}
Character::Character(const Character& rhs)
{
	mName = rhs.mName;
	for (mIdx = 0; mIdx < rhs.mIdx; ++mIdx)
	{
		mInventory[mIdx] = nullptr;
	}
}
Character::~Character() {}
const Character& Character::operator=(const Character& rhs)
{
	if (this != &rhs)
	{
		mName = rhs.mName;
		for (mIdx = 0; mIdx < rhs.mIdx; ++mIdx)
		{
			mInventory[mIdx] = rhs.mInventory[mIdx];
		}
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
	if (!(0 <= idx && static_cast<size_t>(idx) < mIdx))
	{
		return ;
	}
	mInventory[idx]->use(target);
}
