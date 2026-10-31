import sys
input = sys.stdin.readline

MOD = (1 << 61) - 1
BASE = 131

s = input().strip()
n = len(s)
q = int(input())
queries = [tuple(map(int, input().split())) for _ in range(q)]

# h[i] = hash of the first i characters, s[0:i]
h = [0] * (n + 1)
for i in range(n):
    h[i + 1] = (h[i] * BASE + ord(s[i])) % MOD

# group the queries by the length of their substring
by_len = {}
for idx in range(q):
    l, r = queries[idx]
    by_len.setdefault(r - l + 1, []).append(idx)

ans = [0] * q
for L, idxs in by_len.items():
    # count how many times every window hash of length L appears
    pw = pow(BASE, L, MOD)
    cnt = {}
    for i in range(n - L + 1):
        x = (h[i + L] - h[i] * pw) % MOD
        cnt[x] = cnt.get(x, 0) + 1
    for idx in idxs:
        l, r = queries[idx]
        ans[idx] = cnt[(h[r] - h[l - 1] * pw) % MOD]
print("\n".join(map(str, ans)))
