## Problem

특정 상황 (아래 참고)에서 서버가 클라이언트로부터 시그널을 제대로 처리하지 못하여 문자를 제대로 받지 못하는 문제가 발생한다.

## Reasons for the problem

1. 진행되던 흐름에서 인터럽트가 늦어져서 signal handler 함수보다 if (g_ack_received) 문에 먼저 도달하여 g_ack_received가 0이 되어버림
	```c
	void	send_bit(pid_t pid, unsigned char bit)
	{
		g_ack_received = 0;
		while (1)
		{
			if (bit == 1)
				kill(pid, SIGUSR1);
			else if (bit == 0)
				kill(pid, SIGUSR2);
			int a = usleep(TIMEOUT);
			if (a == -1) // signal interrupt
					printf("%d", g_ack_received);
			else
				printf("time out!\n");
			if (g_ack_received)
				return ;
		}
	}
	// a == -1일 때(signal interrupt) g_ack_received가 1로 나오기 때문에 이 가정은 절대로 아님
	```
2. 코어를 병렬적으로 처리하다보니 if (g_ack_received) 문과 signal handler 함수가 동시에 실행되어 g_ack_received가 0이 되어버림
	- 절대 아님 => 활성 상태 보기에서 1 thread로 나오고 있고 서버 프로세스에 많은 부하를 줘도 CPU 사용률이 (100 / 코어수)%를 안넘어감
3. 서버가 보내는 ACK 유실 혹은 안보냄(pid가 0이라) => pid가 0일 때

## Solution

1. ~~서버 측에서 pid를 백업해두었다가 pid가 0으로 식별되면 백업한 pid로 kill 사용 (kill로 모든 프로세스에게 시그널을 브로드캐스트 하는 방법은 불가능했다.)~~
2. 클라이언트 측에서 usleep(TIMEOUT) 이후 usleep(100)을 줌 => 이유는 kil 아래의 Conclusion 참고

1번 방법도 터진다.. 2번 방법으로만 해결된다.

## Conclusion

1. 서버 <- 클라이언트 : 비트에 맞는 시그널을 보냄
2. 서버 -> 클라이언트 : 시그널을 보낸 프로세스의 pid를 찾아 해당 프로세스에 ACK를 보냄 (pid가 0으로 식별 시 백업한 pid로 ACK를 보냄)
3. 서버 <- 클라이언트 : ACK를 받으면 (usleep(100) 이후에) 다음 비트를 보냄

~~`결국 서버 측의 sigaction 구조체에서 받은 시그널에 대한 pid를 식별을 못했던 것이 문제의 핵심 같다.`~~
`결국 kill 함수를 계속해서 사용할 때 서버의 시그널 대기 큐나 클라이언트의 시그널 전송대기 큐 오버플로우가 일어나서 시그널이 손실되는 것 같다.`
