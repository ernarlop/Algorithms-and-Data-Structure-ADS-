from collections import deque

n = int(input())
a = deque(map(int, input().split()))
m = int(input())
b = deque(map(int, input().split()))

# merge: always take the smaller of the two front elements
res = []
while a and b:
    if a[0] <= b[0]:
        res.append(a.popleft())
    else:
        res.append(b.popleft())
# the tail: whatever is left in one of the queues
res.extend(a)
res.extend(b)
print(*res)
