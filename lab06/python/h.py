n = int(input())
letters = input().split()
k = input().strip()

# the letters are sorted, so the first letter bigger than k is the answer
answer = letters[0]  # if nothing is bigger -> wrap around to the first letter
for c in letters:
    if c > k:
        answer = c
        break
print(answer)
