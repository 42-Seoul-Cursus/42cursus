#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

/* 
Ice와 Cure 클래스는 AMateria를 상속받아 구체적인 마법을 구현합니다.
clone()과 use(ICharacter &target) 함수를 오버라이딩하여 구체적인 동작을 정의합니다.
*/

class Ice : public AMateria
{
public:
	Ice();
	virtual ~Ice();
	Ice(const Ice& rhs);
	const Ice&			operator=(const Ice& rhs);
	virtual AMateria*	clone() const;
	virtual void		use(ICharacter& target);
};

#endif 
