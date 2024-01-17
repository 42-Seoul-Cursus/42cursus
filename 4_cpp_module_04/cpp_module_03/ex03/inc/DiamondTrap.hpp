#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string mName;
	void init(const DiamondTrap& rhs);
public:
	DiamondTrap();
	DiamondTrap(const std::string& name);
	~DiamondTrap();
	DiamondTrap(const DiamondTrap& rhs);
	const DiamondTrap&	operator=(const DiamondTrap& rhs);
	void	attack(const std::string& target);
};

#endif 

/* 
In this exercise, you will create a monster: a ClapTrap that’s half FragTrap, half
ScavTrap. It will be named DiamondTrap, and it will inherit from both the FragTrap
AND the ScavTrap. This is so risky!
The DiamondTrap class will have a name private attribute. Give to this attribute
exactly the same variable’s name (not talking about the robot’s name here) than the one
in the ClapTrap base class.
To be more clear, here are two examples.
If ClapTrap’s variable is name, give the name name to the one of the DiamondTrap.
If ClapTrap’s variable is _name, give the name _name to the one of the DiamondTrap.
Its attributes and member functions will be picked from either one of its parent classes:
• Name, which is passed as parameter to a constructor
• ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
• Hit points (FragTrap)
• Energy points (ScavTrap)
• Attack damage (FragTrap)
• attack() (Scavtrap)
 */

/* 
이 연습에서는 절반은 FragTrap, 절반은
스카브트랩입니다. 이 몬스터의 이름은 다이아몬드트랩(DiamondTrap)이며, 파편트랩과 스캐브트랩의
모두 상속받게 됩니다. 이건 너무 위험합니다!
DiamondTrap 클래스에는 이름 비공개 속성이 있습니다. 이 속성에
에 로봇의 이름과 정확히 동일한 변수 이름(여기서는 로봇의 이름을 말하는 것이 아닙니다)을 지정합니다.
과 똑같은 이름을 지정합니다.
더 명확하게 설명하기 위해 두 가지 예를 들어보겠습니다.
ClapTrap의 변수가 이름인 경우, 다이아몬드 트랩의 변수에 이름을 부여합니다.
ClapTrap의 변수가 _name이면 DiamondTrap 중 하나에 _name이라는 이름을 부여합니다.
그 속성과 멤버 함수는 부모 클래스 중 하나에서 선택됩니다:
- 생성자에 매개변수로 전달되는 이름, 생성자에 전달되는 이름
- ClapTrap::name(생성자의 매개변수 + "_clap_name" 접미사)
- 명중 포인트 (FragTrap)
- 에너지 포인트(ScavTrap)
- 공격 피해 (조각트랩)
- 공격() (스캐브트랩)
*/
