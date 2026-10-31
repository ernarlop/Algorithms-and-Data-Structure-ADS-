import sys

point = {"A+": 4, "A": 3.75, "B+": 3.5, "B": 3, "C+": 2.5, "C": 2, "D+": 1.5, "D": 1, "F": 0}

data = sys.stdin.read().split()  # all words of the input, one by one
n = int(data[0])
pos = 1
students = []
for _ in range(n):
    last, first, m = data[pos], data[pos + 1], int(data[pos + 2])
    pos += 3
    total = 0
    credits = 0
    for _ in range(m):
        mark, c = data[pos], int(data[pos + 1])
        pos += 2
        total += point[mark] * c
        credits += c
    students.append((total / credits, last, first))

# tuples are compared by GPA, then last name, then first name
students.sort()

out = []
for gpa, last, first in students:
    out.append(f"{last} {first} {gpa:.3f}")
print("\n".join(out))
