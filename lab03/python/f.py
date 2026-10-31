n, h = map(int, input().split())
a = list(map(int, input().split()))
lo, hi = 1, max(a)  # ищем минимальное K
while lo < hi:
    k = (lo + hi) // 2
    hours = sum((v + k - 1) // k for v in a)  # деление с округлением вверх
    if hours <= h:
        hi = k
    else:
        lo = k + 1
print(lo)
