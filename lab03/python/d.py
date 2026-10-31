import sys
from bisect import bisect_right
from itertools import accumulate
input = sys.stdin.readline

n = int(input())
a = sorted(map(int, input().split()))
s = [0] + list(accumulate(a))  # s[i] — сумма первых i сил
out = []
for _ in range(int(input())):
    k = bisect_right(a, int(input()))  # сколько сил <= p
    out.append(f"{k} {s[k]}")
print("\n".join(out))
