#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <IMateriaSource.hpp>

/* 
MateriaSource 클래스는 IMateriaSource를 구현한 구체적인 클래스로, 마법을 학습하고 생성하는 기능을 구현합니다.
최대 4개의 마법을 학습할 수 있습니다
*/

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
