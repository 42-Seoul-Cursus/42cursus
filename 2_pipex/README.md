# pipex

![](./img/pipex.png)

```zsh
> ls a
ls: a: No such file or directory
```

ls또한 에러 메세지 앞에 프로그램의 이름을 띄우기 때문에 pipex: [file]: errmsg 형식으로 에러메세지 만들것

---
`< infile cmd1 | cmd2 > outfile`

file이 올바르지 않은 것
- bash: [file]: Permission denied (권한이 없을 때)
- bash: [file]: No such file or directory (파일이 존재하지 않을 때)

cmd가 올바르지 않은 것
- bash: [cmd]: command not found
- 만약 파일이 안열리면 (infile의 경우에만) 오류메세지 없음 -> open err 시 exit
---

## [pipe](https://tldp.org/LDP/lpg/node11.html)
err
- Too many open files
## [fork](https://codetravel.tistory.com/23)
err
- Resource temporarily unavailable

## open
err
- bash: [file]: Permission denied -> 권한이 없는 경우
- bash: [file]: No such file or directory -> 파일이 없는 경우

## close
err
- Bad file descriptor

## [execve](https://badayak.com/entry/C%EC%96%B8%EC%96%B4-%EB%8B%A4%EB%A5%B8-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8-%EC%8B%A4%ED%96%89-%ED%95%A8%EC%88%98execve)
execve: No such file or directory

## [wait](https://codetravel.tistory.com/42)

## [waitpid](https://codetravel.tistory.com/42)

## [dup](https://reakwon.tistory.com/104)

## [dup2](https://reakwon.tistory.com/104)

## [unlink](https://www.it-note.kr/177)

## [access](https://jdm.kr/blog/76)

## [perror](https://modoocode.com/53)

## [strerror](https://modoocode.com/105)

https://www.youtube.com/results?search_query=execve
https://www.it-note.kr/157
https://nomad-programmer.tistory.com/110

echo $PATH
