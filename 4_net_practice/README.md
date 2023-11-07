# Netpractice

## When a packet arrives at the router

1. Check the destination IP address
2. Check the interface
3. Check the routing table

Destination IP => NEXT HOP

## Things that I was confused about

- host address의 모든 bit가 0이면 network address, 1이면 broadcast address
- 127.0.0.0/8은 loopback address band
- 10.0.0.0/8은 private address band (NAT)

## Tip

```bash
bc # 계산기
obase=2; # Output base
ibase=2; # Input base
```

서브넷을 쪼개는 연습을 했던 과제
