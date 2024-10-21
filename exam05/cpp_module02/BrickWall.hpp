#ifndef BRICK_WALL_HPP
#define BRICK_WALL_HPP

#include "ATarget.hpp"

class BrickWall : public ATarget
{
public:
    BrickWall();
    BrickWall(const BrickWall& rhs);
    virtual ~BrickWall();
    const BrickWall& operator=(const BrickWall& rhs);
    virtual BrickWall* clone(void) const;
};

#endif
