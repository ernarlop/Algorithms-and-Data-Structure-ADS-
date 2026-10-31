import sys
import heapq

lines = sys.stdin.read().split("\n")
t = int(lines[0])
out = []
for i in range(1, t + 1):
    words = lines[i].split()
    # min-heap of (length, position): shorter words first;
    # equal length -> the one that was earlier (so the order is stable)
    heap = [(len(w), pos) for pos, w in enumerate(words)]
    heapq.heapify(heap)
    res = []
    while heap:
        length, pos = heapq.heappop(heap)
        res.append(words[pos])
    out.append(" ".join(res))
print("\n".join(out))
