# Merge sort, always O(n log n): split in half, sort both halves, merge them
def merge_sort(a):
    if len(a) <= 1:
        return a
    mid = len(a) // 2
    left = merge_sort(a[:mid])
    right = merge_sort(a[mid:])

    # merge the two sorted halves
    res = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            res.append(left[i])
            i += 1
        else:
            res.append(right[j])
            j += 1
    res += left[i:]   # leftovers of the left half
    res += right[j:]  # leftovers of the right half
    return res


n = int(input())
a = list(map(int, input().split()))
print(*merge_sort(a))
