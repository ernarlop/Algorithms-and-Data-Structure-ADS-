n, m = map(int, input().split())
a = []
for _ in range(n):
    a.append(list(map(int, input().split())))

for j in range(m):
    # copy column j, sort it from big to small, put it back
    col = []
    for i in range(n):
        col.append(a[i][j])
    col.sort(reverse=True)
    for i in range(n):
        a[i][j] = col[i]

for row in a:
    print(*row)
