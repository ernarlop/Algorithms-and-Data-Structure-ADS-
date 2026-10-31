from collections import deque

boris = deque(map(int, input().split()))
nursik = deque(map(int, input().split()))

moves = 0
while boris and nursik:
    b = boris.popleft()
    n = nursik.popleft()
    moves += 1

    if b == 0 and n == 9:      # 0 beats 9
        boris_wins = True
    elif b == 9 and n == 0:
        boris_wins = False
    else:
        boris_wins = b > n

    if boris_wins:
        boris.append(b)
        boris.append(n)
    else:
        nursik.append(b)
        nursik.append(n)

if not nursik:
    print("Boris", moves)
else:
    print("Nursik", moves)
