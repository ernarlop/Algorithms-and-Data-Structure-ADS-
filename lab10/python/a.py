import sys
from collections import deque
input = sys.stdin.readline

m, n = map(int, input().split())
g = [list(map(int, input().split())) for _ in range(m)]

# BFS from all Marios at once: one BFS level = one minute
q = deque()
mushrooms = 0
for i in range(m):
    for j in range(n):
        if g[i][j] == 2:
            q.append((i, j, 0))
        elif g[i][j] == 1:
            mushrooms += 1

time = 0
while q:
    i, j, t = q.popleft()
    time = t
    for x, y in ((i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)):
        if 0 <= x < m and 0 <= y < n and g[x][y] == 1:
            g[x][y] = 2  # the mushroom becomes a Mario
            mushrooms -= 1
            q.append((x, y, t + 1))

print(time if mushrooms == 0 else -1)
