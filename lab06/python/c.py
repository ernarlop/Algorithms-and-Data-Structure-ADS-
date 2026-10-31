n = int(input())
a = sorted(map(int, input().split()))

# 1) find the smallest difference between two neighbours
best = a[1] - a[0]
for i in range(1, n):
    best = min(best, a[i] - a[i - 1])

# 2) collect every neighbour pair with that difference
ans = []
for i in range(1, n):
    if a[i] - a[i - 1] == best:
        ans.append(a[i - 1])
        ans.append(a[i])
print(*ans)
