# "DD-MM-YYYY" -> "YYYYMMDD", then simple string comparison sorts by date
def key(s):
    return s[6:10] + s[3:5] + s[0:2]


n = int(input())
dates = []
for _ in range(n):
    dates.append(input().strip())

dates.sort(key=key)

for d in dates:
    print(d)
