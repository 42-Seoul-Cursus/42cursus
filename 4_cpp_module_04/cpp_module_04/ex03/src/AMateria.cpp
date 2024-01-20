#include "iostream"
#include "AMateria.hpp"

AMateria::AMateria(std::string const& type)
: mType(type) {}
AMateria::AMateria(const AMateria& rhs)
: mType(rhs.mType) {}
const AMateria& AMateria::operator=(const AMateria& rhs)
{
	if (this != &rhs)
	{
		mType = rhs.mType;
	}
	return *this;
}
AMateria::~AMateria() {};
std::string const& AMateria::getType() const
{
	return mType;
}
void AMateria::use(ICharacter& target)
{
	std::cout << "Can't do anything to the " << target.getName() << "..." << std::endl;
}
