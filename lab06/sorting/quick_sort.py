# Quick sort, O(n log n) on average:
# take the middle element p, move smaller ones left and bigger ones right, repeat on both parts
def quick_sort(a, l, r):
    p = a[(l + r) // 2]
    i, j = l, r
    while i <= j:
        while a[i] < p:
            i += 1
        while a[j] > p:
            j -= 1
        if i <= j:
            a[i], a[j] = a[j], a[i]
            i += 1
            j -= 1
    if l < j:
        quick_sort(a, l, j)
    if i < r:
        quick_sort(a, i, r)


n = int(input())
a = list(map(int, input().split()))
if n > 0:
    quick_sort(a, 0, n - 1)
print(*a)
