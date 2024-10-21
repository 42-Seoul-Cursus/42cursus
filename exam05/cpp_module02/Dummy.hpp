#ifndef DUMMY_HPP
#define DUMMY_HPP

#include "ATarget.hpp"

class Dummy : public ATarget
{
public:
    Dummy();
    Dummy(const Dummy& rhs);
    virtual ~Dummy();
    const Dummy& operator=(const Dummy& rhs);
    virtual Dummy* clone(void) const;
};

#endif
