import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
q = int(input())
out = []
for x in map(int, input().split()):
    # lower bound: the first position where a[pos] >= x
    l, r = 0, n  # the answer is in [l, r]; r = n means "no such element"
    while l < r:
        m = (l + r) // 2
        if a[m] >= x:
            r = m      # m fits, but maybe there is one more to the left
        else:
            l = m + 1  # a[m] is too small, the answer is to the right
    out.append(-1 if l == n else l + 1)  # indices start from 1
print("\n".join(map(str, out)))
