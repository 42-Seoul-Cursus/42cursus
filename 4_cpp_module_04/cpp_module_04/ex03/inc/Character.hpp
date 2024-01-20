#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

/* 
Character 클래스는 ICharacter를 구현한 구체적인 캐릭터 클래스입니다.
4개의 슬롯으로 이루어진 인벤토리를 관리하며, 마법을 장착, 해제, 사용하는 기능을 구현합니다.
깊은 복사를 지원하여 캐릭터를 복제할 때 마법도 복제합니다.
*/

class Character : public ICharacter
{
private:
	std::string mName;
	AMateria* mInventory[4];
	size_t mIdx;
public:
	Character(const std::string& name);
	Character(const Character& rhs);
	virtual ~Character();
	const Character&			operator=(const Character& rhs);
	virtual std::string const&	getName() const;
	virtual void				equip(AMateria *m);
	virtual void				unequip(int idx);
	virtual void				use(int idx, ICharacter &target);
};

#endif
