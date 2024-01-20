#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	virtual ~Cure();
	Cure(const Cure& rhs);
	const Cure&			operator=(const Cure& rhs);
	virtual AMateria*	clone() const;
	virtual void		use(ICharacter& target);
};

#endif 
