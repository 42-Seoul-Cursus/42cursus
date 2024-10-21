#include "Fireball.hpp"

Fireball::Fireball()
: ASpell("Fireball", "burnt to a crisp")
{
}
Fireball::Fireball(const Fireball& rhs)
: ASpell(rhs)
{
}
Fireball::~Fireball()
{
}
const Fireball& Fireball::operator=(const Fireball& rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return *this;
}
Fireball* Fireball::clone(void) const
{
    return new Fireball();
}
