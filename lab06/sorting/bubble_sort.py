# Bubble sort, O(n^2): swap wrong neighbours, big numbers "bubble up" to the end
n = int(input())
a = list(map(int, input().split()))

for i in range(n - 1):
    swapped = False
    for j in range(n - i - 1):
        if a[j] > a[j + 1]:
            a[j], a[j + 1] = a[j + 1], a[j]
            swapped = True
    if not swapped:  # no swaps -> already sorted
        break

print(*a)
