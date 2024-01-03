## ex03

```cpp
Weapon club = Weapon("crude spiked club");
HumanA bob("Bob", club);
bob.attack();
// deep copy를 하게 되면 crude spiked club 출력이 된다.
// some other type of club 출력을 위해서는 shallow copy를 해야 한다.
club.setType("some other type of club");
bob.attack();
```

```cpp
class HumanA
{
private:
	std::string mName;
	Weapon* mWeapon; // shallow copy를 위해 Weapon 클래스의 포인터를 사용한다.
public:
	HumanA(std::string name, Weapon& weapon) // Weapon에 대한 레퍼런스를 받아야 원본 객체를 가리키게 된다.
	{
		mName = name;
		mWeapon = &weapon;
	};
	void	attack(void) const;
};
```

```cpp
int main()
{
	HumanB jim("Jim");
	{
		Weapon club = Weapon("crude spiked club");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		// 여기서 club 객체가 소멸되면서 jim 객체의 무기도 소멸된다.
	}
	jim.attack(); // illegal Memory Access
}
```

HumanA 클래스의 생성자에서 Weapon 객체를 요구하면 Human보다 Weapon의 생명주기가 길거나 같다는 것을 보장받을 수 있으므로 레퍼런스를 통해 얕은 복사가 가능해지고 메모리 관리 측면에서 효율적이다.

HumanB 클래스의 생성자에서 Weapon 객체를 요구하지 않기 때문에 Human보다 Weapon의 생명주기가 길거나 같다는 것을 보장받을 수 없다.
그러므로 Weapon 객체의 레퍼런스를 얕은 복사하는 것은 위험하다.

결론 : HumanB 클래스에서 setWeapon을 사용할 때 동적할당하는 등의 방법을 고려해보았지만 Weapon 객체의 레퍼런스를 얕은 복사하는 것을 과제에서 원하고 있기 때문에 그렇게 하지 않았다.

## ex04

- cpp의 파일 입출력은 [fstream](https://cplusplus.com/reference/fstream/fstream/)를 사용한다.
  - [참고 블로그](https://blockdmask.tistory.com/322)
  - [참고 사이트](https://www.mygreatlearning.com/blog/file-handling-in-cpp/)
	```cpp
	// 원래 짰던 코드
	// while (!readFile.eof())
	// {
	// 	std::string s;

	// 	std::getline(readFile, s);
	// 	// s.append("\n");
	// 	writeFile.write(s.c_str(), s.length());
	// }

	char c;
  while (readFile.get(c))  // get 함수로 문자 하나씩 읽어오기
  {
	  writeFile.put(c);  // 파일에 문자 하나씩 쓰기
  }
	```
