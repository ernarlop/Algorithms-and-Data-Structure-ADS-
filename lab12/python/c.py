import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
air = [[False] * (n + 1) for _ in range(n + 1)]
for _ in range(m):
    u, v = map(int, input().split())
    air[u][v] = air[v][u] = True

# the pair (1, n) is either an airline or a road, so one of them gets there in 1 hour;
# the answer is the shortest time of the other one (they never meet on the way)
use_air = not air[1][n]

dist = [-1] * (n + 1)
dist[1] = 0
q = deque([1])
while q:
    u = q.popleft()
    for v in range(1, n + 1):
        if v != u and air[u][v] == use_air and dist[v] == -1:
            dist[v] = dist[u] + 1
            q.append(v)
print(dist[n])
