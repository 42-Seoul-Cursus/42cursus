#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

/* 
AMateria 클래스 (Abstract Base Class):

AMateria 클래스는 마법의 기본 형태를 나타내는 추상 베이스 클래스입니다.
type 멤버 변수는 마법의 타입을 나타냅니다.
clone()은 순수 가상 함수로, 해당 마법을 복제한 새로운 인스턴스를 반환합니다.
use(ICharacter &target)은 순수 가상 함수로, 해당 마법을 사용할 때의 동작을 정의합니다.
*/
class AMateria
{
protected:
	std::string mType;
private:
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
