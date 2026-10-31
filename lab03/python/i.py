n, k = map(int, input().split())
a = list(map(int, input().split()))
lo, hi = max(a), sum(a)  # ответ между самым большим домом и суммой всех


def blocks(x):  # жадно набиваем блоки, пока сумма <= x
    cnt, cur = 1, 0
    for v in a:
        if cur + v > x:
            cnt += 1
            cur = 0
        cur += v
    return cnt


while lo < hi:
    x = (lo + hi) // 2
    if blocks(x) <= k:
        hi = x
    else:
        lo = x + 1
print(lo)
