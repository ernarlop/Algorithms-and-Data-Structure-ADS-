n = int(input())
a = list(map(int, input().split()))

# the stack keeps candidates for "nearest smaller on the left"
stack = []
ans = []
for x in a:
    while stack and stack[-1] >= x:  # not smaller -> useless now
        stack.pop()
    ans.append(stack[-1] if stack else -1)
    stack.append(x)
print(*ans)
