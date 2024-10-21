#ifndef SPELL_BOOK_HPP
#define SPELL_BOOK_HPP

#include <map>

class ASpell;

class SpellBook
{
private:
    std::map<std::string, ASpell*> spells;
    SpellBook(const SpellBook& rhs);
    const SpellBook& operator=(const SpellBook& rhs);

public:
    SpellBook();
    ~SpellBook();
    void learnSpell(ASpell* spell);
    void forgetSpell(const std::string& name);
    ASpell* createSpell(const std::string& name) const;
};

#endif
