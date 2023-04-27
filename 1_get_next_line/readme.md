# char *get_next_line(int fd);

```c
	char	*get_next_line(int fd)
```

1. 매개변수로 들어온 fd에 해당하는 리스트를 탐색한다.
	1. 없다면 마지막 노드에 fd가 매개변수, next가 0인 리스트를 새로 만들어준다.
2. fd의 값이 매개변수 fd와 일치하는 리스트의 백업에 개행문자가 있는 지 확인한다.
	1. 있다면 개행문자 후의 문자열을 백업에 저장하고 개행문자 전의 문자열을 반환한다. (없다면 3으로 간다.)
3. 백업의 문자열과 read로 받은 버퍼의 문자열을 합치고 2로 돌아간다. (만약 read의 반환값이 음수이거나 BUFFER_SIZE보다 작다면 반환한다.)

read의 반환값이 음수라면 실패, BUFFER_SIZE보다 작은 음이 아닌 정수의 경우 파일을 다 읽은 것!

OPEN_MAX -> ulimit -a
### 참고자료
* [gnl 준비: 기본 개념](https://velog.io/@pig005/gnl-%EC%A4%80%EB%B9%84-%EA%B8%B0%EB%B3%B8-%EA%B0%9C%EB%85%90)
