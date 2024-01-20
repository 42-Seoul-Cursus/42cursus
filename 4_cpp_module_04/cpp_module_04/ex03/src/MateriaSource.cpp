#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
: mIdx(0) {}
MateriaSource::~MateriaSource() {}
MateriaSource::MateriaSource(const MateriaSource& rhs)
: mIdx(rhs.mIdx)
{
	for (size_t i = 0; i < mIdx; i++)
	{
		mLearnedMaterias[i] = rhs.mLearnedMaterias[i];
	}
}
const MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	if (this != &rhs)
	{
		mIdx = rhs.mIdx;
		for (size_t i = 0; i < mIdx; i++)
		{
			mLearnedMaterias[i] = rhs.mLearnedMaterias[i];
		}
	}
	return *this;
}
void MateriaSource::learnMateria(AMateria *m)
{
	mLearnedMaterias[mIdx++] = m->clone();
}
AMateria* MateriaSource::createMateria(std::string const &type)
{
	if (type == "ice")
	{
		return new Ice;
	}
	if (type == "cure")
	{
		return new Cure;
	}
	return 0;
}
