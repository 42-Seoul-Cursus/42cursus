#include "Ice.hpp"

Ice::Ice()
: AMateria("ice") {}
Ice::~Ice() {}
Ice::Ice(const Ice& rhs)
: AMateria("ice")
{
	mType = rhs.mType;
}
AMateria* Ice::clone()
{
	return new Ice(*this);
}
const Ice& Ice::operator=(const Ice& rhs)
{
	mType = rhs.mType;
}
void Ice::use(ICharacter& target)
{
	// std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
}
