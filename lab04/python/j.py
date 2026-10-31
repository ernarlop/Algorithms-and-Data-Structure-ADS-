n, k = map(int, input().split())
a = sorted(map(int, input().split()))  # = in-order обход BST
print(a[k - 1] if k <= n else -1)
