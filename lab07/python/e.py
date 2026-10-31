from collections import deque

n = int(input())
d = deque(map(int, input().split()))

# the biggest square is always at one of the two ends of the array,
# so take it from the front or the back and fill the answer from the end
res = [0] * n
for k in range(n - 1, -1, -1):
    if abs(d[0]) > abs(d[-1]):
        x = d.popleft()
    else:
        x = d.pop()
    res[k] = x * x
print(*res)
