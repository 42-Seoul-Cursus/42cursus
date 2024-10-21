#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include "ASpell.hpp"

class Fireball : public ASpell
{
public:
    Fireball();
    Fireball(const Fireball& rhs);
    virtual ~Fireball();
    const Fireball& operator=(const Fireball& rhs);
    virtual Fireball* clone(void) const;
};

#endif
