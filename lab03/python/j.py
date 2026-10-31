import sys
input = sys.stdin.readline

n, k = map(int, input().split())
need = []  # сторона квадрата, нужная для каждой овцы
for _ in range(n):
    x1, y1, x2, y2 = map(int, input().split())
    need.append(max(x2, y2))
need.sort()
print(need[k - 1])  # k-я по величине — минимальная сторона для k овец
