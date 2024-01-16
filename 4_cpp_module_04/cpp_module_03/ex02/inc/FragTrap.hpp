#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	void	init(const FragTrap& rhs);
public:
	FragTrap();
	FragTrap(const std::string& name);
	~FragTrap();
	FragTrap(const FragTrap& rhs);
	const FragTrap&	operator=(const FragTrap& rhs);
	void	highFivesGuys(void);
};

#endif 

/* 
박수 트랩을 만드는 것이 신경이 쓰이기 시작했을 것입니다.
이제 ClapTrap을 상속하는 FragTrap 클래스를 구현해 봅시다. 다음과 매우 유사합니다.
ScavTrap과 매우 유사합니다. 하지만 생성 및 소멸 메시지가 달라야 합니다. 적절한
생성/소멸 연쇄가 테스트에 표시되어야 합니다. 프래그트랩이 생성되면
생성되면, 프로그램은 박수 트랩을 생성하는 것으로 시작합니다. 소멸은 역순으로 진행됩니다.
속성은 동일하지만 이번에는 다른 값을 사용합니다:
- 이름: 생성자에 매개변수로 전달되는 이름입니다.
- 히트 포인트(100), 박수 트랩의 체력을 나타냅니다.
- 에너지 포인트 (100)
- 공격 피해 (30)
FragTrap에는 특별한 용량도 있습니다:
void highFivesGuys(void);
이 멤버 함수는 표준 출력에 양수 하이파이브 요청을 표시합니다.
다시 말하지만, 프로그램에 테스트를 더 추가하세요. 
*/
