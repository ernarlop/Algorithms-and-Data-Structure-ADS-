import sys

# read everything at once (a line can be missing when n or m is 0)
data = sys.stdin.read().split()
n, m = int(data[0]), int(data[1])
a = sorted(int(x) for x in data[2:2 + n])
b = sorted(int(x) for x in data[2 + n:2 + n + m])

# two pointers: always move the pointer that shows the smaller number
i = j = 0
common = []
while i < n and j < m:
    if a[i] < b[j]:
        i += 1
    elif a[i] > b[j]:
        j += 1
    else:  # the same number is in both arrays
        common.append(a[i])
        i += 1
        j += 1
print(*common)
