n = int(input()); a = list(map(int, input().split()))
L = [n] * n; R = [n] * n; st = []  # L[i], R[i] — сыновья i-й вставленной вершины, n — нет сына
for i in sorted(range(n), key=a.__getitem__):  # строим BST: вершины по возрастанию + стек
    j = n
    while st and st[-1] > i: j = st.pop()
    L[i] = j
    if st: R[st[-1]] = i
    st.append(i)
out, q = [], [a.index(int(input()))]
while q:  # pre-order через стек: вершина, левое, правое
    v = q.pop()
    if v < n: out.append(a[v]); q += [R[v], L[v]]
print(*out)
