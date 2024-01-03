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
	void	setWeapon(Weapon weapon);
	void	attack(void) const;
};
```

## ex04

- cpp의 파일 입출력은 [fstream](https://cplusplus.com/reference/fstream/fstream/)를 사용한다.
  - [참고 블로그](https://blockdmask.tistory.com/322)
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
