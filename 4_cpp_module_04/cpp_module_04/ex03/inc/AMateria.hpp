#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria
{
private:
	std::string mType;
	AMateria(const AMateria& rhs);
	const AMateria& operator=(const AMateria& rhs);
public:
	AMateria(std::string const& type);
	virtual ~AMateria();
	std::string const&	getType() const; //Returns the materia type
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};

#endif 
