#include "Cure.hpp"

Cure::Cure()
: AMateria("ice") {}
Cure::~Cure() {}
AMateria* Cure::clone()
{
	Cure* other = new Cure;
	return other;
}
void Cure::use(ICharacter& target)
{
	// std::cout << "* heals " << target << "’s wounds *" << std::endl;
}
