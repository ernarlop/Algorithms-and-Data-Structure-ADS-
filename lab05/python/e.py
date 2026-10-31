import sys
import heapq
input = sys.stdin.readline

q, k = map(int, input().split())
heap = []  # the k largest numbers, the smallest of them is on top
total = 0
out = []
for _ in range(q):
    w = input().split()
    if w[0] == "print":
        out.append(total)
    else:
        x = int(w[1])
        heapq.heappush(heap, x)
        total += x
        if len(heap) > k:  # too many -> throw away the smallest
            total -= heapq.heappop(heap)
print("\n".join(map(str, out)))
