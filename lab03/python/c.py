import sys
from bisect import bisect_left
from itertools import accumulate
input = sys.stdin.readline

n, m = map(int, input().split())
p = list(accumulate(map(int, input().split())))  # p[i] — строка, где кончается блок i
out = []
for _ in range(m):
    b = int(input())
    out.append(bisect_left(p, b) + 1)  # первый блок, который кончается не раньше b
print("\n".join(map(str, out)))
