import sys
from collections import deque
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    letters = input().split()
    cnt = {}
    q = deque()  # letters that may still be unique, in the order they came
    ans = []
    for c in letters:
        cnt[c] = cnt.get(c, 0) + 1
        q.append(c)
        # letters at the front that repeated are never the answer again
        while q and cnt[q[0]] > 1:
            q.popleft()
        ans.append(q[0] if q else "-1")
    print(" ".join(ans))
