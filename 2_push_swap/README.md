# push_swap

## Solution

deque 자료구조, greedy algorithm을 이용하여 구현

## Bonus

gnl을 이용하여 checker 구현

./checker_Mac -d -> 시각화

./push_swap 1 2 3 4 -
./push_swap "-"
./push_swap "-one"
./push_swap " 1 one  2 3  4 "
./push_swap 1 "  2 3  4 " 1
./push_swap 2 +3  4- " "
./push_swap 2147483648 +3  4- " "
./push_swap +2147483648 +3  4- " "
./push_swap +2147483648 "++3"  4- " "
./push_swap "++3" 4- " "
./push_swap -2147483649 " "
./push_swap " "
./push_swap "" 33

./checker 1 2 3 4 5 6 7 8 9 10
