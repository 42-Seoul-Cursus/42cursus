#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
private:
	std::string mName;
public:
	Zombie();
	Zombie(const std::string name);
	~Zombie();
	const std::string&	getName() const;
	void				setName(const std::string name);
	void				announce(void) const;
};

void	randomChump( std::string name );
Zombie*	newZombie(std::string name);

#endif
