#include "Fwoosh.hpp"

Fwoosh::Fwoosh()
: ASpell("Fwoosh", "fwooshed")
{
}
Fwoosh::Fwoosh(const Fwoosh& rhs)
: ASpell(rhs)
{
}
Fwoosh::~Fwoosh()
{
}
const Fwoosh& Fwoosh::operator=(const Fwoosh& rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return *this;
}
Fwoosh* Fwoosh::clone(void) const
{
    return new Fwoosh();
}
