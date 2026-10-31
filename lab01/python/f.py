# type the string using a stack: '#' removes the last typed letter
def type_text(s):
    stack = []
    for c in s:
        if c == "#":
            if stack:
                stack.pop()
        else:
            stack.append(c)
    return stack


a = input().strip()
b = input().strip()
print("Yes" if type_text(a) == type_text(b) else "No")
