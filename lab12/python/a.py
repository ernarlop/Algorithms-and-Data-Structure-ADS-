import sys
input = sys.stdin.readline

n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
order = [int(x) - 1 for x in input().split()]

# renumber the vertices: the k-th added vertex gets number k
d = [[a[order[i]][order[j]] for j in range(n)] for i in range(n)]

out = []
for k in range(n):
    # Floyd-Warshall step: now paths may also go through vertex k
    dk = d[k]
    for i in range(n):
        dik = d[i][k]
        # d[i][j] = min(d[i][j], d[i][k] + d[k][j]) for every j
        d[i] = [x if x < dik + y else dik + y for x, y in zip(d[i], dk)]
    # the longest shortest path among the added vertices 0..k
    out.append(max(max(d[i][:k + 1]) for i in range(k + 1)))
print("\n".join(map(str, out)))
