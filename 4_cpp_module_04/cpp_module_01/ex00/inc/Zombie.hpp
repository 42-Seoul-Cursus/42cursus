#include <iostream>
#include <string>

class Zombie
{
private:
	std::string mName;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void		setName(std::string name);
	std::string	getName();
	void		announce(void);
};

void	randomChump( std::string name );
Zombie*	newZombie(std::string name);
