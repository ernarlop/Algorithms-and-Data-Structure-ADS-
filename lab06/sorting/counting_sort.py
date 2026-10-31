# Counting sort, O(n + MAX): works only for small numbers (here 0..1000000)
n = int(input())
cnt = [0] * 1000001
for x in map(int, input().split()):
    cnt[x] += 1  # how many times x appears

result = []
for v in range(1000001):
    for _ in range(cnt[v]):
        result.append(v)
print(*result)
