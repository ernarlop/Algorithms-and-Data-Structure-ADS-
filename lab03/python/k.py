import sys
input = sys.stdin.readline

t = int(input())
q = list(map(int, input().split()))
n, m = map(int, input().split())
pos = {}  # значение -> "строка столбец"
for i in range(n):
    for j, x in enumerate(map(int, input().split())):
        pos[x] = f"{i} {j}"
print("\n".join(pos.get(v, "-1") for v in q))
