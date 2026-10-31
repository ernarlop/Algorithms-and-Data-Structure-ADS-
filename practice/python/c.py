n = int(input())
a = [0] + list(map(int, input().split()))  # a[1..n], numbered from 1 like in the statement

# Lomuto partition
pivot = a[n]  # 1) the pivot is the last element
i = 0
for j in range(1, n):  # 2) smaller elements go to the front
    if a[j] < pivot:
        i += 1
        a[i], a[j] = a[j], a[i]
a[i + 1], a[n] = a[n], a[i + 1]  # 3) put the pivot right after the smaller ones

print(*a[1:])
