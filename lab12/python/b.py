import sys
import heapq
input = sys.stdin.readline

n, m = map(int, input().split())
adj = [[] for _ in range(n + 1)]
for _ in range(m):
    v, u, c = map(int, input().split())
    adj[v].append((u, c))
    adj[u].append((v, c))
s, a, b, f = map(int, input().split())

INF = float("inf")


def dijkstra(src):
    dist = [INF] * (n + 1)
    dist[src] = 0
    pq = [(0, src)]
    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue
        for v, w in adj[u]:
            if d + w < dist[v]:
                dist[v] = d + w
                heapq.heappush(pq, (dist[v], v))
    return dist


# the roads are two-way, so distances from a and from b are enough
da = dijkstra(a)
db = dijkstra(b)
ans = min(da[s] + da[b] + db[f],   # s -> a -> b -> f
          db[s] + da[b] + da[f])   # s -> b -> a -> f
print(ans if ans != INF else -1)
