from collections import deque

n, m = map(int, input().split())
grid = [input().strip() for _ in range(n)]
seen = [[False] * m for _ in range(n)]

islands = 0
for i in range(n):
    for j in range(m):
        if grid[i][j] == "1" and not seen[i][j]:
            # a new island: BFS marks all of its land cells
            islands += 1
            seen[i][j] = True
            q = deque([(i, j)])
            while q:
                a, b = q.popleft()
                for x, y in ((a + 1, b), (a - 1, b), (a, b + 1), (a, b - 1)):
                    if 0 <= x < n and 0 <= y < m and grid[x][y] == "1" and not seen[x][y]:
                        seen[x][y] = True
                        q.append((x, y))
print(islands)
