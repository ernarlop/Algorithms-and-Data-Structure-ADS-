input(); a = list(dict.fromkeys(map(int, input().split()))); n = len(a)  # без повторов
L = [n] * n; R = [n] * n; st = []  # L[i], R[i] — сыновья i-й вставленной вершины, n — нет сына
for i in sorted(range(n), key=a.__getitem__):  # строим BST: вершины по возрастанию + стек
    j = n
    while st and st[-1] > i: j = st.pop()
    L[i] = j
    if st: R[st[-1]] = i
    st.append(i)
h = [0] * (n + 1); ans = 0
for i in reversed(range(n)):
    h[i] = 1 + max(h[L[i]], h[R[i]])
    ans = max(ans, 1 + h[L[i]] + h[R[i]])
print(ans)
