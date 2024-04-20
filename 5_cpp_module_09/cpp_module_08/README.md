# ex01

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
