# Minitalk

## Allowed functions
- signal
- sigemptyset
- sigaddset
- sigaction
- kill
- getpid
- pause
- sleep
- usleep

## Mandatory

SIGUSR1 = 0
SIGUSR2 = 1

## Bonus

C 언어에서 시그널을 처리하는 시그널 핸들러 함수에서 시그널을 보낸 프로세스의 PID를 알기 위해서는 `siginfo_t` 구조체를 사용해야 합니다. 시그널 핸들러 함수는 시그널을 받을 때 이 구조체의 정보를 제공합니다.

시그널 핸들러 함수에서 `siginfo_t` 구조체를 이용하여 시그널을 보낸 프로세스의 PID를 얻으려면 다음과 같이 코드를 작성할 수 있습니다:

```c
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

void sigHandler(int signo, siginfo_t *info, void *context) {
    if (signo == SIGUSR1) {
        pid_t sender_pid = info->si_pid;
        printf("시그널을 보낸 프로세스의 PID: %d\n", sender_pid);
    }
}

int main() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = sigHandler;

    if (sigaction(SIGUSR1, &sa, NULL) != 0) {
        perror("시그널 핸들러 설정 실패");
        return 1;
    }

    // SIGUSR1 시그널을 보내는 예제
    pid_t my_pid = getpid();
    printf("현재 프로세스의 PID: %d\n", my_pid);

    // 다른 프로세스에서 SIGUSR1 시그널을 보내면 sigHandler가 호출됩니다.

    while (1) {
        // 무한 루프에서 대기
    }

    return 0;
}
```

위의 코드에서 `sigaction()` 함수를 사용하여 SIGUSR1 시그널에 대한 핸들러 함수 `sigHandler`를 등록하고, `siginfo_t` 구조체의 `si_pid` 멤버를 통해 시그널을 보낸 프로세스의 PID를 얻습니다.
