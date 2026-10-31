n = int(input())
s = input()

# count how many times each letter appears
cnt = {}
for c in s:
    cnt[c] = cnt.get(c, 0) + 1

# Albert's alphabet: vowels first, then consonants
order = "aeioubcdfghjklmnpqrstvwxyz"
result = ""
for c in order:
    result += c * cnt.get(c, 0)
print(result)
