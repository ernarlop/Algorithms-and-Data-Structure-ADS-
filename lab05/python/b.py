import heapq

n = int(input())
# heapq is a min-heap, so we store -weight to get a max-heap
heap = [-x for x in map(int, input().split())]
heapq.heapify(heap)

while len(heap) > 1:  # smash the two heaviest stones
    y = -heapq.heappop(heap)
    x = -heapq.heappop(heap)
    if y != x:
        heapq.heappush(heap, -(y - x))
print(-heap[0] if heap else 0)
