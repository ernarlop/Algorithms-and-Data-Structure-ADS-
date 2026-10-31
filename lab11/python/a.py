import sys
input = sys.stdin.readline

n, m = map(int, input().split())
segs = []
for _ in range(m):
    l, r, c = map(int, input().split())
    segs.append((c, l, r))
segs.sort()  # Kruskal: cheapest segments first

# a segment [l, r] joins the whole interval, so only neighbours (i, i+1) matter:
# every pair (i, i+1) is joined by the first (cheapest) segment that covers it.
# nxt[i] = the first i' >= i whose pair (i', i'+1) is not joined yet (DSU-style jumps)
nxt = list(range(n + 2))


def find(i):
    while nxt[i] != i:
        nxt[i] = nxt[nxt[i]]
        i = nxt[i]
    return i


total = 0
for c, l, r in segs:
    i = find(l)
    while i < r:
        total += c       # join i and i+1 with cost c
        nxt[i] = i + 1   # this pair is done, jump over it next time
        i = find(i + 1)
print(total)
