import sys
input = sys.stdin.readline

def prefix_function(s):
    # pi[i] = length of the longest proper prefix of s[0..i] that is also its suffix
    n = len(s)
    pi = [0] * n
    for i in range(1, n):
        j = pi[i - 1]
        while j > 0 and s[i] != s[j]:
            j = pi[j - 1]
        if s[i] == s[j]:
            j += 1
        pi[i] = j
    return pi


t = int(input())
out = []
for _ in range(t):
    s, k = input().split()
    k = int(k)
    n = len(s)
    period = n - prefix_function(s)[-1]  # each next copy of s overlaps the previous one
    out.append(n + (k - 1) * period)
print("\n".join(map(str, out)))
