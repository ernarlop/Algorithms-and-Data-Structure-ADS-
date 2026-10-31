import sys
input = sys.stdin.readline

MOD = (1 << 61) - 1  # a huge prime modulus: two different strings practically never get the same hash
BASE = 131


def prefix_hashes(s):
    # h[i] = hash of the first i characters, s[0:i]
    h = [0] * (len(s) + 1)
    for i in range(len(s)):
        h[i + 1] = (h[i] * BASE + ord(s[i])) % MOD
    return h


s1 = input().strip()
s2 = input().strip()
t = input().strip()
m = len(t)

h1 = prefix_hashes(s1)
h2 = prefix_hashes(s2)
ht = prefix_hashes(t)[m]
p = pow(BASE, m, MOD)  # BASE^m, used to cut a window of length m out of the prefix hashes

count = 0
for i in range(min(len(s1), len(s2)) - m + 1):
    # hash of s[i:i+m] = h[i+m] - h[i] * BASE^m   (Rabin-Karp)
    if (h1[i + m] - h1[i] * p) % MOD == ht and (h2[i + m] - h2[i] * p) % MOD == ht:
        count += 1
print(count)
