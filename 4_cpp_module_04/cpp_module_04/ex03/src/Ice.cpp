#include <iostream>
#include "Ice.hpp"

Ice::Ice()
: AMateria("ice") {}
Ice::~Ice() {}
Ice::Ice(const Ice& rhs)
: AMateria("ice")
{
	mType = rhs.mType;
}
const Ice& Ice::operator=(const Ice& rhs)
{
	mType = rhs.mType;
	return *this;
}
AMateria* Ice::clone() const
{
	return new Ice(*this);
}
void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
