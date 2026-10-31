from bisect import bisect_left

n = int(input())
a = list(map(int, input().split()))
x = int(input())
i = bisect_left(a, x)  # бинарный поиск: первая позиция, где a[i] >= x
print("Yes" if i < n and a[i] == x else "No")
