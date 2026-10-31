import sys
import heapq
input = sys.stdin.readline

n, m = map(int, input().split())
adj = [[] for _ in range(n + 1)]
indeg = [0] * (n + 1)
for _ in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)
    indeg[b] += 1

# topological sort (Kahn): always take a quest with no unfinished requirements,
# the heap gives the smallest such quest first
heap = [v for v in range(1, n + 1) if indeg[v] == 0]
heapq.heapify(heap)
order = []
while heap:
    u = heapq.heappop(heap)
    order.append(u)
    for v in adj[u]:
        indeg[v] -= 1
        if indeg[v] == 0:
            heapq.heappush(heap, v)

if len(order) == n:
    print("Possible")
    print(*order)
else:  # some quests are stuck in a cycle
    print("Impossible")
