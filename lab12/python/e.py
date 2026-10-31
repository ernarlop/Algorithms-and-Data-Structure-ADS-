n = int(input())
edges = []
for i in range(n):
    row = list(map(int, input().split()))
    for j in range(n):
        if row[j] != 100000:  # 100000 means "no edge"
            edges.append((i, j, row[j]))

# Bellman-Ford from all vertices at once (every dist starts at 0)
dist = [0] * n
par = [-1] * n
x = -1
for _ in range(n):
    x = -1
    for u, v, w in edges:
        if dist[u] + w < dist[v]:
            dist[v] = dist[u] + w
            par[v] = u
            x = v
    if x == -1:  # nothing changed -> no negative cycle
        break

if x == -1:
    print("NO")
else:
    # something still improved on the n-th round -> a negative cycle exists.
    # walk back n times to be sure we are standing on the cycle
    for _ in range(n):
        x = par[x]
    cycle = [x]
    v = par[x]
    while v != x:
        cycle.append(v)
        v = par[v]
    cycle.append(x)
    cycle.reverse()  # we walked backwards, so turn it around
    print("YES")
    print(len(cycle))
    print(*[v + 1 for v in cycle])
