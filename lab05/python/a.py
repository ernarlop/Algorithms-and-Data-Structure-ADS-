import heapq

n = int(input())
heap = list(map(int, input().split()))
heapq.heapify(heap)  # min-heap

cost = 0
while len(heap) > 1:  # merge the two shortest arrays
    a = heapq.heappop(heap)
    b = heapq.heappop(heap)
    cost += a + b
    heapq.heappush(heap, a + b)
print(cost)
