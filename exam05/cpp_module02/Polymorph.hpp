#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP

#include "ASpell.hpp"

class Polymorph : public ASpell
{
public:
    Polymorph();
    Polymorph(const Polymorph& rhs);
    virtual ~Polymorph();
    const Polymorph& operator=(const Polymorph& rhs);
    virtual Polymorph* clone(void) const;
};

#endif
