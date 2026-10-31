import sys
input = sys.stdin.readline

n, q = map(int, input().split())
a = [input().split() for _ in range(n)]  # adjacency matrix, kept as "0" / "1"

out = []
for _ in range(q):
    x, y, z = map(int, input().split())
    x -= 1
    y -= 1
    z -= 1
    # all three pairs must be allowed
    if a[x][y] == "1" and a[y][z] == "1" and a[x][z] == "1":
        out.append("YES")
    else:
        out.append("NO")
print("\n".join(out))
