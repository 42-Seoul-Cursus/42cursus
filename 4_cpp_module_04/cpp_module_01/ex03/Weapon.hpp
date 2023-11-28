#include <iostream>
#include <string>

class Weapon
{
private:
	/* data */
public:
	Weapon(/* args */);
	~Weapon();
	void				setType();
	std::string	getType() const;
};

Weapon::Weapon(/* args */)
{
}

Weapon::~Weapon()
{
}
