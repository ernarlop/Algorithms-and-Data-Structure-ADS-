import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
adj = [[] for _ in range(n + 1)]
for _ in range(m):
    x, y = map(int, input().split())
    adj[x].append(y)
    adj[y].append(x)

visited = [False] * (n + 1)
parent = [0] * (n + 1)
children = [0] * (n + 1)
is_root = [False] * (n + 1)

for r in range(1, n + 1):
    if visited[r]:
        continue
    # we go from 1 to n, so r is the smallest vertex of its component -> the root
    is_root[r] = True
    visited[r] = True
    q = deque([r])
    while q:
        u = q.popleft()
        for v in adj[u]:
            if not visited[v]:
                visited[v] = True
                parent[v] = u
                children[u] += 1
                q.append(v)

count = 0
for v in range(1, n + 1):
    if is_root[v] or children[v] > children[parent[v]]:
        count += 1
print(count)
