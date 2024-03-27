# Microshell

## Logic
1. ~~`;`를 기준으로 command의 개수를 세고 반복문을 통해 command를 실행한다.~~ av의 index가 ac - 1 과 같아질 때까지(마지막 배열에 도착할 때까지) 반복문을 통해 command를 실행한다.
2. pipe의 개수를 센다.
   - pipe가 있다면 파이프를 만드는 로직에 진입한다.
   - pipe가 없다면 command를 실행한다.
3. 모든 실행이 끝나면 wait을 통해 모든 프로세스가 종료될 때까지 기다린다.

## Multi Pipe
`middle` 함수에 구현되어 있다.
pipe to pipe를 이미 써진 파이프의 fd를 backup해두고 해당 변수에 pipe()를 통해 새로운 파이프를 만든다.

## Test Cases
```bash
ulimit -n 30; ./microshell "/bin/ls" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat" "|" "/bin/cat"
```

```bash
ulimit -n 30; time ./microshell "/bin/ls" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1" "|" "/bin/sleep" "1"
```

```bash
./microshell "/bin/ls" ";" "/bin/ls" ";"
```

```bash
./microshell "/bin/ls" "|" "cd" "|" "/bin/ls"
```

```bash
./microshell "/bin/ls" ";" "cd" ";" "/bin/ls"
```

```bash
./microshell "/bin/ls -l | grep a | wc -l"
```

## Review
dup2와 pipe, 다중 파이프 구현에 대한 복습을 할 수 있는 좋은 기회였다.
