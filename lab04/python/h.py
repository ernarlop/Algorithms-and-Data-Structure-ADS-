from itertools import accumulate
input()
print(*accumulate(sorted(map(int, input().split()), reverse=True)))  # = обход BST справа налево
