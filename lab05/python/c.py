import heapq

n, x = map(int, input().split())
# max-heap of free seats (stored as negative numbers)
heap = [-a for a in map(int, input().split())]
heapq.heapify(heap)

money = 0
for _ in range(x):  # every fan buys a ticket in the row with the most free seats
    k = -heapq.heappop(heap)
    money += k
    if k > 1:
        heapq.heappush(heap, -(k - 1))
print(money)
