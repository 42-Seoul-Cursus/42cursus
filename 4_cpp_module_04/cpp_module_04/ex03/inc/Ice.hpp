#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	~Ice();
	Ice(const Ice& rhs);
	const Ice&			operator=(const Ice& rhs);
	virtual AMateria*	clone();
	virtual void		use(ICharacter& target);
};

#endif 
