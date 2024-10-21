#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>

class ATarget;

class ASpell
{
protected:
    std::string name;
    std::string effects;

public:
    ASpell(const std::string& name, const std::string& effects);
    ASpell(const ASpell& rhs);
    virtual ~ASpell();
    const ASpell& operator=(const ASpell& rhs);
    const std::string& getName(void) const;
    const std::string& getEffects(void) const;
    virtual ASpell* clone(void) const = 0;
    void launch(const ATarget& target) const;
};

#endif
