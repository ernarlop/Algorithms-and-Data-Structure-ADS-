from collections import deque

t = int(input())
for _ in range(t):
    n = int(input())

    # repeat the trick with positions 0..n-1 instead of cards
    q = deque(range(n))
    deck = [0] * n
    for card in range(1, n + 1):
        q.rotate(-(card % len(q)))  # move card % size cards from the top to the bottom
        deck[q.popleft()] = card    # this position must hold card number "card"
    print(*deck)
