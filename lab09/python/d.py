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


p = input().strip().lower()
n = int(input())
names = [input().strip() for _ in range(n)]

# overlap = the longest prefix of the name that is also a suffix of p
overlap = []
for name in names:
    overlap.append(prefix_function(name.lower() + "#" + p)[-1])

best = max(overlap)
good = [names[i] for i in range(n) if overlap[i] == best]
print(len(good))
for name in good:
    print(name)
