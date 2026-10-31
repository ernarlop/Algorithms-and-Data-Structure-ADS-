n = int(input()); a = list(map(int, input().split()))
L = [n] * n; R = [n] * n; st = []  # L[i], R[i] — сыновья i-й вставленной вершины, n — нет сына
for i in sorted(range(n), key=a.__getitem__):  # строим BST: вершины по возрастанию + стек
    j = n
    while st and st[-1] > i: j = st.pop()
    L[i] = j
    if st: R[st[-1]] = i
    st.append(i)
s = [0] * (n + 1)
for i in reversed(range(n)): s[i] = 1 + s[L[i]] + s[R[i]]  # сыновья вставлены позже отца
print(s[a.index(int(input()))])
