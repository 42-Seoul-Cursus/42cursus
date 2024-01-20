#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string mType;
public:
	AMateria(std::string const& type);
	virtual ~AMateria();
	AMateria(const AMateria& rhs);
	const AMateria&		operator=(const AMateria& rhs);
	std::string const&	getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};

#endif 
