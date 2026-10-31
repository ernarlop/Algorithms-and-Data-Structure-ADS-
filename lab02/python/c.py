import sys
input = sys.stdin.readline

n = int(input())
names = []
for _ in range(n):
    s = input().strip()
    # copies always stand next to each other, so compare with the last kept name
    if not names or names[-1] != s:
        names.append(s)

print(len(names))
print("\n".join(names))
