## make

- `find . -type d -name "ex*" | xargs -I {} make -C {}`
- `find . -type d -name "ex*" -exec make -C {} \;`

## ex02

### File open error handling

#### is_open()
- is_open() 메소드는 파일 스트림(fstream, ifstream, ofstream 등)이 현재 파일과 연결되어 있는지 확인
- 주로 파일을 열기 시도 후, 파일이 성공적으로 열렸는지 여부를 확인할 때 사용

```cpp
#include <iostream>

int main()
{
    std::ifstream writeFile("a.txt");

    if (!writeFile.is_open())
    {
        std::cerr << "File open error\n";
        return 1;
    }

    std::cout << "File open success\n";
    return 0;
}
```

#### fail()

- fail() 메소드는 최근 수행된 스트림 연산이 실패했는지 여부를 확인
- 최근 연산이 실패하거나 스트림이 "bad" 상태에 있으면 true를, 그렇지 않으면 false를 반환
- 파일 입출력 연산 후 그 연산이 성공적으로 수행되었는지 여부를 넓은 범위에서 확인하고자 할 때 사용

```cpp

#include <iostream>

int main()
{
    std::ifstream writeFile("a.txt");

    if (writeFile.fail())
    {
        std::cerr << "File open error\n";
        return 1;
    }

    std::cout << "File open success\n";
    return 0;
}
```


#### good()

- good() 메소드는 스트림 상태가 좋은(good) 상태인지, 즉 지금까지 수행된 입출력 연산들이 모두 성공적이었고, 스트림이 EOF(파일 끝)에 도달하지 않았으며, 오류 플래그가 설정되지 않았는지를 확인
- 스트림이 정상적으로 작동하고 있고, 아직 입출력 작업을 계속 진행할 수 있는 상태인지 전반적으로 확인하고 싶을 때 사용

```cpp
#include <iostream>

int main()
{
    std::ifstream writeFile("a.txt");

    if (!writeFile.good())
    {
        std::cerr << "File open error\n";
        return 1;
    }

    std::cout << "File open success\n";
    return 0;
}
``` 


