n, m = map(int, input().split())
x, y = map(int, input().split())

edges = []
for _ in range(m):
    kind, a, b, c = input().split()
    a, b, c = int(a), int(b), int(c)
    if kind == "big":
        price = x
    elif kind == "small":
        price = y
    else:  # "both": take the cheaper asphalt
        price = min(x, y)
    edges.append((c * price, a, b))

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


# Kruskal: take the cheapest roads that connect new parts
edges.sort()
total = 0
for w, a, b in edges:
    if union(a, b):
        total += w
print(total)
