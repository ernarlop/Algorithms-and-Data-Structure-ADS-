import sys
from bisect import bisect_left, bisect_right
input = sys.stdin.readline

n, q = map(int, input().split())
a = sorted(map(int, input().split()))


def cnt(l, r):  # сколько элементов в отрезке [l, r]
    if l > r:
        return 0
    return bisect_right(a, r) - bisect_left(a, l)


out = []
for _ in range(q):
    l1, r1, l2, r2 = map(int, input().split())
    # |A ∪ B| = |A| + |B| - |A ∩ B|
    out.append(cnt(l1, r1) + cnt(l2, r2) - cnt(max(l1, l2), min(r1, r2)))
print("\n".join(map(str, out)))
