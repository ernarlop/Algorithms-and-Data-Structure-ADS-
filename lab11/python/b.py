n = int(input())
d = list(map(int, input().split()))

# Prim's algorithm on the full graph: bridge i-j costs d[i] + d[j]
INF = float("inf")
used = [False] * n
best = [INF] * n  # the cheapest bridge from the built part to island i
best[0] = 0
total = 0
for _ in range(n):
    u = -1
    for i in range(n):
        if not used[i] and (u == -1 or best[i] < best[u]):
            u = i
    used[u] = True
    total += best[u]
    for v in range(n):
        if not used[v] and d[u] + d[v] < best[v]:
            best[v] = d[u] + d[v]
print(total)
