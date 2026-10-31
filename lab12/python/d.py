import sys
input = sys.stdin.readline

n = int(input())
x = []
y = []
for _ in range(n):
    a, b = map(int, input().split())
    x.append(a)
    y.append(b)

# like Dijkstra, but the "length" of a path is its biggest step, not the sum
INF = float("inf")
need = [INF] * n  # need[v] = the smallest age that is enough to reach city v
need[0] = 0
used = [False] * n
for _ in range(n):
    u = -1
    for i in range(n):
        if not used[i] and (u == -1 or need[i] < need[u]):
            u = i
    if u == n - 1:
        break
    used[u] = True
    for v in range(n):
        if not used[v]:
            c = max(need[u], abs(x[u] - x[v]) + abs(y[u] - y[v]))
            if c < need[v]:
                need[v] = c
print(need[n - 1])
