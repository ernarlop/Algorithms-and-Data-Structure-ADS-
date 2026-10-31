from collections import deque

n = int(input())
g = [list(map(int, input().split())) for _ in range(n)]
s, f = map(int, input().split())
s -= 1
f -= 1

# BFS on the adjacency matrix
dist = [-1] * n
dist[s] = 0
q = deque([s])
while q:
    u = q.popleft()
    for v in range(n):
        if g[u][v] == 1 and dist[v] == -1:
            dist[v] = dist[u] + 1
            q.append(v)
print(dist[f])
