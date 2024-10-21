#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include "SpellBook.hpp"

class ASpell;
class ATarget;

class Warlock
{
private:
    std::string name;
    std::string title;
    SpellBook spellBook;
    Warlock(const Warlock& rhs);
    const Warlock& operator=(const Warlock& rhs);

public:
    Warlock(const std::string& name, const std::string& title);
    ~Warlock();
    const std::string& getName(void) const;
    const std::string& getTitle(void) const;
    void setTitle(const std::string& title);
    void introduce(void) const;
    void learnSpell(ASpell* spell);
    void forgetSpell(const std::string& name);
    void launchSpell(const std::string& name, const ATarget& target) const;
};

#endif
