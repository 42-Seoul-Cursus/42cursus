# cpp_module_04

## CppCodingConvention

1. 클래스와 구조체의 이름은 파스칼 표기법을 사용합니다.
	```cpp
	class ClassName
	{
			// ...
	};
	struct StructName
	{
			// ...
	};
	```
2. 지역 변수와 함수의 매개 변수의 이름은 카멜 표기법을 따른다.
	```cpp
	void FunctionName(int myParameter)
	{
			int myLocalVariable;
			// ...
	}
	```
3. 메소드 이름은 동사-목적어 쌍으로 표기한다.
	1. public 메소드는 파스칼 표기법을 사용한다.
		```cpp
		public:
			void ClassName::PublicFunctionName()
			{
					// ...
			}
		```
	2. 그 외 다른 메소드는 카멜 표기법을 사용한다.
		```cpp
		private:
			void ClassName::otherFunctionName()
			{
					// ...
			}
		```
4. 상수 또는 `#define` 으로 정의된 상수의 이름은 모두 대문자로 하되 단어 사이에 `_` 를 넣는다.
	```cpp
	// #define 으로 정의된 상수는 항상 괄호로 감싸준다.
	#define MY_CONSTANT (42)
	// 상수는 웬만하면 const 상수 변수로 선언한다.
	const int MY_OTHER_CONSTANT = 21;
	```
5. namespace는 모두 소문자로 한다.
	```cpp
	namespace abc{}'
	```
6. boolean 변수는 앞에 'b'를 붙인다.
	```cpp
	bool bFired; // 지역 변수와 public 멤버 변수
	bool mbFired; // 클래스의 private 멤버 변수
	```
7. 인터페이스를 선언할 때는 `I`를 접두어로 붙인다.
	```cpp
	class IMyInterface
	{
		public:
			virtual void MyMethod() = 0;
	};
	```
8. 열거형을 선언할 때는 `e`를 접두어로 붙인다.
	```cpp
	enum eDirection
	{
		NORTH,
		SOUTH,
		//...
	};
	```
9. 클래스 멤버 변수명은 앞에 `m`을 붙인다.
	```cpp
	class MyClass
	{
		protected:
			int mMyProtectedVariable;
		private:
			int mMyPrivateVariable;
	};
	```
10. `goto` 레이블 명은 모두 대문자로 하되 밑줄로 각 단어를 분리한다.
	```cpp

	goto MY_LABEL;

	// ....

	MY_LABEL:
		std::cout << "Hello World!" << std::endl;
		return 0;
	```
11. 값을 반환하는 함수의 이름은 무엇을 반환하는지 알 수 있도록 한다.
	```cpp
	uint32_t GetWidth() const;
	```
12. 단순히 반복문에 사용되는 변수가 아닌 경우엔 `i`, `e` 같은 변수명 대신 `index`, `element` 처럼 변수에 저장되는데이터를 한 눈에 알아볼 수 있는 변수명을 사용한다.
13. 뒤에 추가적인 단어가 오지 않는 경우 줄임말은 모두 대문자로 표기한다.
	```cpp
	int OrderID;
	int HttpURL;
	```
14. 클래스 멤버 변수에 접근할 때는 항상 setter와 getter를 사용한다.
	```cpp
	// 틀린 방식
	class MyClass
	{
		public:
			int mMyVariable;
	};

	// 올바른 방식
	class MyClass
	{
		public:
			int GetMyVariable() const;
			void SetMyVariable(int value);
		private:
			int mMyVariable;
	};
	```
15. 구조체는 오직 public 멤버 변수만 가질 수 있다. 구조체의 멤버 변수명은 파스칼 표기법을 따르며, 구조체 안에서 함수는 사용하지 않는다.
	```cpp
	struct MyStruct
	{
		int MyVariable;
	};
	```
16. 외부 헤더 파일을 먼저 인클루드한 뒤, 내부 헤더 파일을 인클루드 한다. 가능하다면 알파벳 순서를 따른단.
```cpp
#include <iostream>
#include <string>

#include "MyHeader.h"
```
17. 모든 헤더 파일 첫 번째 줄에 `#pragma once` 를 넣는다. (42에서는 중복 헤더 컴파일을 막기위해 ifndef를 사용한다. [둘의 차이점](https://secretroute.tistory.com/entry/1408251741))
18. 지역 변수를 선언할 때는 그 지역 변수를 사용하는 코드와 동일한 줄에 선언하는 것을 원칙으로 한다.
19. switch case 문에는 항상 `default:` 를 넣는다.
	```cpp
	switch (number)
	{
		case 1:
			...
			break;
		default:
			break;
	}
	```
20. 원칙적으로 모든 곳에 `const`를 사용한다. 여기에는 지역 변수. 함수 매개 변수도 포함된다.
21. 개체를 수정하지 않는 멤버 함수에는 모두 `const`를 붙인다.
	```cpp
	int MyClass::GetAnything() const;
	```
22. 재귀 함수는 이름 뒤에 `Recursive`를 붙인다.
	```cpp
	void FibonacciRecursive();
	```
23. 클래스 안에서의 멤버 변수와 메소드의 등장 순서는 다음을 따른다.
	1. friend Classes
	2. public Methods
	3. protected Methods
	4. private Methods
	5. protected Variables
	6. private Variables
24. 대부분의 경우 함수 오버로딩을 피한다.
	```cpp
	// 틀린 방식:
	const MyClass* GetAnithing(const int index) const;
	const MyClass* GetAnithing(const std::string& name) const;

	// 올바른 방식:
	const MyClass* GetAnithingByIndex(const int index) const;
	const MyClass* GetAnithingByName(const std::string& name) const;
	```
25. `const 반환을 위한` 함수 오버로딩은 허용한다.
	```cpp
	MyClass* GetAnithing(const int index);
	const MyClass* GetAnithing(const int index) const;
	```
26. 클래스는 각각 독립된 소스 파일에 있어야 한다. 단, 작은 클래스 몇 개를 한 파일 안에 같이 넣어두는 것이 상식적일 때 예외를 허용한다.
27. 파일 이름은 대소문자까지 포함하여 반드시 클래스 이름과 일치해야 한다.
	```cpp
	class MyClass
	{
		// ...
	};

	// MyClass.cpp
	// MyClass.h
	```cpp
28. 모든 컴파일러 경고는 반드시 고친다.
29. 한 줄에 변수 하나만 선언한다.
	```cpp
	// 틀린 방식:
	int a, b;

	// 올바른 방식:
	int a;
	int b;
	```
30. 멤버 변수를 초기화할 때는 초기화 리스트를 사용하는 것을 기본으로 한다.

## Formatting

1. include 전처리문 블록과 코드 본문 사에이는 반드시 빈 줄이 있어야 한다.
2. 중괄호를 열 때는 반드시 새 줄을 만들고 한 줄만 있더라도 반드시 중괄호를 사용한다.
	```cpp
	if (bSomething)
	{
		return;
	}
	```
3. 포인터나 참조 연산자는 변수 이름에 붙여서 쓴다.
	```cpp
	int* pMyPointer;
	int& rMyReference;
	```
4. 초기화 리스트를 이용하여 멤버 변수를 초기화할 때는 아래와 같은 포멧을 따라 한 줄에 변수 하나씩 초기화한다.
	```cpp
	// 틀린 방식:
	 MyClass::MyClass(const int var1, const int var2)
   :mVar1(var1), mVar2(var2), mVar3(0)

	// 올바른 방식:
	MyClass::MyClass(const int var1, const int var2)
   : mVar1(var1)
   , mVar2(var2)
   , mVar3(0)
	```
5. 함수 선언 시에만 자료형과 함수 이름을 구분하기 위해 tab을 사용하고, 나머지 경우에는 모두 공백을 사용한다.(변수, 함수 정의 등등)

> C++은 C 프로그래밍 언어를 확장한 것으로, Bjarne Stroustrup에 의해 만들어진 범용 프로그래밍 언어입니다.
>
> 이 언어는 "C with Classes" 또는 "클래스와 함께 사용하는 C"로도 불립니다. 이 모듈의 목표는 객체 지향 프로그래밍을 소개하는 것이며, C++ 여정의 시작점이 될 것입니다.
>
> 객체 지향 프로그래밍을 학습하려면 여러 언어를 추천할 수 있지만, 우리는 C++을 선택했습니다. 그 이유는 C++이 여러분의 오래된 친구인 C에서 파생되었기 때문입니다.
>
> 이 언어는 복잡한 언어이기 때문에, 간단하게 유지하기 위해 여러분의 코드는 C++98 표준을 준수할 것입니다.
>
> 현대의 C++는 여러 측면에서 크게 다르지만, C++98 표준을 준수하는 것으로 시작합니다. C++ 개발자가 되기 위해서는 42 Common Core 이후로 더 나아가는 것은 여러분에게 달려있습니다.
>
> 이 모듈에서는 단계적으로 새로운 개념을 발견하게 될 것이며, 연습문제는 복잡도가 점차 증가할 것입니다.

# General rules

## 컴파일링

- 코드를 c++로 컴파일하고 -Wall -Wextra -Werror 플래그를 사용하세요.
- 코드는 -std=c++98 플래그를 추가해도 여전히 컴파일되어야 합니다.

## 포매팅 및 명명 규칙

- 연습 디렉토리는 ex00, ex01, ..., exn과 같은 방식으로 명명될 것입니다.
- 파일, 클래스, 함수, 멤버 함수 및 속성은 지침에 따라 명명하세요.
- 클래스 이름은 UpperCamelCase 형식으로 작성하세요. 클래스 코드를 포함하는 파일은 항상 클래스 이름에 따라 명명됩니다. 예를 들어, "BrickWall"을 나타내는 클래스 "BrickWall"의 정의를 포함하는 헤더 파일의 이름은 BrickWall.hpp가 될 것입니다.
- 특별히 지정되지 않는 한, 모든 출력 메시지는 새 줄 문자로 끝나야 하며 표준 출력에 표시되어야 합니다.

좋은 작별 Norminette! C++ 모듈에서는 코딩 스타일이 강제되지 않습니다. 원하는 스타일을 따를 수 있지만, 동료 평가자가 이해할 수 없는 코드는 점수를 매길 수 없는 코드입니다. 깨끗하고 가독성 좋은 코드를 작성하기 위해 최선을 다하십시오.

## 허용/금지 사항

- 더 이상 C에서 코딩하지 않습니다. C++로 넘어가는 시간입니다!
- 표준 라이브러리에서 거의 모든 것을 사용할 수 있습니다. 따라서 이미 알고 있는 것을 고수하기보다는 가능한 한 C 함수의 C++ 스타일 버전을 사용하는 것이 좋습니다.
- 그러나 다른 외부 라이브러리를 사용할 수 없습니다. C++11 및 파생 형태, 그리고 Boost 라이브러리는 금지됩니다. 또한 printf(), malloc() 및 free()와 같은 함수는 금지됩니다. 이러한 함수를 사용하면 점수가 0점이 됩니다.

주의할 사항:

- 명시적으로 다르게 지정되지 않는 한, using namespace <ns_name> 및 friend 키워드는 금지됩니다. 그렇지 않으면 점수가 -42점이 될 것입니다.
- 모듈 08과 모듈 09에서만 STL을 사용할 수 있습니다. 이것은 컨테이너 (vector/list/map/등) 및 알고리즘 (algorithm 헤더를 포함해야 하는 것)을 사용할 수 없음을 의미합니다. 그 이전에는 이러한 기능을 사용할 수 없습니다. 그렇지 않으면 점수가 -42점이 될 것입니다.

## 디자인 요구 사항

- 메모리 누수는 C++에서도 발생합니다. 메모리를 할당할 때 (new 키워드를 사용하여), 메모리 누수를 피해야 합니다.
- 모듈 02부터 모듈 09까지 클래스는 명시적으로 다르게 지정되지 않는 한 정통 규범적인 형태로 설계되어야 합니다.
- 헤더 파일에 함수 구현을 넣는 경우 (함수 템플릿 제외), 해당 연습에 대한 점수가 0점이 됩니다.
- 각 헤더를 다른 헤더와 독립적으로 사용할 수 있어야 합니다. 따라서 필요한 모든 종속성을 포함해야 합니다. 그러나 이중 포함 문제를 피하기 위해 include 가드를 추가해야 합니다. 그렇지 않으면 점수가 0점이 될 것입니다.

### 그 외

- 필요하다면 (코드를 분할하기 위해) 추가적인 파일을 추가할 수 있습니다. 이러한 과제는 프로그램에서 확인되지 않으므로 필수 파일을 제출하는 한 자유롭게 추가할 수 있습니다.
- 때로는 연습 지침이 간단해 보이지만 예제에서 명시적으로 기술되지 않은 요구 사항을 보여줄 수 있습니다.
- 시작하기 전에 각 모듈을 완전히 읽어보세요. 정말로 그렇게 하세요.

> 많은 클래스를 구현해야 할 것입니다. 이는 지루할 수 있지만, 좋아하는 텍스트 편집기를 스크립트화할 수 있다면 도움이 될 것입니다.

> 연습을 완료하는 데 있어서 일정한 자유가 주어집니다. 그러나 필수 규칙을 따르고 게으르지 마세요. 유용한 정보를 많이 놓치게 될 것입니다! 이론적 개념에 대해 읽어보는 것을 주저하지 마세요.



### What I learned from this subject

- class1 내부의 크기가 8인  class2 배열은 class1 생성 시 class2 생성자 호출이 8번 일어난다.
- cpp의 파일 입출력은 [fstream](https://cplusplus.com/reference/fstream/fstream/)를 사용한다.
