## Error

1. signal handler 함수가 인터럽트가 늦어져서 g_ack_received가 안바뀌거나 data race가 일어남
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
			sleep(500);
			//usleep(TIMEOUT);
			return ;
			// if (a == -1)
			// {
			// 	if (!g_ack_received)
			// 		ft_printf("%d", g_ack_received);
			// }
			// else
			// 	ft_printf("time out!\n");
			// if (g_ack_received)
			// 	return ;
		}
	}
	// 절대 아님
	```
2. 병렬적 코어 처리됨
	- 절대 아님 => 활성 상태 보기에서 1 thread로 나옴
3. 서버가 보내는 ACK 유실 혹은 안보냄(pid가 0이라) => pid가 0일 때

## Solution

1. 서버 측에서 pid를 백업해두었다가 pid가 0으로 식별되면 백업한 pid로 kill 사용 (kill로 모든 프로세스에게 시그널을 브로드캐스트 하는 방법은 불가능했다.)
2. 클라이언트 측에서 usleep(TIMEOUT) 이후 usleep(100)을 줌

## Conclusion

1. 서버 <- 클라이언트 : 비트에 맞는 시그널을 보냄
2. 서버 -> 클라이언트 : 시그널을 보낸 프로세스의 pid를 찾아 해당 프로세스에 ACK를 보냄 (pid가 0으로 식별 시 백업한 pid로 ACK를 보냄)
3. 서버 <- 클라이언트 : ACK를 받으면 (usleep(100) 이후에) 다음 비트를 보냄

`결국 서버 측의 sigaction 구조체에서 받은 시그널에 대한 pid를 식별을 못했던 것이 문제의 핵심 같다.`
