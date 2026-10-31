n, k = map(int, input().split())
a = list(map(int, input().split()))
# два указателя: окно [l, r], все числа неотрицательные
ans, l, s = n, 0, 0
for r in range(n):
    s += a[r]
    while l <= r and s >= k:
        ans = min(ans, r - l + 1)
        s -= a[l]
        l += 1
print(ans)
