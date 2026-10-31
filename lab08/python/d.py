n = int(input())
p = list(map(int, input().split()))

# p[i] - p[i-1] = (s[i] - 97) * 2^i, so we can get every letter back
s = ""
prev = 0
for i in range(n):
    s += chr((p[i] - prev) // (2 ** i) + 97)
    prev = p[i]
print(s)
