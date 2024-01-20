#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>
class AMateria;

/* 
ICharacter 인터페이스는 캐릭터의 기본 기능을 정의합니다.
getName()은 캐릭터의 이름을 반환합니다.
equip(AMateria *m)은 캐릭터가 마법을 장착하는 함수입니다.
unequip(int idx)는 특정 인덱스의 마법을 장착 해제하는 함수입니다.
use(int idx, ICharacter &target)은 특정 인덱스의 마법을 사용하는 함수입니다.
*/

class ICharacter
{
public:
	virtual ~ICharacter() {};
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif
