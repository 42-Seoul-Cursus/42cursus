#include "BrickWall.hpp"

BrickWall::BrickWall()
: ATarget("Inconspicuous Red-brick Wall")
{
}
BrickWall::BrickWall(const BrickWall& rhs)
: ATarget(rhs.getType())
{
}
BrickWall::~BrickWall()
{
}
const BrickWall& BrickWall::operator=(const BrickWall& rhs)
{
    if (this != &rhs)
    {
        type = rhs.getType();
    }
    return *this;
}
BrickWall* BrickWall::clone(void) const
{
    return new BrickWall;
}
