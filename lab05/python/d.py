import sys
import heapq

data = sys.stdin.buffer.read().split()
n, m = int(data[0]), int(data[1])
heap = list(map(int, data[2:2 + n]))
heapq.heapify(heap)  # min-heap

ops = 0
while len(heap) > 1 and heap[0] < m:  # mix the two weakest mixtures
    a = heapq.heappop(heap)
    b = heapq.heappop(heap)
    heapq.heappush(heap, a + 2 * b)
    ops += 1
print(-1 if heap[0] < m else ops)
