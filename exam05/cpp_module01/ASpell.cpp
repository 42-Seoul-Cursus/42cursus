#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(const std::string& name, const std::string& effects)
: name(name)
, effects(effects)
{
}
ASpell::ASpell(const ASpell& rhs)
: name(rhs.name)
, effects(rhs.effects)
{
}
ASpell::~ASpell()
{
}
const ASpell& ASpell::operator=(const ASpell& rhs)
{
    if (this != &rhs)
    {
        name = rhs.name;
        effects = rhs.effects;
    }
    return *this;
}
const std::string& ASpell::getName(void) const
{
    return name;
}
const std::string& ASpell::getEffects(void) const
{
    return effects;
}
void ASpell::launch(const ATarget& target) const
{
    target.getHitBySpell(*this);
}
