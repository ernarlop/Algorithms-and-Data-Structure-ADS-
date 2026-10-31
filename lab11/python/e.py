import sys
input = sys.stdin.readline

n, m = map(int, input().split())
adj = [[] for _ in range(n + 1)]
for _ in range(m):
    v, u = map(int, input().split())
    adj[v].append(u)
    adj[u].append(v)

parent = list(range(n + 1))


def find(x):
    # DSU: the leader of the set that contains x (with path compression)
    while parent[x] != x:
        parent[x] = parent[parent[x]]
        x = parent[x]
    return x


def union(a, b):
    # join the sets of a and b; False if they were already together
    a = find(a)
    b = find(b)
    if a == b:
        return False
    parent[a] = b
    return True


# go backwards: instead of deleting 1, 2, ..., n we add n, n-1, ..., 1 and use DSU
ans = [0] * (n + 1)  # ans[i] = number of components after deleting vertices 1..i
comps = 0
for v in range(n, 0, -1):
    ans[v] = comps        # vertices v+1..n are in the graph right now
    comps += 1            # add v as a new component
    for u in adj[v]:
        if u > v and union(u, v):
            comps -= 1    # two components became one
print("\n".join(str(ans[i]) for i in range(1, n + 1)))
