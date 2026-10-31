s = input().strip()

# like brackets: a letter equal to the top of the stack closes it
stack = []
for c in s:
    if stack and stack[-1] == c:
        stack.pop()
    else:
        stack.append(c)
print("YES" if not stack else "NO")
