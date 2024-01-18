#include "Ice.hpp"

Ice::Ice()
: AMateria("ice") {}
Ice::~Ice() {}
AMateria* Ice::clone()
{
	Ice* other = new Ice;
	return other;
}
void Ice::use(ICharacter& target)
{
	// std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
}
