import sys
sys.setrecursionlimit(10000)

inv = 0


# usual merge sort + counting inversions while merging
def merge_sort(a):
    global inv
    if len(a) <= 1:
        return a
    mid = len(a) // 2
    left = merge_sort(a[:mid])
    right = merge_sort(a[mid:])

    res = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            res.append(left[i])
            i += 1
        else:
            inv += len(left) - i  # right[j] is smaller than every element left in "left"
            res.append(right[j])
            j += 1
    res += left[i:]
    res += right[j:]
    return res


n = int(input())
a = list(map(int, input().split()))
merge_sort(a)
print(inv)
