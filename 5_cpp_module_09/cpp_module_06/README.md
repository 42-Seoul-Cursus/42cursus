## ex00

### istringstream
`istringstream`은 C++ 표준 라이브러리에서 제공하는 입력 스트림 클래스의 하나로, `std::istringstream`은 `std::istream`에서 파생된 클래스입니다.
이 클래스는 문자열로부터 입력을 읽어들이기 위해 사용됩니다. 
즉, `istringstream` 객체는 메모리 상의 문자열에 대한 입력 스트림을 제공하여, 문자열 내용을 마치 표준 입력(stdin)이나 파일 입력처럼 다룰 수 있게 해줍니다.

### 기본 사용 방법

`std::istringstream`을 사용하려면 `<sstream>` 헤더를 포함해야 합니다.
기본적으로, `istringstream` 객체는 생성 시점에 문자열을 받아들여, 그 문자열로부터 순차적으로 데이터를 읽어들일 수 있습니다.
데이터는 공백 문자로 구분되며, `>>` 연산자를 통해 읽을 수 있습니다. 

### 예제

```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string data = "123 45.67 Hello, World!";
    std::istringstream iss(data);

    int intValue;
    double doubleValue;
    std::string stringValue;

    iss >> intValue; // 123
    iss >> doubleValue; // 45.67
    iss >> stringValue; // Hello,

    std::string remainder;
    getline(iss, remainder); // 나머지 전체 문자열을 읽어들임: " World!"

    std::cout << intValue << std::endl;
    std::cout << doubleValue << std::endl;
    std::cout << stringValue << std::endl;
    std::cout << remainder << std::endl;

    return 0;
}
```

이 예제에서는 `std::istringstream`을 사용하여 문자열 `data`에서 정수, 부동 소수점 숫자, 그리고 문자열을 순차적으로 읽어들입니다.
이후, `std::getline` 함수를 사용해 남은 문자열 전체를 읽어들입니다.

### 주요 사용 사례

- **문자열 파싱**: 공백이나 다른 구분자로 구분된 데이터가 포함된 문자열에서 개별 값을 추출할 때 유용합니다.
- **데이터 변환**: 문자열 형태의 데이터를 다른 타입, 예를 들어 정수나 부동 소수점 수로 변환할 때 사용할 수 있습니다.
- **테스트 코드 작성**: 실제 파일이나 표준 입력 대신 문자열 데이터를 사용하여 입력 처리 코드를 테스트할 때 유용합니다.

`std::istringstream`은 C++에서 문자열 기반 데이터를 쉽고 효율적으로 다루기 위한 강력한 도구 중 하나입니다.

## ex01

### reinterpret_cast
`reinterpret_cast`는 C++의 타입 캐스팅 연산자 중 하나로, 한 포인터 타입을 다른 포인터 타입으로, 또는 포인터 타입을 충분히 큰 정수 타입으로, 그 반대의 경우로 변환할 때 사용됩니다. 
`reinterpret_cast`는 컴파일 시간에 타입 체크를 거의 수행하지 않으므로, 사용자가 타입 안전성을 보장해야 합니다.
이 연산자는 비트 단위로 변환을 수행하기 때문에, 결과는 사용자의 해석에 따라 달라질 수 있습니다.

### 사용법

```cpp
reinterpret_cast<new_type>(expression)
```

- `new_type`: 변환하고자 하는 타입입니다.
- `expression`: 변환될 값입니다.

### 사용 예시

```cpp
#include <iostream>

int main() {
    int* a = new int(10);
    char* b = reinterpret_cast<char*>(a);

    // 이제 b는 a의 메모리 주소를 가리키지만, char* 타입으로 취급됩니다.
    std::cout << *b << std::endl; // 출력값은 환경에 따라 달라집니다.

    return 0;
}
```

### 주의사항
- `reinterpret_cast`는 포인터의 실제 타입을 변경하지 않고, 단순히 컴파일러에게 해당 포인터를 다른 타입으로 해석하도록 지시합니다. 실제 메모리의 내용이나 구조는 변하지 않습니다.
- 결과적으로, `reinterpret_cast`의 사용은 매우 주의해야 합니다. 변환된 포인터를 통해 데이터에 접근할 때, 잘못된 해석으로 인해 데이터 손상이나 정의되지 않은 동작을 유발할 수 있습니다.
- 특히, 다른 타입으로 변환된 포인터를 통해 객체에 접근하려 할 때, 그 객체의 실제 타입과 접근하려는 타입이 일치하지 않는다면, 정의되지 않은 행동(undefined behavior)을 초래할 수 있습니다.
- `reinterpret_cast`는 포인터와 정수 타입 간의 변환에도 사용될 수 있지만, 이 경우 포인터의 크기와 정수 타입의 크기가 동일한지 주의 깊게 확인해야 합니다.

`reinterpret_cast`의 사용은 필요한 경우가 아니라면 피하는 것이 좋으며, 사용 시에는 타입 안전성과 메모리 안전성을 신중히 고려해야 합니다.

## ex02

### Cascading Dynamic cast

### Dynamic cast
다이나믹 캐스트(dynamic_cast)에서 예외가 발생하는 경우는 주로 다운캐스팅(downcasting)을 수행할 때 발생합니다. 
다운캐스팅은 기본 클래스의 포인터나 참조를 파생 클래스의 포인터나 참조로 변환하는 과정을 말합니다. 
`dynamic_cast`는 런타임에 객체의 타입을 확인하여 안전한 타입 변환을 지원합니다. 
그러나 이 과정에서 몇 가지 조건을 만족하지 않으면 예외적인 상황이 발생할 수 있습니다.

### 포인터를 사용하는 경우
- `dynamic_cast`가 실패하면 `nullptr`을 반환합니다. 
- 이는 예외를 던지는 것은 아니지만, 예외적인 상황을 나타냅니다. 
- 즉, 변환을 시도하는 타입이 실제 객체의 타입과 호환되지 않을 때 발생합니다.

### 참조를 사용하는 경우

- `dynamic_cast`를 참조에 사용했을 때 변환이 실패하면, `std::bad_cast` 예외를 던집니다. 
- 이는 포인터를 사용했을 때와 다르게, 참조의 변환이 실패할 경우 `nullptr`을 반환할 수 없기 때문에 예외를 통해 실패를 알립니다.

### 실패하는 상황

`dynamic_cast`가 실패하는 주요한 상황은 다음과 같습니다.

1. **타입 호환성**: 변환하려는 대상 클래스가 실제 객체의 타입 계층에 속하지 않는 경우.
2. **다형성**: `dynamic_cast`는 다형성을 가진 클래스에만 사용할 수 있습니다. 이는 대상 클래스에 가상 함수가 최소 한 개 이상 있어야 함을 의미합니다. 만약 가상 함수가 없는 클래스에 `dynamic_cast`를 사용하려고 하면, 컴파일 시간에 에러가 발생합니다.
3. **가상 상속**: 복잡한 상속 구조에서 가상 상속이 사용되지 않은 경우, 예상치 못한 방식으로 `dynamic_cast`가 실패할 수 있습니다.

`dynamic_cast`의 이러한 특성을 이해하는 것은 객체 지향 프로그래밍, 특히 C++에서 안전한 타입 변환을 구현하는 데 중요합니다. 실패 가능성을 항상 염두에 두고, `nullptr` 체크나 예외 처리를 적절히 수행해야 합니다.
