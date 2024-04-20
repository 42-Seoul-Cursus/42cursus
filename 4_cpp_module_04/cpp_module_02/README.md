## ex02

```cpp
int a = 0;
(a++)++; // Error: lvalue required as increment operand
```

### Lvalue Rvalve

```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x = 3; // 3 is an rvalue
    const int y = x;
    int z = x + y; // (x + y) is an rvalue
    int *p = &x; // &x is an lvalue

    cout << string("one"); // string("one") is an rvalue

    ++x;
    x++; // x is an lvalue

    &(++x);
    &(x++); // Error: '&' requires lvalue
    return 0;
}
```

- Lvalue: 단일 표현식 이후에도 없어지지 않고 지속되는 객체, const 타입을 포함한 모든 변수는 lvalue
- Rvalue: 표현식이 종료된 이후에는 더이상 존재하지 않는 임시적인 값

`++a`는 lvalue이지만 `a++`는 rvalue이다. `a++`는 `a`를 증가시키고 복사본을 반환하기 때문이다.

lvalue와 rvalue의 가장 간단한 구분 방법은 & 연산자를 사용해보는 것이다. & 연산자는 lvalue만을 피연산자로 받는다.

[lvalue와 rvalue](https://effort4137.tistory.com/entry/Lvalue-Rvalue)

### Implementing increment and decrement operators

```cpp
// prefix
const Fixed& Fixed::operator++()
{
    ++mRawBits;
    return *this;
}
// postfix
const Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++(this->mRawBits);
    return tmp;
}
```

전위 연산과 후위 연산 오버로딩을 구현할 때, 전위 연산은 참조를 반환하고 후위 연산은 복사본을 반환한다.

이때 후위 연산 오버로딩 함수의 반환 타입은 Fixed가 아닌 const Fixed로 선언해야 한다. 그렇지 않으면 `a++ = 42`, `(a++)++`와 같은 코드가 가능해진다.

### Overloading and Overriding
- Overloading: 같은 이름의 함수지만 다른 시그니처(매개변수의 타입, 개수)를 가지는 함수를 여러 개 정의하는 것
- Overriding: 상속 관계에서 부모 클래스의 함수를 자식 클래스에서 재정의하는 것, 이미 정의된 함수를 무시하고 같은 이름의 함수를 새롭게 정의하는 것

[Overriding | TCP](https://www.tcpschool.com/cpp/cpp_inheritance_overriding)
[overloading vs overriding](https://brunch.co.kr/@kimkm4726/2)
