import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
adj = [[] for _ in range(n + 1)]
for _ in range(m):
    x, y = map(int, input().split())
    adj[x].append(y)
    adj[y].append(x)
s, f = map(int, input().split())

# BFS from s: f is in the same component if BFS reaches it
visited = [False] * (n + 1)
visited[s] = True
q = deque([s])
while q:
    u = q.popleft()
    for v in adj[u]:
        if not visited[v]:
            visited[v] = True
            q.append(v)
print("YES" if visited[f] else "NO")
