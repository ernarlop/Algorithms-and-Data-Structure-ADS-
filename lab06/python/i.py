s = input().strip()

# counting sort: count every letter...
cnt = [0] * 26
for c in s:
    cnt[ord(c) - ord('a')] += 1

# ...then print them from 'a' to 'z'
result = ""
for i in range(26):
    result += chr(ord('a') + i) * cnt[i]
print(result)
