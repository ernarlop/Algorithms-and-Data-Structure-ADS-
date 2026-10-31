import heapq

n, m = map(int, input().split())
# min-heap of (-sum, row): the biggest sum comes out first,
# equal sums -> rows are compared element by element (lexicographically)
heap = []
for _ in range(n):
    row = list(map(int, input().split()))
    heapq.heappush(heap, (-sum(row), row))

while heap:
    s, row = heapq.heappop(heap)
    print(*row)
