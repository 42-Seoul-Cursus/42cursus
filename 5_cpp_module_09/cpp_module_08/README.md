## ex01

[Standard library header <cstddef> - cppreference.com](https://en.cppreference.com/w/cpp/header/cstddef)
cpp에서는 `#include <cstddef>`가 `#include <stddef.h>`를 포함하고 있기 때문에 `#include <cstddef>` 헤더를 사용하는 것이 좋다. 

```cpp
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dis(1, 100);
```

cpp11 버전에서는 [Mersenne Twister](https://en.wikipedia.org/wiki/Mersenne_Twister)을 이용한 난수 생성기를 사용할 수 있지만 cpp98 버전에서는 `rand()` 함수를 사용해야 한다. 

```cpp
std::srand(std::time(NULL));

int random = std::rand() % 100 + 1;
```

## ex02

### Type of Container
| Type of Container | Description | Example |
|:---------:|:-----------:|:-------:|
| Sequence Container | 데이터를 선형으로 저장하며, 특별한 제약이나 규칙이 없는 가장 일반적인 컨테이너 | vector, list, deque |
| Associative Container | 데이터를 일정 규칙에 따라 조직화하여 저장하고 관리하는 컨테이너 | set, map, multiset, multimap |
| Adapter Container | 간결함과 명료성을 위해 인터페이스를 제한한 시퀀스나 연관 컨테이너의 변형 반복자를 지원하지 않으므로 STL 알고리즘에서는 사용할 수 없음 | stack, queue, priority_queue |

- [컨테이터 종류, TCP School](https://www.tcpschool.com/cpp/cpp_container_intro)
- [[C++] STL 컨테이너 클래스 정리 & 종류 - 하루 공부 기록](https://yj59.github.io/cppstl/container-class/)

### Stack

```cpp
template <class _Tp, class _Container /*= deque<_Tp>*/>
class _LIBCPP_TEMPLATE_VIS stack
{
public:
    typedef _Container                               container_type;
    typedef typename container_type::value_type      value_type;
    typedef typename container_type::reference       reference;
    typedef typename container_type::const_reference const_reference;
    typedef typename container_type::size_type       size_type;
    static_assert((is_same<_Tp, value_type>::value), "" );

protected:
    container_type c;
    ...
}
```
