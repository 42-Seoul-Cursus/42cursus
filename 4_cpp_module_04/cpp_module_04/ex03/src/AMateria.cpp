#include "iostream"
#include "AMateria.hpp"

AMateria::AMateria(std::string const& type)
: mType(type) {}
AMateria::~AMateria() {};
std::string const& AMateria::getType() const
{
	return mType;
}
void AMateria::use(ICharacter& target)
{
	// std::cout << "Can't do anything to the " << target << "..." << std::endl;
}
