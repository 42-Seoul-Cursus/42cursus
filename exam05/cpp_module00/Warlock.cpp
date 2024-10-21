#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title)
: name(name)
, title(title)
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock()
{
    std::cout << name << ": My job here is done!" << std::endl;
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
