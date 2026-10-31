import sys
from collections import deque
input = sys.stdin.readline

n, m, q = map(int, input().split())
adj = [[] for _ in range(n + 1)]
for _ in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

INF = float("inf")
dist = [INF] * (n + 1)  # dist[v] = distance from v to the nearest red vertex

out = []
for _ in range(q):
    t, v = map(int, input().split())
    if t == 1:
        if dist[v] == 0:
            continue
        # BFS from the new red vertex, but only where it makes the distance smaller
        dist[v] = 0
        dq = deque([v])
        while dq:
            u = dq.popleft()
            for w in adj[u]:
                if dist[u] + 1 < dist[w]:
                    dist[w] = dist[u] + 1
                    dq.append(w)
    else:
        out.append(dist[v] if dist[v] != INF else -1)
print("\n".join(map(str, out)))
