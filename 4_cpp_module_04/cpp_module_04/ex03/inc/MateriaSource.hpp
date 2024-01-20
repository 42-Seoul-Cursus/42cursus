#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <IMateriaSource.hpp>

class MateriaSource : public IMateriaSource
{
private:
	AMateria* mLearnedMaterias[4];
	size_t mIdx;
public:
	MateriaSource();
	virtual ~MateriaSource();
	MateriaSource(const MateriaSource& rhs);
	const MateriaSource&	operator=(const MateriaSource& rhs);
	virtual void			learnMateria(AMateria *m);
	virtual AMateria*		createMateria(std::string const &type);
};

#endif
