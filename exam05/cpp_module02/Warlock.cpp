#include "Warlock.hpp"
#include "ASpell.hpp"

Warlock::Warlock(const std::string& name, const std::string& title)
: name(name)
, title(title)
, spellBook()
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock()
{
    std::cout << name << ": My job here is done!" << std::endl;
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
        spellBook.learnSpell(spell);
}
void Warlock::forgetSpell(const std::string& name)
{
    spellBook.forgetSpell(name);
}
void Warlock::launchSpell(const std::string& name, const ATarget& target) const
{
    const ASpell* spell = spellBook.createSpell(name);
    if (spell)
    {
        spell->launch(target);
        delete spell;
    }
}
