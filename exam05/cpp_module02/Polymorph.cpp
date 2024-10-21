#include "Polymorph.hpp"

Polymorph::Polymorph()
: ASpell("Polymorph", "turned into a critter")
{
}
Polymorph::Polymorph(const Polymorph& rhs)
: ASpell(rhs)
{
}
Polymorph::~Polymorph()
{
}
const Polymorph& Polymorph::operator=(const Polymorph& rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return *this;
}
Polymorph* Polymorph::clone(void) const
{
    return new Polymorph();
}
