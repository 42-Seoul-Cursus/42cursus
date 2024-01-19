#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
private:
	Cure(const Cure& rhs);
	const Cure& operator=(const Cure& rhs);
public:
	Cure();
	~Cure();
	virtual AMateria*	clone();
	virtual void		use(ICharacter& target);
};

#endif 
