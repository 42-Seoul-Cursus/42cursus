#include <iostream>
#include "Cure.hpp"

Cure::Cure()
: AMateria("cure") {}
Cure::~Cure() {}
Cure::Cure(const Cure& rhs)
: AMateria("cure")
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
	std::cout << "* heals " << target.getName()  << "'s wounds *" << std::endl;
}
