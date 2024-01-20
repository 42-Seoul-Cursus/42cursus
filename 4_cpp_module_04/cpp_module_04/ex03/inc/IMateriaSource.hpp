#ifndef IMATERIASOURCE
#define IMATERIASOURCE

#include <AMateria.hpp>

/* 
IMateriaSource 인터페이스는 마법을 학습하고 생성하는 기능을 정의합니다.
learnMateria(AMateria *m)은 마법을 학습하여 저장하는 함수입니다.
createMateria(std::string const &type)은 특정 타입의 마법을 생성하는 함수입니다.
*/

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
