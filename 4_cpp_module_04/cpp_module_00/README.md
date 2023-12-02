## ex00

main 함수의 인자로 받은 문자열을 대문자로 출력하는 간단한 프로그램

나는 `PrintLowerToUpper`라는 함수를 만들어서 사용했지만 `toupper` 함수를 사용해도 무방하다.
`PrintLowerToUpper` 함수에서 대문자로 변환하는 과정을 '매개변수로 받은 문자 - 32' 를 해주는 것으로 구현했는데
이 과정에서 형변환을 해줘야 했다. 그렇지 않으면 `char` 타입의 문자가 `int` 타입으로 변환되었기 때문이다.

cpp에서는 형변환을 해주는 다양한 문법이 존재한다.

- [static_cast](https://en.cppreference.com/w/cpp/language/static_cast)
- [static_cast 연산자](https://learn.microsoft.com/ko-kr/cpp/cpp/static-cast-operator?view=msvc-170)
- [static_cast란](https://hwan-shell.tistory.com/211)

## ex01

`Phonebook`, `Contact` 클래스를 만들어서 전화번호부를 구현하는 프로그램

`Phonebook` 클래스는 `Contact` 클래스의 배열을 멤버로 가지고 있으며, `Contact` 클래스는 이름, 성, 전화번호를 멤버로 가지고 있다. (`Phonebook` 클래스 생성 시 `Contact` 클래스 생성자가 8번 호출된다.)

ADD, SEARCH, EXIT 명령어를 입력받아서 각각의 동작을 수행한다.
- ADD: `Phonebook` 클래스의 `AddContact` 함수를 호출한다.
	- `Phonebook` 클래스의 `AddContact` 함수는 `Contact` 클래스의 `Set(memberVars)` 함수를 호출한다.
- SEARCH: `Phonebook` 클래스의 `SearchContact` 함수를 호출한다.
	- `Phonebook` 클래스의 `SearchContact` 함수는 `Contact` 클래스의 `Get(memberVars)` 함수를 호출한다.
	- 각 열을 10칸으로 출력하기 위해 `setw` 함수를 사용하고, 10글자를 초과하는 문자열을 자르기 위해 `substr` 함수를 사용한다.
- EXIT: 프로그램을 종료한다.

```cpp
std::cin과 getline()을 같이 사용할 때 주의할 점이 있다.

std::cin은 입력 버퍼에 남아있는 '\n'을 읽지 않고 그대로 두기 때문에
getline()을 사용할 때 입력 버퍼에 남아있는 '\n'을 읽어들여서
getline()이 바로 종료되는 현상이 발생한다.

이를 해결하기 위해 std::cin.ignore()를 사용하여 입력 버퍼에 남아있는 '\n'을 지워준다.
```

- [cin과 getline()을 같이 사용할 때 주의할 점](https://velog.io/@copyrat90/cin%EA%B3%BC-getline%EC%9D%84-%EC%84%9E%EC%96%B4%EC%93%B8-%EB%95%8C-%EC%A3%BC%EC%9D%98%EC%A0%90)
- [getline을 이용해 입력받을 때 cin.ignore()로 버퍼 비우기](https://infjin.tistory.com/143)
- [string](http://www.cplusplus.com/reference/string/string/)
- [string Microsoft](https://learn.microsoft.com/ko-kr/cpp/standard-library/string?view=msvc-170)
- [iomanip](http://www.cplusplus.com/reference/iomanip/)
- [iomanip Microsoft](https://learn.microsoft.com/ko-kr/cpp/standard-library/iomanip?view=msvc-170)

## ex02

```
This function and the related types were deprecated in C++11 and removed in C++17 in favor of the more general
std::mem_fn and std::bind, both of which create callable adaptor-compatible function objects from member functions.
```

[mem_fun_ref](http://www.cplusplus.com/reference/functional/mem_fun_ref/)
