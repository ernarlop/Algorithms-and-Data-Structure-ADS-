import sys

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


s = sys.stdin.readline().strip()
n = len(s)
pi = prefix_function(s)

# a + c == b + c  means  a == b, so s = a + a + c
# s[:L] == s[L:2L]  exactly when the smallest period of s[:2L] divides L
count = 0
for L in range(1, (n - 1) // 2 + 1):
    period = 2 * L - pi[2 * L - 1]
    if L % period == 0:
        count += 1
print(count)
