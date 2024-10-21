#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget(const std::string& type)
: type(type)
{
}
ATarget::ATarget(const ATarget& rhs)
: type(rhs.type)
{
}
const ATarget& ATarget::operator=(const ATarget& rhs)
{
    if (this != &rhs)
    {
        type = rhs.type;
    }
    return *this;
}
ATarget::~ATarget()
{
}
const std::string& ATarget::getType(void) const
{
    return type;
}
void ATarget::getHitBySpell(const ASpell& spell) const
{
    std::cout << type << " has been " << spell.getEffects() << '!' << std::endl;
}
