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


def kmp(pattern, text):
    # KMP: start positions (from 0) of all occurrences of pattern in text
    m = len(pattern)
    pi = prefix_function(pattern + "#" + text)
    res = []
    for i in range(len(pi)):
        if pi[i] == m:
            res.append(i - 2 * m)
    return res


a = input().strip()
b = input().strip()

# every cyclic shift of b is a substring of b + b
occ = kmp(a, b + b)
print(occ[0] if occ else -1)
