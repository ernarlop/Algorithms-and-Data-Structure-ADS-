n = int(input()); ch = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    x, y, z = map(int, input().split()); ch[x].append(y)
lv, ans = [1], 0
while lv:  # идём по уровням
    ans = max(ans, len(lv))
    lv = [u for v in lv for u in ch[v]]
print(ans)
