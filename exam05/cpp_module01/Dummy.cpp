#include "Dummy.hpp"

Dummy::Dummy()
: ATarget("Target Practice Dummy")
{
}
Dummy::Dummy(const Dummy& rhs)
: ATarget(rhs.getType())
{
}
Dummy::~Dummy()
{
}
const Dummy& Dummy::operator=(const Dummy& rhs)
{
    if (this != &rhs)
    {
        type = rhs.getType();
    }
    return *this;
}
Dummy* Dummy::clone(void) const
{
    return new Dummy;
}
