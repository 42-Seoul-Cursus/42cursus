#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <map>

class ASpell;
class ATarget;

class Warlock
{
private:
    std::string name;
    std::string title;
    std::map<std::string, ASpell*> spells;

public:
    Warlock(const std::string& name, const std::string& title);
    ~Warlock();
    Warlock(const Warlock& rhs);
    const Warlock& operator=(const Warlock& rhs);
    const std::string& getName(void) const;
    const std::string& getTitle(void) const;
    void setTitle(const std::string& title);
    void introduce(void) const;
    void learnSpell(ASpell* spell);
    void forgetSpell(const std::string& name);
    void launchSpell(const std::string& name, const ATarget& target) const;
};

#endif
