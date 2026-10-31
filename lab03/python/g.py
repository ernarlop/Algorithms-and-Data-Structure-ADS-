n, k = map(int, input().split())
a = list(map(int, input().split()))
lo, hi = 0.0, float(max(a))  # ищем максимальную длину
for _ in range(60):
    x = (lo + hi) / 2
    if sum(v // x for v in a) >= k:  # сколько кусков длины x получится
        lo = x
    else:
        hi = x
print(f"{lo:.9f}")
