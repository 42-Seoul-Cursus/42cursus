#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock
{
private:
    std::string name;
    std::string title;

public:
    Warlock(const std::string& name, const std::string& title);
    Warlock(const Warlock& rhs);
    ~Warlock();
    const Warlock& operator=(const Warlock& rhs);
    const std::string& getName(void) const;
    const std::string& getTitle(void) const;
    void setTitle(const std::string& title);
    void introduce(void) const;
};

#endif
