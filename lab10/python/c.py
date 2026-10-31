from collections import deque

a, b = map(int, input().split())
LIMIT = 2 * max(a, b)  # going higher than this is never useful

# BFS over numbers, par[x] = the number we came to x from
par = [-1] * (LIMIT + 1)
par[a] = a
q = deque([a])
while q:
    x = q.popleft()
    if x == b:
        break
    for y in (x * 2, x - 1):
        if 1 <= y <= LIMIT and par[y] == -1:
            par[y] = x
            q.append(y)

# go back from b to a to restore the numbers
path = []
x = b
while x != a:
    path.append(x)
    x = par[x]
path.reverse()

print(len(path))
print(*path)
