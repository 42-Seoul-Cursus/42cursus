#include <iostream>
#include "Cure.hpp"

Cure::Cure()
: AMateria("Cure") {}
Cure::~Cure() {}
Cure::Cure(const Cure& rhs)
: AMateria("Cure")
{
	mType = rhs.mType;
}
const Cure& Cure::operator=(const Cure& rhs)
{
	mType = rhs.mType;
	return *this;
}
AMateria* Cure::clone() const
{
	return new Cure(*this);
}
void Cure::use(ICharacter& target)
{
	std::cout << "* shoots an Cure bolt at " << target.getName() << " *" << std::endl;
}
