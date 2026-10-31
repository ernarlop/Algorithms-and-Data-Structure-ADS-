import sys

MOD = (1 << 61) - 1
BASE = 131

s = sys.stdin.readline().strip()  # the string may be empty
n = len(s)

# h[i] = hash of the first i characters, s[0:i]
h = [0] * (n + 1)
for i in range(n):
    h[i + 1] = (h[i] * BASE + ord(s[i])) % MOD

total = 0
for L in range(1, n + 1):
    # put the hash of every substring of length L into a set: the set keeps only different ones
    pw = pow(BASE, L, MOD)
    seen = set()
    for i in range(n - L + 1):
        seen.add((h[i + L] - h[i] * pw) % MOD)
    total += len(seen)
print(total)
