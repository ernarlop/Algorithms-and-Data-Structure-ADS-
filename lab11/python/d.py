n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]

# Prim's algorithm: a[i][j] = 0 means the edge already exists (it is free)
INF = float("inf")
used = [False] * n
best = [INF] * n
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
        if not used[v] and a[u][v] < best[v]:
            best[v] = a[u][v]
print(total)
