import sys
from collections import deque
input = sys.stdin.readline
sys.setrecursionlimit(10000)

n, m = map(int, input().split())
adj = [[] for _ in range(n + 1)]
indeg = [0] * (n + 1)
for _ in range(m):
    x, y = map(int, input().split())
    adj[x].append(y)
    indeg[y] += 1

# 1) DFS finds any cycle (color: 0 = new, 1 = in the current DFS path, 2 = finished)
color = [0] * (n + 1)
parent = [0] * (n + 1)
cycle = []  # edges of the found cycle


def dfs(u):
    color[u] = 1
    for v in adj[u]:
        if cycle:
            return
        if color[v] == 0:
            parent[v] = u
            dfs(v)
        elif color[v] == 1:  # edge back into the current path -> a cycle v -> ... -> u -> v
            cycle.append((u, v))
            x = u
            while x != v:
                cycle.append((parent[x], x))
                x = parent[x]
            return
    color[u] = 2


for s in range(1, n + 1):
    if color[s] == 0 and not cycle:
        dfs(s)


def acyclic_without(bu, bv):
    # Kahn's topological sort that ignores the edge bu -> bv
    deg = indeg[:]
    deg[bv] -= 1
    q = deque(v for v in range(1, n + 1) if deg[v] == 0)
    done = 0
    while q:
        u = q.popleft()
        done += 1
        for v in adj[u]:
            if u == bu and v == bv:
                continue
            deg[v] -= 1
            if deg[v] == 0:
                q.append(v)
    return done == n  # every vertex was taken -> no cycle left


# 2) the edge we delete must be on this cycle, so try each of them
if not cycle:
    print("YES")
elif any(acyclic_without(u, v) for u, v in cycle):
    print("YES")
else:
    print("NO")
