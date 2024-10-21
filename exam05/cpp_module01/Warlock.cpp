#include "Warlock.hpp"
#include "ASpell.hpp"

Warlock::Warlock(const std::string& name, const std::string& title)
: name(name)
, title(title)
, spells()
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock()
{
    std::cout << name << ": My job here is done!" << std::endl;

    for (std::map<std::string, ASpell*>::iterator it = spells.begin(); it != spells.end(); ++it)
    {
        delete it->second;
    }
    spells.clear();
}
Warlock::Warlock(const Warlock& rhs)
: name(rhs.name)
, title(rhs.title)
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}
const Warlock& Warlock::operator=(const Warlock& rhs)
{
    if (this != &rhs)
    {
        name = rhs.name;
        title = rhs.title;

        for (std::map<std::string, ASpell*>::iterator it = spells.begin(); it != spells.end(); ++it)
        {
            delete it->second;
        }
        spells.clear();
        for (std::map<std::string, ASpell*>::const_iterator it = rhs.spells.begin(); it != spells.end(); ++it)
        {
            spells[it->first] = it->second;
        }
    }

    return *this;
}
const std::string& Warlock::getName(void) const
{
    return name;
}
const std::string& Warlock::getTitle(void) const
{
    return title;
}
void Warlock::setTitle(const std::string& title)
{
    this->title = title;
}
void Warlock::introduce(void) const
{
    std::cout << name << ": I am " << name << ", " << title << '!' << std::endl;
}
void Warlock::learnSpell(ASpell* spell)
{
    if (spell)
        spells.insert(std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
}
void Warlock::forgetSpell(const std::string& name)
{
    std::map<std::string, ASpell*>::iterator it = spells.find(name);
    if (it != spells.end())
        delete it->second;
    spells.erase(name);
}
void Warlock::launchSpell(const std::string& name, const ATarget& target) const
{
    std::map<std::string, ASpell*>::const_iterator it = spells.find(name);
    if (it != spells.end())
        it->second->launch(target);
}
