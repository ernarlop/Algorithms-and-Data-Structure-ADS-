n = int(input())
origin = {}  # current nickname -> original nickname
for _ in range(n):
    old, new = input().split()
    original = old
    if old in origin:  # old was already a renamed nickname
        original = origin[old]
        del origin[old]
    origin[new] = original

# flip it: (original, current), sorted by original
pairs = []
for cur in origin:
    pairs.append((origin[cur], cur))
pairs.sort()

print(len(pairs))
for orig, cur in pairs:
    print(orig, cur)
