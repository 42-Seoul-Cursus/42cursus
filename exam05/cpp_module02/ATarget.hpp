#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>

class ASpell;

class ATarget
{
protected:
    std::string type;

public:
    ATarget(const std::string& type);
    ATarget(const ATarget& rhs);
    virtual ~ATarget();
    const ATarget& operator=(const ATarget& rhs);
    const std::string& getType(void) const;
    virtual ATarget* clone(void) const = 0;
    void getHitBySpell(const ASpell& spell) const;
};

#endif
